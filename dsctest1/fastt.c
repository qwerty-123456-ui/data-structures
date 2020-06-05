#include<stdio.h>
#include<stdlib.h>
#define MAXT 100
typedef struct 
{
	int r;
	int c;
	int v;
}spr;
spr a[MAXT],b[MAXT];
void scanspr(spr m[])
{
	int count=1,i,j,x;
	printf("Enter the no. of rows and columns \n");
	scanf("%d%d",&m[0].r,&m[0].c);
	printf("Enter the elements\n");
	for(i=0;i<m[0].r;i++)
	{
		for(j=0;j<m[0].c;j++)
		{
			scanf("%d",&x);
			if(x != 0)
			{
				m[count].r=i;
				m[count].v=x;
				m[count++].c=j;
			}
		}
	}
	m[0].v=--count;
	if(count ==0)
		printf("IT is a zero matrix \n");
}
void printspr(spr m[])
{
	int i;
	printf("ROW\t\tCOLUMN\t\tVALUE\n");
	for(i=0;i<=m[0].v;i++)
		printf("%d\t\t %d\t\t %d\n",m[i].r,m[i].c,m[i].v);
	//printf("\n");
}
void fastt(spr a[],spr b[])
{
	int i,j;
	int rt[MAXT],sp[MAXT];
	int numt,numcols;
	numt=a[0].v;
	numcols=a[0].c;
	b[0].r=numcols;
	b[0].v=numt;
	b[0].c=a[0].r;
	for(i=0;i<numcols;i++)
		rt[i]=0;
	for(i=1;i<=numt;i++)
		rt[a[i].c]++;
	sp[0]=1;
	for(i=1;i<numcols;i++)
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



