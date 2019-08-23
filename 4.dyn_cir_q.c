/*Write a C program to implement a circular queue using 
dynamically allocated array and perform the following operations on it.
(i)	Insert an item      
(ii) Delete an item             
(iii)  Display a circular queue */

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int key;
}element;
element *queue;
int f=0,r=0;
int cap=1;

void qfull();
void insert(element x)
{
	if((r+1)%cap == f)
		qfull();
	r=(r+1)%cap;
	queue[r]=x;
}
element qempty()
{
	element item;
	item.key=-1;
	return item;
}
element del()
{
	if(f==r)
		return qempty();
	f=(f+1)%cap;
	return queue[f];
}
void disp()
{
	int i;
	printf("\nThe queue:\n");
	for(i=(f+1)%cap; i!=(r+1)%cap ; i=(i+1)%cap)
		printf("%d\t",queue[i].key);
}
void copy(element *q,element *s,element *e)
{
	int i=0;
	while(s<e)
	{
		*(q+i)=*s;
		i++;s++;
	}
}
void qfull()
{
	element *nq=(element*)malloc(sizeof(element)*2*cap);
	int start=(f+1)%cap;
	
	if(start<2)
		copy(nq,queue+start,queue+r+1);
	else
	{
		copy(nq,queue+start,queue+cap);
		copy(nq+cap-start,queue,queue+r+1);
	}
	
	r=cap-2;
	f=2*cap-1;
	cap*=2;
	free(queue);
	queue=nq;
	
	printf("\nCapacity increased to...%d",cap);
}

int main()
{
	int ch;
	element e;
	queue=(element*)malloc(sizeof(element));//imp!!!!
	
	for(;;)
	{
		printf("\n1:Insert\n2:Delete\n3:Display\n4:Exit\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element to insert: ");
				scanf("%d",&e.key);
				insert(e);
				break;
			case 2:
				e=del();
				if(e.key!=-1)
					printf("\nElement deleted: %d",e.key);
				else
					printf("\nQueue is empty...no element to delete");
				break;
			case 3:
				disp();
				break;
			default:
				return 0;
		}
		disp();
	}
}
