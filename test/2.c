#include<stdio.h>
#include<stdlib.h>
typedef struct spr
{
	int r;
	int c;
	int v;
}spr;
spr a[100],b[100];
void scanspr(spr m[])
{
	int x,i,j,count=1;
	printf("Enter no of rows and cols\n");
	scanf("%d%d",&m[0].r,&m[0].c);
	for(i=0;i<m[0].r;i++)
	{
		for(j=0;j<m[0].c;j++)
		{
			printf("Enter valuse\n");
			scanf("%d",&x);
			if(x != 0)
			{
				m[count].r=i;
				m[count].c=j;
				m[count++].v=x;
			}
		}
	}
	m[0].v=--count;
	if(count==0)
	{
		printf("Zero matric\n");
		exit(1);
	}
}
void printspr(spr m[])
{
	int i,j;
	printf("ROW \t\t COLUMN \t\t VALUE\n");
	for(i=0;i<m[0].v;i++)
		printf("%d\t\t%d\t\t%d\n",m[i].r,m[i].c,m[i].v);
}
void fastt(spr a[],spr b[])
{
	int nt,sp[100],rt[100],nc,i,j;
	b[0].r=nc=a[0].c;
	b[0].c=a[0].r;
	b[0].v=nt=a[0].v;
	if(nt>0)
	{
		for(i=0;i<nc;i++)
			rt[i]=0;
		for(i=1;i<=nt;i++)
			rt[a[i].c]++;
		sp[0]=1;
		for(i=1;i<nc;i++)
			sp[i]=sp[i-1]+rt[i-1];
		for(i=1;i<=nt;i++)
		{
			j=sp[a[i].c]++;
			b[j].r=a[i].c;
			b[j].c=a[i].r;
			b[j].v=a[i].v;
		}
	}
}
void main()
{
	scanspr(a);
	printspr(a);
	fastt(a,b);
	printspr(b);
}
