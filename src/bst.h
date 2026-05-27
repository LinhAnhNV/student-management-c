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
void     bst_inorder(BSTNode *root);
void     bst_free(BSTNode *root);

#endif