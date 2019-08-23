/*Write a C program to perform depth first search of a graph 
represented as an adjacency list.*/

#include<stdio.h>
#include<stdlib.h>
#define maxv 30
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

void dfs(int v)
{
	nodeptr w;
	visited[v]=T;
	printf("%d\t",v);
	for(w=graph[v]; w; w=w->link)
		if(!visited[w->vertex])
			dfs(w->vertex);
}
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
		while(cur->link != NULL)
			cur=cur->link;
		cur->link=temp;
	}
//	printf("\nattached: (%d,%d)",u,v);
}

int main()
{
	int ne,nv,u,v,i,start;
	nodeptr w;
	
	printf("\nEnter no. of vertices: ");
	scanf("%d",&nv);
	printf("\nEnter no. of edges(undirected): ");
	scanf("%d",&ne);
	//init graph and visited
	for(i=0;i<nv;i++)
	{
		graph[i]=NULL;
		visited[i]=F;
	}
	
	//input
	printf("\nEnter the edges(start and end vertices): ");
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
		printf("\ngraph[%d]:\t",i);
		for(w=graph[i]; w; w=w->link)
			printf("%d\t",w->vertex);
	}
	
	printf("\n\nEnter start vertex: ");
	scanf("%d",&start);
	printf("\nDFS:\n");
	dfs(start);
	
	return 0;
}
