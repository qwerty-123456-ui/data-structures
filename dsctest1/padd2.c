#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)>(y) ?1:((x)==(y)?0:-1))
typedef struct
{
	float coef;
	int expon;
}poly;
poly terms[100];
int avail=0;
void attach(float c,int e)
{
	if(avail>=100)
	{
		printf("Array full\n");
		exit(0);
	}
		terms[avail].coef=c;
		terms[avail++].expon=e;
}
void padd(int sa,int fa,int sb,int fb,int *sd,int *fd)
{
	*sd=avail;
	while(sa<=fa && sb<=fb)
	{
		switch(COMPARE(terms[sa].expon,terms[sb].expon))
		{
			case 1:attach(terms[sa].coef,terms[sa].expon);
			       sa++;
			       break;
		        case 0:attach(terms[sa].coef+terms[sb].coef,terms[sa].expon);
                               sa++;
			       sb++;
                               break;
                        case -1:attach(terms[sb].coef,terms[sb].expon);
                               sb++;
                               break;
		}
	}
	for(;sa<=fa;sa++)
		attach(terms[sa].coef,terms[sa].expon);
	for(;sb<=fb;sb++)
                attach(terms[sb].coef,terms[sb].expon);
	*fd=avail-1;
}
void main()
{
	int sa,sb,fa,fb,fd,sd,n,i,e;
	float c;
	printf("How many terms in polynomial A\n");
	scanf("%d",&n);
	for(sa=0,i=0;i<n;i++)
	{
		printf("Enter coefficient  and exponent\n");
		scanf("%f%d",&c,&e);
		attach(c,e);
	}
	fa=avail-1;
	printf("How many terms in polynomial B\n");
        scanf("%d",&n);
        for(sb=avail,i=0;i<n;i++)
        {
                printf("Enter coefficient  and exponent\n");
                scanf("%f%d",&c,&e);
		attach(c,e);
        }
        fb=avail-1;
	padd(sa,fa,sb,fb,&sd,&fd);
	printf("POlynomial A \n");
	for(;sa<fa;sa++)
	printf("%0.0fx^%d+",terms[sa].coef,terms[sa].expon);
      	printf("%0.0fx^%d",terms[sa].coef,terms[sa].expon);
	printf("\n");
	 printf("POlynomial B \n");
        for(;sb<fb;sb++)
        printf("%0.0fx^%d+",terms[sb].coef,terms[sb].expon);
        printf("%0.0fx^%d",terms[sb].coef,terms[sb].expon);
	printf("\n");
        printf(" SUM POlynomial  \n");
        for(;sd<fd;sd++)
        printf("%0.0fx^%d+",terms[sd].coef,terms[sd].expon);
        printf("%0.0fx^%d",terms[sd].coef,terms[sd].expon);
	printf("\n");
}

        





