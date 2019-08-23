/*Write a C program to perform breadth first search of a graph 
represented as an adjacency list.*/

#include<stdio.h>
#include<stdlib.h>
#define maxv 20
#define T 1
#define F 0

struct node
{
	int vertex;
	struct node* link;
};
typedef struct node* nodeptr;
nodeptr graph[maxv];
short int visited[maxv];
nodeptr f=NULL,r=NULL;

void attach(int u,int v)
{
	nodeptr temp,cur;
	temp=(nodeptr)malloc(sizeof(nodeptr*));
	temp->vertex=v;
	temp->link=NULL;
	
	if(!graph[u])
		graph[u]=temp;
	else
	{
		cur=graph[u];
		while(cur->link!=NULL)
			cur=cur->link;
		cur->link=temp;
	}
	printf("\nattached : %d,%d",u,v);
}

void addq(int v)
{
	nodeptr temp;
	temp=(nodeptr)malloc(sizeof(nodeptr*));
	temp->vertex=v;
	temp->link=NULL;
	if(!f)
		f=temp;
	else
		r->link=temp;
	r=temp;
}

int delq()
{
	nodeptr temp;
	int x;
	if(!f)
		return -1;
	temp=f;
	f=f->link;
	x=temp->vertex;
	free(temp);
	return x;
}

void bfs(int v)
{
	nodeptr w;
	visited[v]=T;
	printf("%d\t",v);
	addq(v);
	while(f)
	{
		v=delq();
		for(w=graph[v]; w; w=w->link)
		{
			if(!visited[w->vertex])
			{
				printf("%d\t",w->vertex);
				visited[w->vertex]=T;
				addq(w->vertex);
			}
		}
	}
}

int main()
{
	int ne,nv,u,v,start,i;
	nodeptr w;
	
	printf("\nEnter no.of vertices: ");
	scanf("%d",&nv);
	printf("\nEnter no. of edges(undirected): ");
	scanf("%d",&ne);
	
	for(i=0;i<nv;i++)
	{
		graph[i]=NULL;
		visited[i]=F;
	}
	
	printf("\nEnter the edges(start & end vertices)- ");
	for(i=0;i<ne;i++)
	{
		printf("\nEdge %d: ",i+1);
		scanf("%d%d",&u,&v);
		attach(u,v);
		attach(v,u);
	}
	
	printf("\nAdjacency list representation: ");
	for(i=0;i<nv;i++)
	{
		printf("\nGraph[%d]:\t",i);
		for(w=graph[i]; w; w=w->link)
			printf("%d\t",w->vertex);
	}
	
	printf("\nEnter start vertex: ");
	scanf("%d",&start);
	printf("\nBFS:\n");
	bfs(start);
	
	return 0;
}
