/*
    5.  Suppose 7 persons are recruited in a company to do their specific tasks.Each task requires a
        fixed amount of time to complete and all those tasks are needed to be done in a single
        platform that can be shared by each employee. But as per the regulations of the company
        every employee should report to his/her immediate boss after doing the work every 2 units of
        time only. The following table shows the name of the employee, their assigned task number
        and total time required to complete their tasks. Find the order of the employees with different
        time stamps to accomplish the assigned tasks. You have to show starting time, ending time
        and the different time instants at which the employees shared that common platform. Take
        name of the employee as input who will start work first from 0th time instant.
*/

#include <limits.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <ctype.h>


struct Node{
    int task,timeleft;
    struct Node* next;
};


struct Node *push(int ,int ,struct Node *);
void findWaitTime(int time_req[],int tat[],int used[][100],struct Node *); 
void print(int task[],char *name,int time_req[],struct Node *last);
  
int main() 
{ 
	struct Node * last=NULL;
 	int task[7]={1,2,3,4,5,6,7},time_req[7],ta,t;
 	char name[7],ch='A';
 	printf("The persons arrive in the order of the task they perform\n");
 	for(int i=0;i<7;i++)
 	{
 		printf("Enter task number and time required to finish that task for %c : ",ch+i);
 		scanf("%d %d",&ta,&t);
 		name[ta-1]=ch+i,time_req[ta-1]=t;
 	}
 	for(int i=0;i<7;i++)
 		last=push(i,time_req[i],last);
    print(task,name,time_req,last); 
    return 0; 
} 

struct Node *push(int task,int data,struct Node *last)
{
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	if(last==NULL)
		 temp->task=task,temp->timeleft=data,temp->next=temp,last=temp;
	else
	{
		 temp->task=task,temp->timeleft=data,temp->next=last->next,last->next=temp;
		 last=temp;
	}
	return last;
	
}

void findWaitTime(int time_req[],int tat[],int used[7][100],struct Node *last) 
{ 
int k=0,temp=0,total=7,c=0;
	while(1)
	{
		if(last->next==last)
			{
				used[(last->next)->task][k]=temp;
				temp=temp+(last->timeleft);
				tat[last->task]=temp;
				while(last->timeleft>0)
				{
					used[(last->next)->task][k+1]=used[(last->next)->task][k]+(last->timeleft==1?1:2);
					last->timeleft=last->timeleft-2,k++;
				}
				last=NULL;
				return;
			}
		if((last->next)->timeleft>2)
		{
			used[(last->next)->task][k]=temp;
			temp=temp+2,c++;
			(last->next)->timeleft=(last->next)->timeleft-2;
			last=last->next;
		}
		else
		{
			struct Node *t=last->next;
			used[(last->next)->task][k]=temp;
		    last->next=t->next;
			temp=temp+(t->timeleft);
			tat[t->task]=temp;
			free(t);
			total--;
		}
		if(c==total)
			c=0,k++;	
	}  
} 

void print(int task[],char *name,int time_req[],struct Node *last) 
{ 
    int tat[7];
    int used[7][100]; 
    struct Node *temp=last->next;
    findWaitTime(time_req,tat,used,last); 
  
    printf( " Task | Name | Arrival Time | Time Spent | Finish Time | Usage Times\n"); 
    for (int i=0;i<7;i++) 
    {
        printf("  %d\t %c\t 0\t\t%d\t\t%d\t  ",i+1,name[i],time_req[i],tat[i]);
        int z=(time_req[i]+1)/2;
        for(int j=0;j<z;j++)
        	printf("%d ",used[i][j]);
        printf("\n");
    } 
  
} 