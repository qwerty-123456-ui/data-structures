#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)==(y)?0:((x)>(y)?1:-1))
typedef struct 
{
	float c;
	int e;
}poly;
poly t[100];
int a=0;
void attach(float coef,int exp)
{
	if(a>=100)
	{
		printf("array full\n");
		exit(1);
	}
	t[a].c=coef;
	t[a++].e=exp;
}
void padd(int sa,int fa,int sb,int fb,int *sd,int *fd)
{
	*sd=a;
	while(sa<=fa && sb<=fb)
	{ printf("%d\t",temp->data.key);
		switch(COMPARE(t[sa].e,t[sb].e))
		{
			case 1:attach(t[sa].c,t[sa].e);
			       sa++;
			       break;
			case -1:attach(t[sb].c,t[sb].e);
                               sb++;
                               break;
			case 0:attach(t[sa].c+t[sb].c,t[sa].e);
                               sa++;
			       sb++;
                               break;
		}
	}
	for(;sa<=fa;sa++)
		attach(t[sa].c,t[sa].e);
	for(;sb<=fb;sb++)
                attach(t[sb].c,t[sb].e);
	*fd=a-1;
}
void main()
{
	int i,ex,n;
	float co;
	int sa,fa,sb,fb,sd,fd;
	printf("Enter no of terms in A\n");
	scanf("%d",&n);
	sa=0;
	for(i=0;i<n;i++)
	{
		printf("Enter coef and exp\n");
		scanf("%f%d",&co,&ex);
		attach(co,ex);
	}
	fa=a-1;
	printf("Enter no of terms in B\n");
        scanf("%d",&n);
	sb=a;
        for(i=0;i<n;i++)
        {
                printf("Enter coef and exp\n");
                scanf("%f%d",&co,&ex);
                attach(co,ex);
        }
        fb=a-1;
	padd(sa,fa,sb,fb,&sd,&fd);
	printf("poly a\n");
	for(;sa<fa;sa++)
		printf("%0.0fx^%d+",t[sa].c,t[sa].e);
	 printf("%0.0fx^%d",t[sa].c,t[sa].e);
	 printf("poly b\n");
        for(;sb<fb;sb++)
                printf("%0.0fx^%d+",t[sb].c,t[sb].e);
         printf("%0.0fx^%d",t[sb].c,t[sb].e);
	 printf("poly sum\n");
        for(;sd<fd;sd++)
                printf("%0.0fx^%d+",t[sd].c,t[sd].e);
         printf("%0.0fx^%d",t[sd].c,t[sd].e);
}

