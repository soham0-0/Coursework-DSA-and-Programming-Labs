/*
    3.  Write a program to implement BST using three array (data, left address, right address).
        Also write an in-order traversal of this binary search tree using stack.
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int SIZE;
void push(int *, int *, int);
int pop(int *, int *);
void display(int *, int);
void insert(int , int *, int *, int *, int *);
void inorder(int , int *, int *, int *, int *, int *);

int main(){
    int n; printf("Enter number of elements: ");
	scanf("%d", &n);
    SIZE = n;
	int val[n], left[n], right[n];
	int stack[n], top = -1;
	for (int i = 0; i < n; i++) val[i] = left[i] = right[i] = -1;
	int root = -1;
	printf("Enter elements: \n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
		insert(i, &root, val, left, right);
	}
	printf("Inorder traversal: ");
	inorder(0, val, left, right, stack, &top);
	display(stack, top);
	puts("");
    return 0;
}

void insert(int ind, int *r, int *data, int *left, int *right) {
	if (*r == -1) {
		*r = ind;
		left[ind] = -1;
		right[ind] = -1;
	}
	else if (data[ind] > (data[*r]))    insert(ind, &right[*r], data, left, right);
    else    insert(ind, &left[*r], data, left, right);
}

void inorder(int ind, int *data, int *left, int *right, int *stack, int *top) {
	if (right[ind] != -1)   inorder(right[ind], data, left, right, stack, top);
    push(stack, top, data[ind]);
	if (left[ind] != -1)    inorder(left[ind], data, left, right, stack, top);
}

void push(int *stack, int *top, int elem){
    if(*top==SIZE){
        printf("Stack Overflow!!");
        return;
    }
    stack[++*top]=elem;
}

int pop(int *stack, int *top){
    if(*top==-1){
        printf("Stack Underflow!!");
        return INT_MIN;
    }
    return stack[(*top)--];
}

void display(int *stack, int top){
    while(top!=-1){
        printf("%d ", stack[top--]);
    }
}