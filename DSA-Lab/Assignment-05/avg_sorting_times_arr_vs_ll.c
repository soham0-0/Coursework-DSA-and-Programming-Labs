/*
    Write a program that takes a single positive integer (say N) as a command line
    argument, generates N random integers between 0 and 10, 000. Insert them (one
    by one) into a list in sorted order. Assume the list is initially empty.
    Example: Generated elements: 8, 5, 10, 1, . . . List: 8 → 5 8 → 5 8 10 → 1 5 8 10.
    I. Use the same process for storing the elements using : (a) an array; (b) a linked list;
    II. Run your program 6 times each for N = 100, 500, 1000, 2000, 3000, . . ., 10000.
    Print the sorted list to standard output, and the time taken (followed by a single tab,
    but no newline) to standard error.
    III. Find the average time taken for each value of N and for each implementation
    method given above.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct LinkedList{
    int val;
    struct LinkedList* next;
};
typedef struct LinkedList LL;

void sortedPush(LL**, int);
void sortedPushArr(int*, int);
void display(LL*);

int main(){
    srand(time(0)); 
    int arr[12] = {100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000};
    for(int n=0; n<12; n++){
        int N = arr[n], k = 6;
        printf("\nFor N = %d:\n", N);
        double avg_time_array = 0, avg_time_ll = 0;
        while(k--){
            LL* head=NULL;
            int list[N+1], num[N];
            memset(list, -1, (N+1)*sizeof(int));
            for(int i = 0; i<N; i++){
                num[i] = rand()%10001;
            } 
            clock_t Atime = clock();
            for(int i=0; i<N; i++) sortedPushArr(list, num[i]);
            Atime = clock() - Atime;
            double time_taken_in_array_implementation = ((double)Atime)/CLOCKS_PER_SEC;
            clock_t Ltime = clock();
            for(int i=0; i<N; i++)  sortedPush(&head, num[i]);
            Ltime = clock() - Ltime;
            double time_taken_in_LL_implementation = ((double)Ltime)/CLOCKS_PER_SEC;
            display(head);
            avg_time_array+=time_taken_in_array_implementation;
            avg_time_ll+=time_taken_in_LL_implementation;
            fflush(stdout);
            fprintf(stderr, "\n\nTime taken in array implementation: %lf\n", time_taken_in_array_implementation);
            fflush(stderr);
            
            fflush(stdout);
            fprintf(stderr, "Time taken in LinkedList implementation: %lf\n\n", time_taken_in_LL_implementation);
            fflush(stderr);
            printf("\n");
        }
        fflush(stdout);
        fprintf(stderr, "\nAverage Time taken in array implementation: %lf\n", avg_time_array/6);
        fflush(stderr);
        
        fflush(stdout);
        fprintf(stderr, "\nAverage Time taken in LinkedList implementation: %lf\n", avg_time_ll/6);
        fflush(stderr);
        printf("\n\n");
    }
    return 0;
}

void sortedPush(LL** head, int val){
    if(*head == NULL || (*head)->val > val) {
        LL* new = (LL*)malloc(sizeof(LL));
        new->next = *head;
        new->val = val;
        *head = new;
        return ;
    }
    LL* temp = *head;
    while(temp->next!=NULL && temp->next->val<val){
        temp = temp->next;
    }
    LL* new = (LL*)malloc(sizeof(LL));
    new->val = val;
    new->next = temp->next;
    temp->next = new;
    return ;
}

void sortedPushArr(int* list, int val){
    if(list[0]==-1){
        list[0] = val;
        return ;
    }
    int i = 0, tem = 0;
    while(list[i]!=-1 && list[i]<val){
        i++;
    }
    tem = list[i];
    list[i] = val;
    i++;
    while(list[i]!=-1){
        tem^=list[i];
        list[i]^=tem;
        tem^=list[i];
        i++;
    }
    list[i] = tem;
    return ;
}

void display(LL* head){
    while(head!=NULL){
        printf("%d ", head->val);
        if(head->next!=NULL){
            printf("-> ");
        }
        head=head->next;
    }
}