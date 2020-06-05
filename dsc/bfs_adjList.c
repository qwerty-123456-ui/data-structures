#include<stdio.h>
#include<stdlib.h>
 
#define TRUE 1
#define FALSE 0

typedef struct node
{
    struct node *link;
    int vertex;
}node;
 
node *G[20];   
node *front, *rear;
	
int visited[20];
int n;
 
void addq(int v)
{ 
	node* temp, *ptr;
	temp=(node*)malloc(sizeof(node));
	temp->link=NULL;
	temp->vertex=v;
	if(front==NULL)
		front=temp;
	else
		rear->link=temp;
	rear=temp;
}

int deleteq()
{ 
	int a;
	node* temp=front;
	a=temp->vertex;
	temp=temp->link;
	front=temp;
	return a;
}

void BFS(int v)
{
    node *p;
	printf("\n%5d",v);
    visited[v]=TRUE;
	addq(v);
	while(front)
	{
		v=deleteq();
		for(p=G[v];p; p=p->link)
    	{
       	   if(!visited[p->vertex])
			{
				printf("%5d",p->vertex);
            	addq(p->vertex); 
				visited[p->vertex] = TRUE;
			}
   		}
	}
	printf("\n");
}
 
void insert(int vi,int vj)
{
    node *p,*q;
    q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->link=NULL;
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {   for(p=G[vi];p->link!=NULL; p=p->link);
        p->link=q;
    }
}

void read_graph()
{
    int i,vi,vj,no_of_edges;
    printf("Enter number of vertices:");
   	scanf("%d",&n);
 
	for(i=0;i<n;i++)
        G[i]=NULL;
    printf("Enter number of edges \n");
    scanf("%d",&no_of_edges);
    for(i=0;i<no_of_edges;i++)
    {
        printf("Enter an edge(u,v):");
		scanf("%d%d",&vi,&vj);
		insert(vi,vj);
    }
}
 
int main()
{
    int i;
	front = rear= NULL;
    read_graph();
   	for(i=0;i<n;i++)
        visited[i]=FALSE;
	printf("\n\nNodes visited in BFS order\n");
    BFS(0);
	return 0;
}
