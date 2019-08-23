/*Write a C program to input a sparse  matrix and  
find its fast transpose. */

#include<stdio.h>
#include<stdlib.h>
#define max 20

typedef struct
{
	int row,col,val;
}matrix;

void fast_trans(matrix a[],matrix b[])
{
	int rt[max],sp[max],i,j;
	int nc=a[0].col, nt=a[0].val;
	b[0].row = nc;
	b[0].col = a[0].row;
	b[0].val = nt;
	if(nt>0)
	{	
		for(i=0;i<nc;i++)
			rt[i]=0;
		for(i=1;i<=nt;i++)
			rt[a[i].col]++;
		sp[0]=1;
		for(i=1;i<nc;i++)
			sp[i]=sp[i-1]+rt[i-1];
		for(i=1;i<=nt;i++)
		{
			j=sp[a[i].col]++;
			b[j].row=a[i].col;
			b[j].col=a[i].row;
			b[j].val=a[i].val;
		}
	}
}

void disp(matrix x[])
{
	int i;
	printf("\nROW\tCOL\tVALUE");
	for(i=0;i<=x[0].val;i++)
		printf("\n%d\t%d\t%d",x[i].row,x[i].col,x[i].val);
}
int main()
{
	matrix a[max],b[max];
	int n,i;
	
	printf("\nMatrix a:\nEnter no. of rows and cols: ");
	scanf("%d%d",&a[0].row,&a[0].col);
	printf("\nEnter no.of non-zero elements: ");
	scanf("%d",&a[0].val);
	
	printf("\nEnter row,col & value - ");
	for(i=1;i<=a[0].val;i++)
	{
		printf("\nElement %d: ",i);
		scanf("%d%d%d",&a[i].row,&a[i].col,&a[i].val);
	}
	
	fast_trans(a,b);
	printf("\nMatrix A: ");
	disp(a);
	printf("\nFast transpose: ");
	disp(b);
	
	return 0;
}
