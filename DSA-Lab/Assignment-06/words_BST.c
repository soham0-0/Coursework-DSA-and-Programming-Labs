/*
    1.  You have a set of words. Write a program to sort all the words given using Binary search
        tree.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef struct words_BST {
    char val[MAX_SIZE];
    struct words_BST *left, *right;
} wbst;

void insert(wbst **, char*);
void inorder(wbst *);

int main(){
    int n; printf("Enter the number of elements in the set: ");
    scanf(" %d", &n);
    char str[MAX_SIZE]; wbst *root = NULL;
    puts("Enter the strings: ");
    while(n--){
        scanf(" %s", str);
        insert(&root, str);
    }
    printf("Sorted order: ");
    inorder(root);
    puts("");
    return 0;
}

void insert(wbst **root, char *str){
    if(!(*root)){
        (*root) = malloc(sizeof(wbst));
        strcpy((*root)->val, str);
        (*root)->left = NULL; (*root)->right = NULL;
    }
    else if(strcmp((*root)->val, str) > 0)  insert(&(*root)->left, str);
    else insert(&(*root)->right, str);
}

void inorder(wbst *root){
    if(!root) return;
    if(root->left) inorder(root->left);
    printf("%s ", root->val);
    if(root->right) inorder(root->right);
}