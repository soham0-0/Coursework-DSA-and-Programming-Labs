/*
    4.  Suppose we have two queues, P and Q, and one stack S. We are only allowed to dequeue
        from P and allowed to enqueue into the Q. We can do push and pop from the stack. In this
        assignment, you will be given a permutation of n numbers and asked to check if it is a stack
        permutation or not.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <ctype.h>
#include <limits.h> 

#define SIZE 1000
struct QUEUE 
{ 
    int front,back,size; 
    int array[SIZE]; 
}; 

void push(int *, int , int*);
int pop(int *, int *);
void enqueue(struct QUEUE *, int);
void dequeue(struct QUEUE *);
int front(struct QUEUE *);
int back(struct QUEUE *);

int main() 
{ 
	int stack[SIZE], top=-1;
    struct QUEUE qi,qo;
    qi.front=0,qi.back=0,qi.size=0;
    qo.front=0,qo.back=0,qo.size=0;
   	printf("Enter a number: ");
   	int n,x;
   	scanf("%d",&n);
  	printf("Enter permutation of %d numbers\n",n);
  	int a[n];
  	for(int i=0;i<n;i++)
  		scanf("%d",&x),enqueue(&qi,x);
  	printf("Enter a seperate permutation of %d numbers\n",n);
  	for(int i=0;i<n;i++)
  		scanf("%d",&a[i]);
  	for(int i=0;i<n;)
  	{
  		push(stack,front(&qi),&top);
  		printf("%d ",stack[top]);
  		dequeue(&qi);
  		if(top>=0 && stack[top]==a[i])
  			while(top>=0 && stack[top]==a[i])		
  				enqueue(&qo,stack[top]),pop(stack,&top),i++;
  		if(qi.size==0)
  			break;
  	}
  	if(top==-1 && qi.size==0)
  		printf("It is a Stack Permutation.\n");
  	else
  		printf("It is not a Stack Permutation.\n");
    return 0; 
} 

void push(int *stack, int elem, int *top) {
    if(*top==SIZE){
        printf("Stack Overflow!!");
        return;
    }
    stack[++*top]=elem;
}

int pop(int *stack, int *top) {
    if(*top==-1){
        printf("Stack Underflow!!");
        return INT_MIN;
    }
    return stack[(*top)--];
}

void enqueue(struct QUEUE *queue, int item) { 
    if (queue->size == SIZE) 
        return; 
    queue->array[queue->back] = item; 
    queue->back = (queue->back + 1)  %1000; 
    queue->size = queue->size + 1; 
} 
  
void dequeue(struct QUEUE *queue) { 
    if (queue->size == 0) 
        printf("No more items left!");
    queue->front = (queue->front + 1) %1000; 
    queue->size = queue->size - 1; 
} 

int front(struct QUEUE *queue)  { 
    if (queue->size == 0) 
    {
    	printf("Queue empty");
        return INT_MIN; 
    }
    return queue->array[queue->front]; 
} 
int back(struct QUEUE *queue) { 
    if (queue->size == 0) 
    {
    	printf("Queue empty");
        return INT_MIN; 
    }
    return queue->array[queue->back-1]; 
} 