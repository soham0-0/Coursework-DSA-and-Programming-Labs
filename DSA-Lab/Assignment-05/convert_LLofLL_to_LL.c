/*
    You are given a linked list of linked lists. Write a program to create a singly linked list
    as shown in the following example.
    Input
    2 → 6 → 21 → 25
    ↓    ↓    ↓     ↓
    1   11   22    35
    ↓    ↓    ↓
    8   50   47
    ↓    ↓
    19  89
    Output 2 → 1 → 8 → 19 → 6 → 11 →50 → 89 → 21 → 22 →47 → 25 → 35
    Take input from a file with following format:
    Line 1: # Number of lists
    Line 2: Elements of List 1
    Line 3: Elements of List 2
    And so on
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct LinkedList{
    int val;
    struct LinkedList* next;
};
typedef struct LinkedList LL;
struct ListofLinkedLists
{
    LL* list;
    struct ListofLinkedLists* next;
};
typedef struct ListofLinkedLists LLL;

void insert(LL**, int);
void push(LLL**, LL*);
void display(LLL*);

int main(){
    int numOfLists;
    LLL* HEAD = NULL;
    printf("Enter Number of lists: ");
    scanf(" %d", &numOfLists);
    for(int i=0; i<numOfLists; i++){
        int n = 1;
        LL* head = NULL;
        printf("Enter Elements of list %d space seperated:\n", i+1);
        char elem[500];
        scanf(" %[^\n]c*", elem);
        char *token = strtok(elem, " ");
        while(token!=NULL){
            insert(&head, atoi(token));
            token = strtok(NULL, " ");
        }
        push(&HEAD, head);
    }
    printf("Displaying: \n");
    display(HEAD);
    printf("\n");
    return 0;
}

void insert(LL** head, int val){
    if(*head==NULL){
        *head = (LL*)malloc(sizeof(LL));
        (*head)->val = val;
        (*head)->next = NULL;
        return ;
    }
    LL* temp = *head;
    while(temp->next!=NULL) temp = temp->next;
    temp->next = (LL*)malloc(sizeof(LL));
    temp->next->val = val;
    temp->next->next= NULL;
    return ;
}

void push(LLL** head, LL* list){
    if(*head==NULL){
        *head = (LLL*)malloc(sizeof(LLL));
        (*head)->list = list;
        (*head)->next = NULL;
        return ;
    }
    LLL* temp = *head;
    while(temp->next!=NULL) temp = temp->next;
    temp->next = (LLL*)malloc(sizeof(LLL));
    temp->next->list = list;
    temp->next->next= NULL;
    return ;
}

void display(LLL* head){
    while(head!=NULL){
        LL* tem = head->list;
        while(tem!=NULL){
            printf("%d ", tem->val);
            if(tem->next!=NULL){
                printf("-> ");
            }
            tem=tem->next;
        }
        if(head->next!=NULL){
            printf("-> ");
        }
        head = head->next;
    }
}