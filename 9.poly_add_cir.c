/*Write a C program to add two polynomials represented 
as circular linked lists with header nodes. Display both 
polynomials and the resultant polynomial after addition.*/

#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y) (((x)>(y))?1:(((x)==(y))?0:(-1)))

struct node
{
	int coeff,exp;
	struct node* link;
};
typedef struct node* polyptr;

void attach(int c,int e,polyptr *last)
{
	polyptr temp=(polyptr)malloc(sizeof(polyptr*));
	temp->coeff=c;
	temp->exp=e;
	(*last)->link=temp;
	(*last)=temp;
}
polyptr add(polyptr a,polyptr b)
{
	polyptr c,rear,starta;
	int sum,done=0;
	
	rear=(polyptr)malloc(sizeof(polyptr*));
	rear->link=rear;	//check
	rear->exp=-1;
	c=rear;
	
	starta=a;
	a=a->link;
	b=b->link;
	
	while(!done)
	{
		switch(COMPARE(a->exp,b->exp))
		{
			case 1:
				attach(a->coeff,a->exp,&rear);
				a=a->link;
				break;
			case -1:
				attach(b->coeff,b->exp,&rear);
				b=b->link;
				break;
			case 0:
				if(starta==a)
					done=1;
				else
				{
					sum=a->coeff+b->coeff;
					if(sum)
						attach(sum,a->exp,&rear);
					a=a->link;
					b=b->link;
				}
		}
	}
	rear->link=c;
	return c;
}

void disp(polyptr p)
{
	polyptr temp=p;
	temp=temp->link;
	while(temp!=p)
	{
		printf("%dx^%d ",temp->coeff,temp->exp);
		if(temp->link!=p)
			printf(" + ");
		temp=temp->link;
	}
}

void read(polyptr *p)
{
	polyptr r;
	int n,c,e,i;
	r=(polyptr)malloc(sizeof(polyptr*));
	r->exp=-1;
	*p=r;
	
	printf("\nEnter no. of terms: ");
	scanf("%d",&n);
	printf("\nEnter coeff and exp of -");
	for(i=0;i<n;i++)
	{
		printf("\nTerm %d: ",i+1);
		scanf("%d%d",&c,&e);
		attach(c,e,&r);
	}
	r->link=(*p);	
}

int main()
{
	polyptr a,b,c;
	
	printf("\nPoly a: ");
	read(&a);
	printf("\nPoly b: ");
	read(&b);
	
	c=add(a,b);
	
	printf("\nPoly a: \n");
	disp(a);
	printf("\nPoly b: \n");
	disp(b);
	printf("\nAddition: \n");
	disp(c);
	
	return 0;
}
