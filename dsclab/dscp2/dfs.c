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

int visited[20];
int n;
 
void insert(int vi,int vj)
{
    node *p,*q,*r;
   	q=(node*)malloc(sizeof(node));
    q->vertex=vj;
    q->link=NULL;
    if(G[vi]==NULL)
        G[vi]=q;
    else
    {   for(p=G[vi];p->link!=NULL; p=p->link);
        p->link=q;
    }
    r=(node*)malloc(sizeof(node));
    r->vertex=vi;
    r->link=NULL;
    if(G[vj]==NULL)
        G[vj]=r;
    else
    {   for(p=G[vj];p->link!=NULL; p=p->link);
        p->link=r;
    }
}
void displayAdjList()
{
        int i;
        node * x;
        for(i=0; i<n; i++)
        {
                printf("%d\t",i);
                x=G[i];
                for(;x;x=x->link)
                {
                        printf("%d\t",x->vertex);
                }
                printf("\n");

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
 
void DFS(int i)
{
    node *p;
    visited[i]=TRUE;
      printf("%5d",i);
    for(p=G[i];p; p=p->link)
    {
       	   if(!visited[p->vertex])
            DFS(p->vertex); 
    }
}
 
int main()
{
    int i;
    read_graph();
    displayAdjList();
    for(i=0;i<n;i++)
        visited[i]=FALSE;
	printf("\nNodes visited in DFS order\n");
    DFS(0);
	printf("\n");
	return 0;
}
