/*Write a C program to convert a given infix expression to a 
postfix expression using a stack.*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define max 20

typedef enum{
	lp,rp,plus,minus,divi,into,mod,eos,opd
}prcd;
prcd stack[max];
int top=-1;
char expr[max];
char chop[]="()+-/*%";
int isp[]={0,9,12,12,13,13,13,0};
int icp[]={20,9,12,12,13,13,13,0};

void push(prcd x)
{
	stack[++top]=x;
}
prcd pop()
{
	return stack[top--];
}

prcd get_tok(char *s,int *n)
{
	*s=expr[(*n)++];
	switch(*s)
	{
		case '(':	return lp;
		case ')':	return rp;
		case '+':	return plus;
		case '-':	return minus;
		case '/':	return divi;
		case '*':	return into;
		case '%':	return mod;
		case '\0':	return eos;
		default:	if(isdigit(*s))
						return opd;
					printf("\nInvalid symbol!");
					exit(0);
	}
}

void in_post()
{
	prcd token;
	char sym;
	int n=0;
	push(eos);
	
	for(token=get_tok(&sym,&n); token!=eos; token=get_tok(&sym,&n))
	{
		if(token==opd)
			printf("%c",sym);
		else if(token==rp)
		{
			while(stack[top]!=lp)
				printf("%c",chop[pop()]);
			pop();
		}
		else
		{
			while(icp[token] <= isp[stack[top]])
				printf("%c",chop[pop()]);
			push(token);
		}
	}
	
	for(token=pop(); token!=eos; token=pop())
		printf("%c",chop[token]);
}

int main()
{
	printf("\nEnter the infix expr: ");
	scanf("%s",expr);
	printf("\nThe equivalent postfix expr: ");
	in_post();
	return 0;
}
