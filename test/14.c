#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        struct node *link;
        int vertex;
}node;
node *G[20];
int visited[20];
int n;
node *front,*rear;
void addq(int i)
{
	node  *temp;
	temp=(node *)malloc(sizeof(struct node));
	temp->vertex=i;
	temp->link=NULL;
	if(front)
		rear->link=temp;
	else
		front=temp;
	rear=temp;
}
int deleteq()
{ 
        node *temp;
	int a;
	temp=front;
	a=temp->vertex;
	temp=temp->link;
	front=temp;
	return a;
}

void insert(int vi,int vj)
{
        node *p,*q,*r;
        q=(node *)malloc(sizeof(node));
        q->vertex=vj;
        q->link=NULL;
        if(G[vi]==NULL)
                G[vi]=q;
        else
        {
                for(p=G[vi];p->link!=NULL;p=p->link);
                        p->link=q;
        }
        r=(node *)malloc(sizeof(node));
        r->vertex=vi;
        r->link=NULL;
        if(G[vj]==NULL)
                G[vj]=r;
        else
        {
                for(p=G[vj];p->link!=NULL;p=p->link);
                        p->link=r;
        }
}
void read()
{
        int i,ne,vi,vj;
        printf("Enter no of vertices\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
                visited[i]=0;
        printf("no of edges\n");
        scanf("%d",&ne);
        for(i=0;i<ne;i++)
        {
                printf("edge [u-v]\n");
                scanf("%d%d",&vi,&vj);
                insert(vi,vj);
        }
}
void bfs(int i)
{
        node *p;
        visited[i]=1;
        printf("%5d",i);
	addq(i);
	while(front)
	{
		i=deleteq();
        for(p=G[i];p;p=p->link)
        {
                if(!visited[p->vertex])
		{
                        printf("%5d",p->vertex);
			visited[p->vertex]=1;
			addq(p->vertex);
		}
        }
	}
}
void main()
{
        int i;
        for(i=0;i<20;i++)
                G[i]=NULL;
        read();
        printf("bfs order\n");
        bfs(0);
}

