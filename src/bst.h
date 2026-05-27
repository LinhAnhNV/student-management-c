#ifndef BST_H
#define BST_H
#include "student.h"

typedef struct BSTNode {
    Student data;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

BSTNode* bst_insert(BSTNode *root, Student s);
BSTNode* bst_search(BSTNode *root, const char *mssv);
BSTNode* bst_delete(BSTNode *root, const char *mssv);
void     bst_update(BSTNode *root, const char *mssv);
void     bst_search_by_name(BSTNode *root, const char *name);
void     bst_thong_ke(BSTNode *root);
void     bst_inorder(BSTNode *root);
void     bst_inorder_table(BSTNode *root);
void     bst_free(BSTNode *root);
void     bst_save(BSTNode *root, const char *filename);
void     bst_load(BSTNode **root, const char *filename);
void bst_sort_and_print(BSTNode *root, int (*cmp)(const void*, const void*));
void bst_export_report(BSTNode *root, const char *filename);
int bst_to_array(BSTNode *root, Student *arr, int max);
int cmp_by_gpa(const void *a, const void *b);
int cmp_by_name(const void *a, const void *b);
int cmp_by_major(const void *a, const void *b);

#endif