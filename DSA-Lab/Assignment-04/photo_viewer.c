/*
	2. 	Design a program to simulate a “Photo-Viewer” having the following features: -
		-The path of the images are stored in a doubly circular linked list.
		-Allow the users to add an image at the current location.
		-Allow the user to delete an image at the current location.
		-Allow the user to navigate the images using any two buttons of his/her/ choice denoting the actions-previous and next.
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SIZE 300
struct Node {
	char image[SIZE];
	struct Node *next, *prev;
};

int cur=0;
struct Node *push(struct Node *last);
struct Node *delete(struct Node *last);
struct Node *navigate(struct Node *last);

int main() {
	struct Node *last=NULL;
	int n=1;
	while(n) {
		printf("PRESS 0 to EXIT / PRESS 1 to INSERT IMAGE / PRESS 2 to DELETE IMAGE / PRESS 3 to NAVIGATE\n");
		scanf("%d",&n);
		switch (n)
		{
		case 1:
			last = push(last);
			break;
		case 2:
			last = delete(last);
			break;
		case 3:
			last = navigate(last);
			break;
		default:
			break;
		}
	}
	return 0;
}


struct Node *push(struct Node *last) {
	char image[SIZE];
	printf("Enter an image : ");
	scanf("%s",image);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	if(last==NULL)
		strcpy((temp->image),image),temp->next=temp,temp->prev=temp,last=temp;
	else
		strcpy((temp->image),image),temp->next=last->next,temp->prev=last,(last->next)->prev=temp,last->next=temp,last=temp;
	cur++;
	return last;
}

struct Node *delete(struct Node *last) {
	if(cur==0)
	{
		printf("Enter images before you delete\n");
		return NULL;
	}
	struct Node *temp=last;
	(last->prev)->next=last->next;
	(last->next)->prev=last->prev;
	last=last->prev;
	free(temp);
	cur--;
	return last;
}

struct Node *navigate(struct Node *last) {
	char op[10],ch[10];
	printf("Enter keys using which you want to navigate left and right respectively : ");
	scanf("\n");
	scanf("%[^\n]%*c",op);
	int k=0;
	if(last==NULL)
	{
		printf("No photos available\n");
		return NULL;
	}
	do
	{
		printf("Current image : %s\n",last->image);
		printf("Move left or right using keys you've entered or press 0 to exit \n");
		scanf("%[^\n]%*c",ch);
		if(ch[0]==op[2])
			last=last->next;
		else if(ch[0]==op[0])
			last=last->prev;
	}
	while(ch[0]!='0');
	printf("\n");
	return last;
}