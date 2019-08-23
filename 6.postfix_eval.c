/*Write a C program to evaluate a given postfix expression using a stack.*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 20

typedef enum{
	plus,minus,divi,into,mod,eos,opd
}prcd;

int stack[max];
int top=-1;
char expr[max];

void push(int x)
{
	stack[++top]=x;
}
int pop()
{
	return stack[top--];
}

prcd get_tok(char *s,int *n)
{
	*s=expr[(*n)++];
	switch(*s)
	{
		case '+':	return plus;
		case '-':	return minus;
		case '/':	return divi;
		case '*':	return into;
		case '%':	return mod;
		case '\0':	return eos;
		default:	if(isdigit(*s))
						return opd;
					printf("\nInvalid symbol!Aborting!!");
					exit(0);
	}
}

int eval()
{
	char sym;
	int n=0,op1,op2;
	prcd token;
	
	for(token=get_tok(&sym,&n); token!=eos; token=get_tok(&sym,&n))
	{
		if(token==opd)
			push(sym-'0');
		else
		{
			op2=pop();
			op1=pop();
			switch(token)
			{
				case plus:	push(op1+op2); break;
				case minus:	push(op1-op2); break;
				case divi:	push(op1/op2); break;
				case into:	push(op1*op2); break;
				case mod:	push(op1%op2); break;
			}
		}
	}
	return pop();
}

int main()
{
	printf("\nEnter the postfix expr: ");
	scanf("%s",expr);
	printf("\nThe value: %d",eval());
	return 0;
}
