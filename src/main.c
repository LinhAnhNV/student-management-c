#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"
#include "utils.h"

BSTNode *root = NULL;

void input_student(Student *s) {
    do {
        nhap_chuoi("MSSV   : ", s->mssv, sizeof(s->mssv) - 1);
        if(bst_search(root, s->mssv) != NULL) printf("MSSV %s da ton tai! Vui long nhap lai.\n", s->mssv);
    } while(bst_search(root, s->mssv) != NULL);
    nhap_chuoi("Ten    : ", s->name, sizeof(s->name) - 1);
    nhap_chuoi("Nganh  : ", s->major, sizeof(s->major) - 1);
    do {
        s->dob.day = nhap_so_nguyen("Ngay sinh - Ngay: ", 1, 31);
        s->dob.month = nhap_so_nguyen("Ngay sinh - Thang: ", 1, 12);
        s->dob.year = nhap_so_nguyen("Ngay sinh - Nam: ", 1900, 2100);
        if(s->dob.day > ngayTrongThang(s->dob.month, s->dob.year)) {
            printf("Ngay khong hop le cho thang %d nam %d. Vui long nhap lai.\n", s->dob.month, s->dob.year);
        }
    } while(s->dob.day > ngayTrongThang(s->dob.month, s->dob.year));
    s->gk  = nhap_so_thuc("Diem GK (0-10): ", 0.0, 10.0);
    s->tl  = nhap_so_thuc("Diem TL (0-10): ", 0.0, 10.0);
    s->ck  = nhap_so_thuc("Diem CK (0-10): ", 0.0, 10.0);
    s->gpa = tinhGPA(s->gk, s->tl, s->ck);}

void menu() {
    printf("\n|=======================================|");
    printf("\n|        STUDENT MANAGEMENT v1.0        |");
    printf("\n|=======================================|");
    printf("\n| 1. Them mot sinh vien                 |");
    printf("\n| 2. Tim thong tin sinh vien theo MSSV  |");
    printf("\n| 3. Xoa mot sinh vien                  |");
    printf("\n| 4. Xuat danh sach (da sort theo MSSV) |");
    printf("\n| 5. Sua thong tin sinh vien            |");
    printf("\n| 6. Tim thong tin sinh vien theo ten   |");
    printf("\n| 7. Thong ke GPA                       |");
    printf("\n| 8. Sort theo GPA, ten, nganh          |");
    printf("\n| 9. Xuat bao cao                       |");
    printf("\n| 0. Luu va thoat                       |");
    printf("\n|=======================================|");
}

int main() {
    bst_load(&root, "data.csv");
    int choice;
    do {
        menu();
        choice = nhap_so_nguyen("\nLua chon: ", 0, 9);
        switch(choice) {
            case 1: {
                Student s;
                input_student(&s);
                root = bst_insert(root, s);
                printf("Da them!\n");
                break;
            }
            case 2: {
                char mssv[12];
                nhap_chuoi("Nhap MSSV: ", mssv, sizeof(mssv) - 1);
                BSTNode *found = bst_search(root, mssv);
                if (found) student_print(&found->data);
                else printf("Khong tim thay!\n");
                break;
            }
            case 3: {
                char mssv[12];
                nhap_chuoi("Nhap MSSV can xoa: ", mssv, sizeof(mssv) - 1);
                BSTNode *found = bst_search(root, mssv);
                if (!found) {
                    printf("Khong tim thay MSSV %s\n", mssv);
                    break;
                }
                student_print(&found->data);
                printf("Ban co chac muon xoa? (y/n): ");
                char c;
                scanf(" %c", &c);
                if (c == 'y' || c == 'Y') {
                    root = bst_delete(root, mssv);
                    printf("Da xoa!\n");
                } else printf("Huy xoa!\n");
                break;
            }
            case 4: {
                if (!root) printf("Danh sach trong!\n");
                else bst_inorder_table(root);
                break;
            }
            case 5: {
                char mssv[12];
                nhap_chuoi("Nhap MSSV can sua: ", mssv, sizeof(mssv) - 1);
                bst_update(root, mssv);
                break;
            }
            case 6: {
                char name[50];
                nhap_chuoi("Nhap ten can tim: ", name, sizeof(name) - 1);
                bst_search_by_name(root, name);
                break;
            }
            case 7: {
                bst_thong_ke(root);
                break;
            }
            case 8: {
                printf("Sort theo:\n 1. GPA\t 2. Ten\t 3. Nganh\n");
                int opt = nhap_so_nguyen("Lua chon: ", 1, 3);
                if (opt == 1) bst_sort_and_print(root, cmp_by_gpa);
                else if (opt == 2) bst_sort_and_print(root, cmp_by_name);
                else bst_sort_and_print(root, cmp_by_major);
                break;
            }
            case 9:{
                bst_export_report(root, "report.csv");
                printf("Da xuat ra report.csv!\n");
                break;
            }
            case 0:{
                bst_save(root, "data.csv");
                bst_save(root, "data_backup.csv");
                bst_free(root);
                printf("Tam biet!\n");
                break;
            }
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choice != 0);
    return 0;
}