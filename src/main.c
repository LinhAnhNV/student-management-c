#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

BSTNode *root = NULL;

void input_student(Student *s) {
    printf("MSSV   : "); scanf("%s", s->mssv);
    printf("Ten    : "); scanf(" %[^\n]", s->name);
    printf("Nganh  : "); scanf(" %[^\n]", s->major);
    printf("GPA    : "); scanf("%f", &s->gpa);
}

void menu() {
    printf("\n|==========================|");
    printf("\n|  STUDENT MANAGEMENT v1.0 |");
    printf("\n|==========================|");
    printf("\n| 1. Them sinh vien        |");
    printf("\n| 2. Tim theo MSSV         |");
    printf("\n| 3. Xoa sinh vien         |");
    printf("\n| 4. Danh sach (da sort)   |");
    printf("\n| 0. Thoat                 |");
    printf("\n|==========================|");
    printf("\n> ");
}

int main() {
    int choice;
    do {
        menu();
        scanf("%d", &choice);
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
                printf("Nhap MSSV: "); scanf("%s", mssv);
                BSTNode *found = bst_search(root, mssv);
                if (found) student_print(&found->data);
                else printf("Khong tim thay!\n");
                break;
            }
            case 3: {
                char mssv[12];
                printf("Nhap MSSV can xoa: "); scanf("%s", mssv);
                root = bst_delete(root, mssv);
                printf("Da xoa!\n");
                break;
            }
            case 4: {
                if (!root) printf("Danh sach trong!\n");
                else bst_inorder(root);
                break;
            }
            case 0:
                bst_free(root);
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(choice != 0);
    return 0;
}