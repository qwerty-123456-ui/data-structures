#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)>(y)?1:((x)==(y)?0:-1))
typedef struct 
{
	float coef;
	int exp;
}poly;
poly terms[100];
int avail=0;
void attach(float c,int e)
{
	if(avail>=100)
	{
		printf("array full\n");
		exit(1);
	}
	terms[avail].coef=c;
	terms[avail++].exp=e;
}
void padd(int sa,int fa,int sb,int fb,int *sd,int *fd)
{
	*sd=avail;
	while(sa<=fa && sb<=fb)
	{
		switch(COMPARE(terms[sa].exp,terms[sb].exp))
		{
			case 1:attach(terms[sa].coef,terms[sa].exp);
			       sa++;
			       break;
			case -1:attach(terms[sb].coef,terms[sb].exp);
                               sb++;
                               break;
			case 0:attach(terms[sa].coef+terms[sb].coef,terms[sa].exp);
                               sa++;sb++;
                               break;
		}
	}
	for(;sa<=fa;sa++)
		attach(terms[sa].coef,terms[sa].exp);
	for(;sb<=fb;sb++)
                attach(terms[sb].coef,terms[sb].exp);
	*fd=avail-1;
}
void main()
{
	int sa,sb,fa,fb,fd,sd;
	int n,i,c,e;
	printf("ENTER NO OF TERMS IN A\n");
	scanf("%d",&n);
	sa=0;
	for(i=0;i<n;i++)
	{
		printf("Enter the coef and exp\n");
		scanf("%d%d",&c,&e);
		attach(c,e);
	}
	fa=avail-1;
	 printf("ENTER NO OF TERMS IN B\n");
        scanf("%d",&n);
        sb=avail;
        for(i=0;i<n;i++)
        {
                printf("Enter the coef and exp\n");
                scanf("%d%d",&c,&e);
                attach(c,e);
        }
        fb=avail-1;
	padd(sa,fa,sb,fb,&sd,&fd);
	printf("pOLY AIS \n");
	for(;sa<fa;sa++)
		printf("%0.0fx^%d+",terms[sa].coef,terms[sa].exp);
	 printf("%0.0fx^%d\n",terms[sa].coef,terms[sa].exp);
	 for(;sb<fb;sb++)
                printf("%0.0fx^%d+",terms[sb].coef,terms[sb].exp);
         printf("%0.0fx^%d\n",terms[sb].coef,terms[sb].exp);
	 for(;sd<fd;sd++)
                printf("%0.0fx^%d+",terms[sd].coef,terms[sd].exp);
         printf("%0.0fx^%d\n",terms[sd].coef,terms[sd].exp);
}
