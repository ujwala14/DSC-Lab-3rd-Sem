/*Write a C program to perform addition of two polynomials 
using an array.(Represent both polynomials as well as the 
resultant polynomial in a single array. Display both polynomials 
and the resultant polynomial after addition).*/

#include<stdio.h>
#include<stdlib.h>
#define max 20
#define COMPARE(x,y) (((x)>(y))?1:(((x)==(y))?0:(-1)))

typedef struct
{
	int coeff,exp;
}poly;
poly terms[max];
int avail=0;

void attach(int c,int e)
{
	terms[avail].coeff=c;
	terms[avail].exp=e;
	avail++;
}

void add(int sa,int fa,int sb,int fb,int *sc,int *fc)
{
	int sum;
	*sc=avail;
	while(sa<=fa && sb<=fb)
	{
		switch(COMPARE(terms[sa].exp,terms[sb].exp))
		{
			case 1:
				attach(terms[sa].coeff,terms[sa].exp);
				sa++; break;
			case -1:
				attach(terms[sb].coeff,terms[sb].exp);
				sb++; break;
			case 0:
				sum=terms[sa].coeff+terms[sb].coeff;
				if(sum)
					attach(sum,terms[sa].exp);
				sa++; sb++; break;
		}	
	}	
	
	//extra terms
	for(;sa<=fa;sa++)
		attach(terms[sa].coeff,terms[sa].exp);
	for(;sb<=fb;sb++)
		attach(terms[sb].coeff,terms[sb].exp);
	
	*fc=avail-1;
}

void disp(int s,int f)
{
	int i;
	for(i=s;i<=f;i++)
	{
		printf("%dx^%d ",terms[i].coeff,terms[i].exp);
		if(i!=f)
			printf(" + ");
	}
}

void read(int *s,int *f)
{
	int i,n,c,e;
	*s=avail;
	printf("\nEnter no. of terms: ");
	scanf("%d",&n);
	printf("\nEnter coeff & exp of-");
	for(i=0;i<n;i++)
	{
		printf("\nTerm %d: ",i+1);
		scanf("%d%d",&c,&e);
		attach(c,e);
	}
	*f=avail-1;
}

int main()
{
	int sa,sb,sc,fa,fb,fc;
	
	printf("\nPoly a: ");
	read(&sa,&fa);
	
	printf("\nPoly b: ");
	read(&sb,&fb);
	
	add(sa,fa,sb,fb,&sc,&fc);
	
	printf("\nPoly a:\n"); 		disp(sa,fa);
	printf("\nPoly b:\n"); 		disp(sb,fb);
	printf("\nAddition:\n");	disp(sc,fc);
	
	return 0;
}

