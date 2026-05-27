#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "utils.h"

// ── INSERT ──────────────────────────────────────────
BSTNode* bst_insert(BSTNode *root, Student s) {
    if(!root) {
        BSTNode *node = malloc(sizeof(BSTNode));
        node->data = s;
        node->left = node->right = NULL;
        return node;
    }
    int cmp=strcmp(s.mssv, root->data.mssv);
    if (cmp < 0) root->left = bst_insert(root->left, s);
    else if (cmp > 0) root->right = bst_insert(root->right, s);
    else printf("MSSV %s da ton tai!\n", s.mssv);
    return root;
}

// ── SEARCH ──────────────────────────────────────────
BSTNode* bst_search(BSTNode *root, const char *mssv) {
    if (!root) return NULL;
    int cmp = strcmp(mssv, root->data.mssv);
    if (cmp == 0) return root;
    else if (cmp < 0) return bst_search(root->left, mssv);
    else return bst_search(root->right, mssv);
}

// ── INORDER (in danh sách đã sort) ──────────────────
void bst_inorder(BSTNode *root) {
    if (!root) return ;
    bst_inorder(root->left);
    student_print(&root->data);
    bst_inorder(root->right);
}
static void bst_print_table_row(BSTNode *root) {
    if (!root) return;
    bst_print_table_row(root->left);
    printf("| %-10s | %-20s | %-16s | %02d/%02d/%04d | %.2f |\n",
        root->data.mssv, root->data.name, root->data.major,
        root->data.dob.day, root->data.dob.month, root->data.dob.year,
        root->data.gpa);
    bst_print_table_row(root->right);
}
void bst_inorder_table(BSTNode *root) {
    printf("+------------+----------------------+------------------+------------+------+\n");
    printf("| %-10s | %-20s | %-16s | %-10s | %-4s |\n",
        "MSSV", "Ten", "Nganh", "Ngay sinh", "GPA");
    printf("+------------+----------------------+------------------+------------+------+\n");
    if (!root)
        printf("| %-73s |\n", "Danh sach trong!");
    else
        bst_print_table_row(root);
    printf("+------------+----------------------+------------------+------------+------+\n");
}

// ── FREE (giải phóng bộ nhớ) ────────────────────────
void bst_free(BSTNode *root) {
    if (!root) return;
    bst_free(root->left);
    bst_free(root->right);
    free(root);
}

// ── DELETE ──────────────────────────────────────────
BSTNode* bst_delete(BSTNode *root, const char *mssv) {
    if (!root) return NULL;
    int cmp = strcmp(mssv, root->data.mssv);
    if (cmp < 0) root->left = bst_delete(root->left, mssv);
    else if (cmp > 0) root->right = bst_delete(root->right, mssv);
    else {
        if (!root->left) {
            BSTNode *temp = root->right;
            free(root);
            return temp;
        } else if (!root->right) {
            BSTNode *temp = root->left;
            free(root);
            return temp;
        } else {
            BSTNode *temp = root->right;
            while(temp->left) temp = temp->left;
            root->data = temp->data;
            root->right = bst_delete(root->right,temp->data.mssv);
        }
    }
    return root;
}

// ── UPDATE ──────────────────────────────────────────
void bst_update(BSTNode *root, const char *mssv) {
    BSTNode *node = bst_search(root, mssv);
    if (!node) {
        printf("Khong tim thay MSSV %s\n", mssv);
        return;
    }
    nhap_chuoi("Nhap ten moi: ", node->data.name, sizeof(node->data.name) - 1);
    nhap_chuoi("Nhap nganh moi: ", node->data.major, sizeof(node->data.major) - 1);
    do {
        node->data.dob.day = nhap_so_nguyen("Ngay sinh - Ngay: ", 1, 31);
        node->data.dob.month = nhap_so_nguyen("Ngay sinh - Thang: ", 1, 12);
        node->data.dob.year = nhap_so_nguyen("Ngay sinh - Nam: ", 1900, 2100);
    } while(node->data.dob.day > ngayTrongThang(node->data.dob.month, node->data.dob.year));
    node->data.gpa = nhap_so_thuc("Nhap GPA moi: ", 0.0, 4.0);
}

void bst_search_by_name(BSTNode *root, const char *name) {
    if (!root) return;
    bst_search_by_name(root->left, name);
    if (strstr(root->data.name, name)) student_print(&root->data);
    bst_search_by_name(root->right, name);
}

static void thong_ke_recursive(BSTNode *root, int *total, float *sum, int *gioi, int *kha, int *tb, int *yeu) {
    if (!root) return;
    thong_ke_recursive(root->left, total, sum, gioi, kha, tb, yeu);
    (*total)++;
    *sum += root->data.gpa;
    int gpa10 = (int)(root->data.gpa * 10 + 0.5f);
    if (gpa10 >= 36) (*gioi)++;
    else if (gpa10 >= 32) (*kha)++;
    else if (gpa10 >= 20) (*tb)++;
    else (*yeu)++;
    thong_ke_recursive(root->right, total, sum, gioi, kha, tb, yeu);
}
void bst_thong_ke(BSTNode *root) {
    int total = 0, gioi = 0, kha = 0, tb = 0, yeu = 0;
    float sum = 0.0;
    thong_ke_recursive(root, &total, &sum, &gioi, &kha, &tb, &yeu);
    printf("Tong so sinh vien : %d\n", total);
    printf("GPA trung binh    : %.2f\n", total > 0 ? sum / total : 0.0);
    printf("Gioi (>=3.6)      : %d\n", gioi);
    printf("Kha  (>=3.2)      : %d\n", kha);
    printf("TB   (>=2.0)      : %d\n", tb);
    printf("Yeu  (<2.0)       : %d\n", yeu);
}

static void to_array_recursive(BSTNode *root, Student *arr, int *index) {
    if (!root) return;
    to_array_recursive(root->left, arr, index);
    if (*index < 1000) arr[(*index)++] = root->data;
    to_array_recursive(root->right, arr, index);
}
int bst_to_array(BSTNode *root, Student *arr, int max) {
    int index = 0;
    to_array_recursive(root, arr, &index);
    return index < max ? index : max;
}

int cmp_by_gpa(const void *a, const void *b) {
    Student *sa = (Student *)a;
    Student *sb = (Student *)b;
    if (sa->gpa > sb->gpa) return 1;
    else if (sa->gpa < sb->gpa) return -1;
    else return 0;
}
int cmp_by_name(const void *a, const void *b) {
    Student *sa = (Student *)a;
    Student *sb = (Student *)b;
    return strcmp(sa->name, sb->name);
}
int cmp_by_major(const void *a, const void *b) {
    Student *sa = (Student *)a;
    Student *sb = (Student *)b;
    return strcmp(sa->major, sb->major);
}

void bst_sort_and_print(BSTNode *root, int (*cmp)(const void*, const void*)) {
    Student arr[1000];
    int n = bst_to_array(root, arr, 1000);
    qsort(arr, n, sizeof(Student), cmp);
    printf("+------------+----------------------+------------------+------------+------+\n");
    printf("| %-10s | %-20s | %-16s | %-10s | %-4s |\n",
        "MSSV", "Ten", "Nganh", "Ngay sinh", "GPA");
    printf("+------------+----------------------+------------------+------------+------+\n");
    for (int i = 0; i < n; i++) {
        printf("| %-10s | %-20s | %-16s | %02d/%02d/%04d | %.2f |\n", arr[i].mssv, arr[i].name,
             arr[i].major, arr[i].dob.day, arr[i].dob.month, arr[i].dob.year, arr[i].gpa);
    }
    printf("+------------+----------------------+------------------+------------+------+\n");
}