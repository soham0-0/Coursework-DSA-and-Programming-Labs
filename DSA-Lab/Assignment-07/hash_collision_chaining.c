/*
    1.  Write a C Program for resolving the collision in the hash algorithm by
        implementing the chaining method.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int SIZE = 100;  
typedef struct LinkedList {
    int val;
    struct LinkedList* next;
} LL;

void append(int, LL**);
void display(LL*);
int hash(int key){ return key%SIZE; }   //  MOD SIZE hash function

int main(){
    LL *table[SIZE];
    memset(table, 0, SIZE*sizeof(LL*));
    char c; int val;
    do {
        printf("Enter value : ");
        scanf(" %d", &val);
        append(val, &table[hash(val)]);
        printf("Do you want to insert more values? (y/n): ");
        scanf(" %c", &c);
    }while(c == 'y');
    printf("MOD %d Hash Table: \n");
    for(int i = 0; i<SIZE; ++i){
        if(table[i]){
            printf("%d : ", i);
            display(table[i]);
        }
    }
    return 0;
}

void append(int val, LL **head){
    if(!(*head)){
        *head =  (LL*)malloc(sizeof(LL));
        (*head)->val = val;
        (*head)->next = NULL;;
        return ;
    }
    else {
        LL *cur = *head;
        while(cur->next) { cur = cur->next; }
        cur->next = (LL*)malloc(sizeof(LL));
        cur->next->val = val;
        cur->next->next = NULL;
    }
}

void display(LL *head){
    while(head){
        printf("%d", head->val);
        if(head->next) printf(" -> ");
        head = head->next;
    }
    puts("");
}