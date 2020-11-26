/*
Q2. Sort the given set of elements present in three stack data structures and put
    them in a single stack, without using any other variable.
*/

#include<stdio.h>
#include<limits.h>

#define SIZE 50

void push(int *, int *, int);
int pop(int *, int *);
void display(int *, int);

void pushAscending(int *stack, int *top, int x)
{
    if(*top==-1 || x>stack[*top])
    {
        push(stack, top, x);
        return;
    }
    int tem=pop(stack, top);
    pushAscending(stack, top, x);
    push(stack, top, tem);
}

void sort3Stacks(int stack[][SIZE], int *top){
    if(top[0]+top[1]+top[2]+3>SIZE) {
        printf("Final Stack will overeflow!! Total no. of elements > Stack SIZE\n");
        return;
    }
    for(int i=1; i<3; i++){ 
        while(top[i]!=-1){
            push(stack[0], &top[0], pop(stack[i], &top[i]));
        }
    }
    if(top[0]!=-1){
        int tem = pop(stack[0], &top[0]);
        sort3Stacks(stack, top);    
        pushAscending(stack[0], &top[0], tem);
    }
}

int main(){
    int stack[3][SIZE], top[3]={-1, -1, -1};
    for(int i=0; i<3; i++){
        char yn = 'y';
        while(yn=='y'){
            printf("Push Element in Stack %d:\n",i+1);
            printf("Enter Element: ");
            int elem; scanf(" %d", &elem);
            push(stack[i], &top[i], elem);
            display(stack[i],top[i]);
            printf("Do you want to add more? (y/n)\n");
            scanf(" %c", &yn);
        }
    }
    sort3Stacks(stack, top);
    printf("Sorted elements in one stack: \n");
    display(stack[0], top[0]);
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
    while(top!=-1){
        printf("| %d |\n", stack[top--]);
    }
}