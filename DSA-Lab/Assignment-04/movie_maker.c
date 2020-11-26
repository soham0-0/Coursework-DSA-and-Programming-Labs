/*
	1.	Design a program to simulate “Movie-Maker”. It must have the following functionalities: -
	 	-Allow the users to add images to the slide show.
		-Allow the users to delete any image from the list.
		-Allow the users to start the slide show.
		There must be a comfortable time gap between two consecutive images.
		(The path of individual images are stored in a singly circular linked list. The slide show can start from any slide.)
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 300
struct Node
{
	char imgPath[SIZE];
	struct Node *next;
};

void delay(int time);
struct Node *push(struct Node *last);
void delete(struct Node *last);
void display(struct Node *last);

int main()
{
	struct Node *last=NULL;
	int n=1;
	while(n)
	{
		printf("Press 0 to exit\nPress 1 to insert Image\nPress 2 to delete Image\nPress 3 to start Slide Show\n");
		scanf("%d",&n);
		switch (n)
		{
			case 1:
				last = push(last);
				break;
			case 2:
				delete(last);
				break;
			case 3:
				display(last);
			default:
				break;
		}
	}
	return 0;
}

void delay(int time) {
	int ms = SIZE * time;
	clock_t start = clock();
	while (clock() < start + ms);
}

struct Node *push(struct Node *last) {
	char imgPath[SIZE];
	printf("Enter the Image Path: ");
	scanf("%s", imgPath);
	struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
	if(last==NULL)
		strcpy((temp->imgPath),imgPath),temp->next=temp,last=temp;
	else
		strcpy((temp->imgPath),imgPath),temp->next=last->next,last->next=temp,last=temp;
	return last;
}

void delete(struct Node *last) {
	if(last==NULL)
	{
		printf("No Images to delete!\n");
		return ;
	}
	char imgPath[SIZE];
	printf("Enter Image Path to delete: ");
	scanf("%s", imgPath);
	struct Node *temp, *p; 
	p=last->next;
	temp=last;
	do
	{
		if(strcmp((p->imgPath),imgPath)==0)
		{
			temp->next=p->next;
			free(p);
			return;
		}
		temp=p;	
		p=p->next;
		
	}
	while(p!=last->next);
	printf("Image not found!\n");
}

void display(struct Node *last) {
	struct Node *temp=last->next;
	do
	{
		printf("%s\n", temp->imgPath);
		fflush(stdout);
		delay(2000);
		temp=temp->next;
		
	}
	while(temp!=last->next);
	printf("\n");
}