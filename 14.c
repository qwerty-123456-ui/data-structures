#include<stdio.h>
#include<stdlib.h>
#define true 1
#define false 0
typedef struct node
{
       	 struct node *link;
	int vertex;
}node;

node *G[20];
node *front,*rear;
int visited[20];
int n;
void addq(int i)
{
	node *temp;
	temp=(node *)malloc(sizeof(struct node));
	temp->vertex=i;
	if(front)
		rear->link=temp;
	else
		front=temp;
	rear=temp;
} 
int  deleteq()
{
	int a;
	node *temp;
	temp=front;
	a=temp->vertex;
	temp=temp->link;
	front=temp;
	return a;
}
void insert(int vi,int vj)
{
	node *p,*q,*r;
	q=(node *)malloc(sizeof(struct node));
	q->vertex=vj;
	if(G[vi]==NULL)
		G[vi]=q;
	else
	{
		for(p=G[vi];p->link!=NULL;p=p->link);
		p->link=q;
	}
	r=(node *)malloc(sizeof(struct node));
        r->vertex=vi;
        if(G[vj]==NULL)
                G[vj]=r;
        else
        {
                for(p=G[vj];p->link!=NULL;p=p->link);
                p->link=r;
	}
}
void bfs(int i)
{
	node *p;
	printf("%5d",i);
	visited[i]=true;
	addq(i);
	while(front)
	{
		i=deleteq();
		for(p=G[i];p;p=p->link)
		{
			if(!visited[p->vertex])
			{
				printf("%5d",p->vertex);
				visited[p->vertex]=true;
				addq(p->vertex);
			}
		}
	}
	printf("\n");
}
void readgraph()
{
	int ne,i,vi,vj;
	printf("enter the no.of vertices\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		G[i]=NULL;
	printf("Enetr the no of edges\n");
	scanf("%d",&ne);
	for(i=0;i<ne;i++)
	{
		printf("Enetr the edge[u-v]");
		scanf("%d%d",&vi,&vj);
		insert(vi,vj);
	}
}
void main()
{
	int i;
	readgraph();
	for(i=0;i<n;i++)
		visited[i]=false;
	printf("bfs si\n");
	bfs(0);
}




