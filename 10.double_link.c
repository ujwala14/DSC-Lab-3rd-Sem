/*Write a C program to implement a doubly linked circular list 
with a header node and perform the following operations on it.
(i)   Insert a node             
(ii)  Delete a node 
(iii) Display a doubly linked circular list in forward direction
(iv)  Display a doubly linked circular list in reverse direction */

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left,*right;
};
typedef struct node* nodeptr;
nodeptr head;

void insert(int x)
{
	nodeptr temp,rear;
	rear=head->left;
	
	temp=(nodeptr)malloc(sizeof(nodeptr*));
	temp->data=x;
	
	rear->right=temp;
	temp->left=rear;
	temp->right=head;
	head->left=temp;
}
nodeptr search(int x)
{
	nodeptr temp=head->right;
	while(temp!=head)
	{
		if(temp->data==x)
			return temp;
		temp=temp->right;
	}
	return NULL;
}
void del(int x)
{
	nodeptr temp=search(x);
	
	if(!temp)
		printf("\nNot found to delete!");
	else
	{
		printf("\nDeleting...%d",temp->data);
		temp->left->right=temp->right;
		temp->right->left=temp->left;
		free(temp);
	}
}

void disp_front()
{
	nodeptr temp;
	printf("\nDisplaying from front:\n");
	for(temp=head->right; temp!=head; temp=temp->right)
		printf("%d\t",temp->data);
}

void disp_back()
{
	nodeptr temp;
	printf("\nDisplaying from back:\n");
	for(temp=head->left; temp!=head; temp=temp->left)
		printf("%d\t",temp->data);
}

int main()
{
	int ch,x;
	
	head=(nodeptr)malloc(sizeof(nodeptr*));
	head->data=-1;
	head->left=head;
	head->right=head;
	
	for(;;)
	{
		printf("\n1:Insert\n2:Delete\n3:Display from front");
		printf("\n4:Display from back\n5:Exit\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element to insert: ");
				scanf("%d",&x);
				insert(x);
				break;
			case 2:
				printf("\nEnter element to delete: ");
				scanf("%d",&x);
				del(x);
				break;
			case 3:
				disp_front(); break;
			case 4:
				disp_back(); break;
			default:
				return 0;
		}
	}
}
