#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
        struct node *link;
        int vertex;
}node;
node *G[20];
node *front,*rear;
int n,visited[20];
/*void addq(int i)
{
        node *p;
        p=(node *)malloc(sizeof(struct node));
        p->vertex=i;
        p->link=NULL;
        if(front)
                rear->link=p;
        else
                front=p;
        rear=p;
}
int deleteq()
{
        node *temp;
        int a;
                temp=front;
                front=front->link;
                a=temp->vertex;
                return a;
}*/
void insert(int vi,int vj)
{
        node *p,*q,*r;
        q=(node *)malloc(sizeof(struct node));
        q->vertex=vj;
        q->link=NULL;
        if(G[vi]==NULL)
                G[vi]=q;
        else
        {
                for(p=G[vi];p->link!=NULL;p=p->link);
                p->link=q;
        }
        r=(node *)malloc(sizeof(struct node));
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
        int ne,vi,i,vj;
        printf("Enter verices\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
                G[i]=NULL;
        printf("Enter no of edges\n");
        scanf("%d",&ne);
        for(i=0;i<ne;i++)
        {
                printf("enter edge [u,v]\n");
                scanf("%d%d",&vi,&vj);
                insert(vi,vj);
        }
}
void bfs(int i)
{
        node *p;
        printf("%5d",i);
        visited[i]=1;
        //addq(i);
        //while(front)
        //{
          //      i=deleteq();
                for(p=G[i];p;p=p->link)
                {
                        if(!visited[p->vertex])
                        {
				bfs(p->vertex);
            //            printf("%5d",p->vertex);
              //          visited[p->vertex]=1;
                //        addq(p->vertex);
                        }
                }
        //}
       // printf("\n");
}
void main()
{
        //front=rear=NULL;
        read();
        for(int i=0;i<n;i++)
                visited[i]=0;
        printf("dfs is\n");
        bfs(0);
}

