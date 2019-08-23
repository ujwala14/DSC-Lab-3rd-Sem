/*Write a C program to implement a max heap using an array 
and perform the following operations on it.
(i)   Insert an item        
(ii)  Delete an item       
(iii) Display a heap */

#include<stdio.h>
#include<stdlib.h>
#define max 20
#define heapfull(n) (n==max)
#define heapempty(n) (n==0)

typedef struct
{
	int key;
}element;
element heap[max+1];
int n=0;

void insert(element x)
{
	int i;
	if(heapfull(n))
		printf("\nHeap is full...cannot insert");
	else
	{
		i=++n;
		while((i!=1) && (x.key>heap[i/2].key))
		{
			heap[i]=heap[i/2];
			i/=2;
		}
		heap[i]=x;
	}
}
element del()
{
	element item,temp;
	int pa,ch;
	item.key=-1;
	if(heapempty(n))
		printf("\nHeap is empty..cannot delete");
	else
	{
		item=heap[1];
		temp=heap[n--];
		pa=1;
		ch=2;
		while(ch<=n)
		{
			if(ch<n && heap[ch+1].key>heap[ch].key)
				ch++;
			if(temp.key>=heap[ch].key)
				break;
			heap[pa]=heap[ch];
			pa=ch;
			ch=ch*2;
		}
		heap[pa]=temp;
	}
	return item;
}
void disp()
{
	int i;
	printf("\nThe Heap:\n");
	for(i=1;i<=n;i++)
		printf("%d\t",heap[i].key);
}

int main()
{
	int ch;
	element e;
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
				break;
			case 3:
				disp();
				break;
			default:
				return 0;
		}
	}
}
