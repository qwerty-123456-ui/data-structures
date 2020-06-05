#include<stdio.h>
#define MAXTERMS 100
typedef struct
{
	int r;
	int c;
	int value;
}spr;
spr a[MAXTERMS],b[MAXTERMS];
void scanspr(spr m[])
{
	int x,count=1,i,j;
	printf("Enter no. of rows and columns \n");
	scanf("%d%d",&a[0].r,&a[0].c);
	printf("Enter the elements \n");
	for(i=0;i<a[0].r;i++)
		for(j=0;j<m[0].c;j++)
		{
			scanf("%d",&x);
			if(x != 0)
			{
				m[count].value=x;
				m[count].r=i;
				m[count++].c=j;
			}
		}
			m[0].value=--count;
			if(count==0)
				printf("It is a zero matrix\n");
		
}
void printspr(spr m[])
{
	int i;
	printf("ROW\t\tCOLUMNS\t\tVALUE\n");
	for(i=0;i<=m[0].value;i++)
		printf("%d\t\t %d\t\t%d \t\t\n",m[i].r,m[i].c,m[i].value);
}

void fastt(spr a[],spr b[])
{
	int rowterms[MAXTERMS],sp[MAXTERMS];
	int i,j,numterms=a[0].value;
	int numcols=a[0].c;
	b[0].r=numcols;
	b[0].c=a[0].r;
	b[0].value=numterms;
	if(numterms>0)
	{
		for(i=0;i<numcols;i++)
			rowterms[i]=0;
		for(i=1;i<=numterms;i++)
			rowterms[a[i].c]++;
		sp[0]=1;
		for(i=1;i<numcols;i++)
			sp[i]=sp[i-1]+rowterms[i-1];
		for(i=1;i<=numterms;i++)
		{
			j=sp[a[i].c]++;
			b[j].r=a[i].c;
			b[j].c=a[i].r;
			b[j].value=a[i].value;
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




