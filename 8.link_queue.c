/*Write a C program to implement multiple linked queues (at least 3) 
and perform the following operations on them
(i)	  Add an item in ith queue      
(ii)  Delete an item from ith queue
(iii) Display ith queue */

#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct
{
	int key;
}element;
struct node
{
	element data;
	struct node* link;
};
typedef struct node* listptr;
listptr f[max],r[max];

void insert(int i,element x)
{
	listptr temp;
	temp=(listptr)malloc(sizeof(listptr *));
	temp->data=x;
	temp->link=NULL;
	if(!f[i])
		f[i]=temp;
	else
		r[i]->link=temp;
	r[i]=temp;
}
element del(int i)
{
	listptr temp;
	element item;
	if(!f[i])
	{
		printf("\nQueue is empty...no element to delete!");
		item.key=-1;
	}
	else
	{
		temp=f[i];
		item=temp->data;
		f[i]=f[i]->link;
		free(temp);
	}
	return item;
}

void disp(int i)
{
	listptr temp=f[i];
	printf("\nThe Queue:\n");
	while(temp)
	{
		printf("%d\t",temp->data.key);
		temp=temp->link;
	}
}

int main()
{
	int ch,n,i;
	element e;
	
	printf("\nEnter no. of queues: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		f[i]=r[i]=NULL;
	
	for(;;)
	{
		printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit\nEnter choice: ");
		scanf("%d",&ch);
		if(ch>=1 && ch<=3)
		{
			printf("\nEnter queue no. : ");
			scanf("%d",&i);
			if(i>n)
			{
				printf("\nInvalid queue no.!\n");
				continue;
			}
		}
		
		switch(ch)
		{
			case 1:
				printf("\nEnter element to be inserted: ");
				scanf("%d",&e.key);
				insert(i,e);
				break;
			case 2:
				e=del(i);
				if(e.key!=-1)
					printf("\nElement deleted: %d",e.key);
				break;
			case 3:
				disp(i);
				break;
			default:
				return 0;
		}
	}
}
