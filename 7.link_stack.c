/*Write a C program to implement multiple linked stacks (at least 3) 
and perform the following operations on them
(i)  Push an item in ith stack       
(ii) Pop an item from ith stack
(iii)Display ith stack */

#include<stdio.h>
#include<stdlib.h>
#define max 7

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
listptr top[max];

void push(int i,element x)
{
	listptr temp=(listptr)malloc(sizeof(listptr*));
	temp->data=x;
	temp->link=top[i];
	top[i]=temp;
}
element pop(int i)
{
	listptr temp;
	element item;
	if(top[i])
	{
		temp=top[i];
		item=temp->data;
		top[i]=top[i]->link;
		free(temp);
	}
	else
	{
		printf("\nStack is empty...No element to pop!");
		item.key=-1;
	}
	return item;
}

void disp(int i)
{
	listptr temp=top[i];
	printf("\nThe Stack:\n");
	while(temp)
	{
		printf("%d\n",temp->data.key);
		temp=temp->link;
	}
}

int main()
{
	int ch,i,n;
	element e;
	printf("\nEnter no. of stacks: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		top[i]=NULL;
		
	for(;;)
	{
		printf("\n1:Push\n2:Pop\n3:Display\n4:Exit\nEnter choice: ");
		scanf("%d",&ch);
		if(ch>=1 && ch<=3)
		{
			printf("\nEnter stack no.: ");
			scanf("%d",&i);
			if(i>n)
			{
				printf("\nWrong stack no.!");
				continue;
			}
		}
		switch(ch)
		{
			case 1:	printf("\nEnter element to insert: ");
					scanf("%d",&e.key);
					push(i,e);
					break;
			case 2: e=pop(i);
					if(e.key!=-1)
						printf("\nElement popped: %d",e.key);
					break;
			case 3: disp(i);
					break;
			default: return 0;
		}
	}
}
