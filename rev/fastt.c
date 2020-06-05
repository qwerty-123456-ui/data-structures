#include<stdio.h>
typedef struct 
{
	int r,v,c;
}spr;
spr a[100],b[100];
void scanspr(spr m[])
{
	int i,j,c=1,n;
	printf("Enter no of rows and cols \n");
	scanf("%d%d",&m[0].r,&m[0].c);
	for(i=0;i<m[0].r;i++)
		for(j=0;j<m[0].c;j++)
		{
			printf("enter elements\n");
			scanf("%d",&n);
			if(n!=0)
			{
				m[c].r=i;
				m[c].c=j;
				m[c++].v=n;
			}
		}
	m[0].v=--c;
	if(c==0)
		printf("zero matrix\n");
}
void printspr(spr m[])
{
	int i;
	printf("ROW \t\t COLUMN \t\t VALUE\n");
	for(i=0;i<=m[0].v;i++)
		printf("%d\t\t%d\t\t%d\n",m[i].r,m[i].c,m[i].v);
}
void fastt(spr a[],spr b[])
{
	int rt[100],sp[100],i,j,nt,nc;
	b[0].r=nc=a[0].c;
	b[0].v=nt=a[0].v;
	b[0].c=a[0].r;
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
void main()
{
	scanspr(a);
	printspr(a);
	fastt(a,b);
	printspr(b);
}

