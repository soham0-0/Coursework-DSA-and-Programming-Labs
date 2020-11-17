/*
    2.  Implement a ternary tree where each node may contain two key values in sorted form.
        Each node may have maximum three children. Data insertion rule for the tree is as search
        tree i.e. data in leftmost child is less than the data of first key. Data in the middle child is
        greater that the first key but less than second key. Data in third child is greater than the data
        in second key.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct ternary_tree {
    int v1, v2;
    bool filled;
    struct ternary_tree *left, *middle, *right;
} ttree;

void insert(ttree **, int);
void inorder(ttree *);

int main() {
    ttree *root = NULL;
    int n, val; printf("Enter number of elements: ");
    scanf(" %d", &n);
    puts("Enter the elements of the array:");
    while(n--) {
        scanf(" %d", &val);
        insert(&root, val);
    }
    puts("Inorder Traversal:");
    inorder(root);
    puts("");
    return 0;
}

void insert(ttree **root, int val){
    if(!(*root)) {
        (*root) = malloc(sizeof(ttree));
        (*root)->v1 = val; (*root)->filled = false;
        (*root)->left = NULL;
        (*root)->middle = NULL;
        (*root)->right = NULL;
    }
    else if(!(*root)->filled) {
        if(val > (*root)->v1) (*root)->v2 = val;
        else {
            (*root)->v2 = (*root)->v1;
            (*root)->v1 = val;
        }
        (*root)->filled = true;
    }
    else if((*root)->v1 > val) insert(&(*root)->left, val);
    else if((*root)->v2 < val) insert(&(*root)->right, val);
    else insert(&(*root)->middle, val);
}

void inorder(ttree *root){
    if(!root) return ;
    if(root->left) inorder(root->left);
    printf("%d ", root->v1);
    if(root->middle) inorder(root->middle);
    if(root->filled) printf("%d ", root->v2);
    if(root->right) inorder(root->right);
}