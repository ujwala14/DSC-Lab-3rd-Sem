/*Write a C program to perform pattern matching using KMP Algorithm. 
(Print the failure function of a pattern and display whether match 
is found or not).*/

#include<stdio.h>
#include<string.h>
#define max 20

int f[max];

void fail(char *pat)
{
	int i,j;
	f[0]=-1;
	for(i=1;i<strlen(pat);i++)
	{
		j=f[i-1];
		while((pat[i]!=pat[j+1])&&(j!=-1))
			j=f[j];
		if(pat[i]==pat[j+1])
			f[i]=j+1;
		else
			f[i]=-1;
	}
}

int kmp_find(char *str,char *pat)
{
	int i=0,j=0,lp=strlen(pat),ls=strlen(str);
	while(j<lp && i<ls)
	{
		if(str[i]==pat[j])
		{
			i++;j++;
		}
		else if(j==0)
			i++;
		else
			j=f[j-1]+1;
	}
	if(j==lp)
		return (i-lp);
	else
		return -1;
}

int main()
{
	char pat[max],str[max];
	int i,res;
	
	printf("\nEnter the string: ");
//	scanf("%s",str);
	gets(str);
	printf("\nEnter the pattern: ");
//	scanf("%s",pat);
	gets(pat);
	
	fail(pat);
	//failure array display
	printf("\nThe failure array:\n");
	for(i=0;i<strlen(pat);i++)
		printf("%d\t",f[i]);
	
	res=kmp_find(str,pat);
	if(res==-1)
		printf("\nNot found!");
	else
		printf("\nFound at %d pos",res+1);
}
