/*Write a C program to implement a binary search tree using 
linked representation and perform the following operations on it.
(i)   Insert an item     
(ii)  Search an item   
(iii) Inorder Traversal  */

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int key;
}element;
struct node
{
	element data;
	struct node* lchild,*rchild	;
};
typedef struct node* nodeptr;

element* search(nodeptr root,int x)
{
	if(!root)
		return NULL;
	else if(x==root->data.key)
		return &(root->data);
	else if(x<root->data.key)
		return search(root->lchild,x);
	else
		return search(root->rchild,x);
}

void insert(nodeptr *root,int x)
{
	nodeptr temp,cur,trail;
	
//	printf("\nInsert() called");
	temp=(nodeptr)malloc(sizeof(nodeptr*));
	temp->data.key=x;
	temp->lchild=NULL;
	temp->rchild=NULL;
//	printf("\nNode created");
	
	if(!(*root))
		*root=temp;
	else
	{
		cur=*root;
		trail=NULL;
		while(cur)
		{
			trail=cur;
			if(x < cur->data.key)
				cur=cur->lchild;
			else if(x > cur->data.key)
				cur=cur->rchild;
			else
			{
				printf("\nNode exists!");
				return;
			}
		}
		if(x < trail->data.key)
			trail->lchild=temp;
		else
			trail->rchild=temp;
	}
}

void in_disp(nodeptr root)
{
	if(root)
	{
		in_disp(root->lchild);
		printf("%d\t",root->data.key);
		in_disp(root->rchild);
	}
}

int main()
{
	int ch,x;
	element *e;
	nodeptr root=NULL;	//imp
	for(;;)
	{
		printf("\n1:Insert\n2:Search\n3:Display(inonder)");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter element to insert: ");
				scanf("%d",&x);
				insert(&root,x);
				break;
			case 2:
				printf("\nEnter element to search: ");
				scanf("%d",&x);
				e=search(root,x);
				if(!e)
					printf("\nNot found!");
				else
					printf("\nFound!");
				break;
			case 3:
				printf("\nThe inorder traversal: \n");
				in_disp(root);
				break;
			default:
				return 0;
		}
	}
}

