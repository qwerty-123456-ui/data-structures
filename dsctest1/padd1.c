#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)>(y)?1:((x)==(y)?0:-1))
#define MAXSIZE 100
typedef struct
{
	float coef;
	int expon;
}poly;
poly terms[MAXSIZE];
int avail=0;
void attach(float c, int e)
{
	if(avail>MAXSIZE-1)
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
	switch(COMPARE(terms[sa].expon,terms[sb].expon))
	{
		case 1:attach(terms[sa].coef,terms[sa].expon);
		       sa++;
		       break;
		case -1:attach(terms[sb].coef,terms[sb].expon);
                       sb++;
                       break;
                case 0:attach(terms[sa].coef+terms[sb].coef,terms[sa].expon);
                       sa++;
		       sb++;
                       break;
	}
	for(;sa<=fa;sa++)
		attach(terms[sa].coef,terms[sa].expon);
	for(;sb<=fb;sb++)
                attach(terms[sb].coef,terms[sb].expon);

	*fd=avail-1;
}
void main()
{
	int n,e,i;
	float c;
	int sa,sb,fa,fb,sd,fd;
	printf("How many terms in polynomial A\n");
	scanf("%d",&n);
	for(sa=0,i=0;i<n;i++)
	{
		printf("Enter the exponent and coefficient\n");
		scanf("%f%d",&c,&e);
		attach(c,e);
	}
	fa=avail-1;
	printf("How many terms in polynomial B\n");
        scanf("%d",&n);
        for(sb=avail,i=0;i<n;i++)
        {
                printf("Enter the exponent and coefficient\n");
                scanf("%f%d",&c,&e);
                attach(c,e);
        }
        fb=avail-1;
	padd(sa,fa,sb,fb,&sd,&fd);
	printf("Polynomial A is \n");
	for(;sa<=fa;sa++)
		printf("%.0fx^%d +",terms[sa].coef,terms[sa].expon);
	printf("\n");
	printf("Polynomial B is \n");
        for(;sb<=fb;sb++)
                printf("%.0fx^%d +",terms[sb].coef,terms[sb].expon);
	printf("\n");
        printf("Sum of 2 Polynomials A and  B  is \n");
        for(;sd<=fd;sd++)
                printf("%.0fx^%d +",terms[sd].coef,terms[sd].expon);
	printf("\n");
}





