#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

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
    else printf("MSSV %s đã tồn tại!\n", s.mssv);
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