/*
    2.  A binary tree is termed as a mirror twin of a binary search tree (BST) if both of them
        comprise the same set of val items and they are structurally mirror images to each other.
        Given the pre-order traversal of a BST and the in-order and pre-order traversals of a simple
        binary tree as user inputs, write a program to determine whether the binary tree is a mirror
        twin of the BST or not. As for example, the binary tree shown below (in the right side) is a
        mirror twin of the BST given below (in the left side).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct binaryTree {
    int val;
    struct binaryTree *left, *right;
} btree;

int idx;
int search(int*, int, int, int);
btree *newNode(int);
btree *buildTree(int*, int*, int, int);
void postOrder(btree* , int*);

int main(){
    int n1, n2; scanf("%d %d", &n1, &n2);
    if(n1 != n2) {  //  If number of elements not equal then it is not a mirror twin
        puts("NOT MIRROR TWIN");
        return 0;
    }
    //  Input
    int preBST[n1], inBT[n2], preBT[n2];
    for(int i=0; i<n1; ++i) scanf(" %d", &preBST[i]);
    for(int i=0; i<n2; ++i) scanf(" %d", &inBT[i]);
    for(int i=0; i<n2; ++i) scanf(" %d", &preBT[i]);

    // Constructing a binary tree from inorder and preorder traversals
    btree *root = buildTree(inBT, preBT, 0, n2 - 1);
    int postBT[n2]; //  Array to store the postorder traversal
    postOrder(root,postBT); //  Computing postorder traversal of binary tree
    bool mirror = true;

    // If the binary tree is a mirror to the BST. its post order must be reverse of the pre order of the BST
    // Checking required condition
    for(int i=0;i<n1;i++) {
        if(postBT[i]!=preBST[n1-1-i]) {
            mirror=false;
            break ;
        }
    }

    // Output
    if(mirror) puts("MIRROR TWIN");
    else puts("NOT MIRROR TWIN");
    return 0;
}

int search(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
}

btree *newNode(int val) {
    btree *node = (btree *)malloc(sizeof(btree));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

btree *buildTree(int in[], int pre[], int inStart, int inEnd) {
    static int preIndex = 0;
    if (inStart > inEnd) return NULL;
    btree *tNode = newNode(pre[preIndex++]);
    if (inStart == inEnd) return tNode;
    int inIndex = search(in, inStart, inEnd, tNode->val);
    tNode->left = buildTree(in, pre, inStart, inIndex - 1);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd);
    return tNode;
}

void postOrder(btree *node, int *postBT) {
    if (node == NULL) return;
    postOrder(node->left,postBT);
    postOrder(node->right,postBT);
    postBT[idx++]=node->val;
}