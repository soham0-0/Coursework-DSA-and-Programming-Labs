/*
Q1. Write a method duplicate Stack that returns a new stack containing the same
    elements and in the same order as the stack specified in the parameter. The
    method should create a new stack and fill it with the same data elements as
    the given stack. (You do not need to duplicate the contents of the elements.).
    Before the method finishes, it must restore the contents of the original stack
    to its original state (same contents in the same order).
*/

#include<stdio.h>
#include<limits.h>

#define SIZE 10

void push(int *, int *, int);
int pop(int *, int *);
void display(int *, int);

void duplicate(int *stack, int *top, int *duplicateStack, int *top2){
    int tempStack[SIZE], tem, tempTop=-1;
    while(*top!=-1){
        push(tempStack, &tempTop, pop(stack, top));
    }
    while(tempTop!=-1){
        int tem = pop(tempStack, &tempTop);
        push(stack, top, tem);
        push(duplicateStack, top2, tem);
    }
}

int main(){
    int stack[SIZE], duplicateStack[SIZE], top=-1, tempTop=-1, top2=-1, selec=0, q=1;
    while(q!=0){
        printf("0. Quit I/O and duplicate stack.\n1. Push Element in stack\n2. Pop Element from stack\n3. Display Stack\nEnter Choice (0-3): ");
        scanf(" %d", &selec);
        switch(selec){
            case 0: q=0;
                    break;
            case 1: {printf("Enter Element: ");
                    int elem; scanf(" %d", &elem);
                    push(stack, &top, elem);
                    display(stack,top);}
                    break;
            case 2: {int pelem = pop(stack,&top);
                    if(pelem!=INT_MIN) printf("Popped Element: %d\n", pelem);
                    display(stack,top);}
                    break;
            case 3: display(stack, top);
                    break;
            default:printf("Wrong Choice! try again!!\n");
        }
    }
    duplicate(stack, &top, duplicateStack, &top2);
    printf("Original stack:\n");
    display(stack, top);
    printf("Duplicated stack:\n");
    display(duplicateStack, top2);
    return 0;
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
    printf("- - -\n");
    while(top!=-1){
        printf("| %d |\n- - -\n", stack[top--]);
    }
}
