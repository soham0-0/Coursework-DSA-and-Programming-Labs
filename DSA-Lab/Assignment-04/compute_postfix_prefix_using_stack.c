/*
    3.  Write a program to evaluate a postfix and prefix expression using a stack data structure.
        Your program has to consider two or three-digit numbers (eg.112 34 5 * + ) Implement the
        stack using Linked List ADT.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

struct Node
{
	int data;
	struct Node *prev;
};
struct Node *top;
void push(int);
int pop();
void display();

int main()
{
    int selec;
	char input[10*SIZE];
    printf("Enter 1 to compute prefix exp or Enter 2 to compute postfix exp: ");
    scanf("%d", &selec);
    printf("Enter Input: ");
    scanf(" %[^\n]*c", input);
    switch (selec)
    {
    case 1:{
            char *ptr = strtok(input, " "), tem[SIZE][SIZE];
            int size = 0;
            while(ptr != NULL)
            {
                strcpy(tem[size++], ptr);
                ptr = strtok(NULL, " ");
            }
            while(size--){
                if(strlen(tem[size])==1 && tem[size][0]<'0')
                {
	                int a=pop();
                    int b=pop();
                    if(tem[size][0]=='+')       push(a+b);
                    else if(tem[size][0]=='-')  push(a-b);
                    else if(tem[size][0]=='*')  push(a*b);
                    else if(tem[size][0]=='/')  push(a/b);
                    else if(tem[size][0]=='%')  push(a%b);
                    else
                    {
                        push(a);
                        push(b);
                    }                        
                }
                else
                {
                    int intValue=atoi(tem[size]);
                    push(intValue);
                }
            }
            int ans=top->data;
            printf("Evaluated Result: %d\n",ans);
        }
        break;
    case 2:{
            char *ptr = strtok(input, " ");
            while(ptr != NULL)
            {
                    if(strlen(ptr)==1 && ptr[0]<'0')
                    {
                        int b=pop();
                        int a=pop();
                        if(ptr[0]=='+')       push(a+b);
                        else if(ptr[0]=='-')  push(a-b);
                        else if(ptr[0]=='*')  push(a*b);
                        else if(ptr[0]=='/')  push(a/b);
                        else if(ptr[0]=='%')  push(a%b);
                        else
                        {
                            push(a);
                            push(b);
                        }                         
                    }
                    
                    else
                    {
                        int intValue=atoi(ptr);
                        push(intValue);
                    }
                ptr = strtok(NULL, " ");
            }
            int ans=top->data;
            printf("Evaluated Result: %d\n",ans);
        }
        break;
    default:
        break;
    }
    return 0;
}

void push(int value) {
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); 
	temp->data=value;
	temp->prev=top;
	top=temp;
}

int pop() {
	struct Node *temp;
	if(top==NULL)
	{
		printf("\nStack underflow\n");
		exit(1);
	}
	else
	{   
        int r = top->data;
		temp=top;
		top=top->prev;
		temp->prev=NULL;
		free(temp);
        return r;
	}
}

void display() {  
    struct Node* temp; 
    if (top == NULL) 
    {  
        printf("\nStack Underflow"); 
    }  
    else 
    {  
        temp = top;  
        while (temp != NULL) 
        { 
            printf("%d -> ",temp->data); 
            temp = temp->prev;  
        }  
    }  
    printf("\n");
}