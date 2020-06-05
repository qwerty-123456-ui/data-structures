#include<stdio.h>
typedef struct
{
	int r;
	int c;
	int v;
}spr;
spr a[100],b[100];
void scanspr(spr m[])
{
	int count=1,x,i,j;
	printf("enter the no. of rows and columns\n");
	scanf("%d%d",&m[0].r,&m[0].c);
	printf("Enter the elements\n");
	for(i=0;i<a[0].r;i++)
		for(j=0;j<a[0].c;j++)
		{
			scanf("%d",&x);
			if(x !=0)
			{
				m[count].v=x;
				m[count].r=i;
				m[count++].c=j;
			}
		}
	m[0].v=--count;
	if(count==0)
		printf("It is A zero matrix\n");
}
void printspr(spr m[])
{
	int i;
	printf("ROW\t\tCOLUMNS\t\tVALUE\n");
	for(i=0;i<=m[0].v;i++)
		printf("%d\t\t %d\t\t %d\t\t\n",m[i].r,m[i].c,m[i].v);
}
void fastt(spr a[],spr b[])
{
	int i,j,numt,numc;
	int rt[100],sp[100];
	numt=a[0].v;
	numc=a[0].c;
	b[0].c=a[0].r;
	b[0].r=a[0].c;
	b[0].v=a[0].v;
	for(i=0;i<numc;i++)
		rt[i]=0;
	for(i=1;i<=numt;i++)
		rt[a[i].c]++;
	sp[0]=1;
	for(i=1;i<numc;i++)
		sp[i]=sp[i-1]+rt[i-1];
	for(i=1;i<=numt;i++)
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

