#include<stdio.h>
#include<stdlib.h>
#define MAX_TERMS 100
typedef struct
{
	float coef;
	int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

int compare(int a, int b)
{
	return (a>b? 1 : ((a<b)? -1 :0));
}

void attach(float c, int e)
{
	if(avail >= MAX_TERMS)
	{
		printf("array full\n");
		exit(1);
	}
	terms[avail].coef = c;
	terms[avail++].expon = e;
}

void padd(int startA, int finishA, int startB, int finishB, int *startD, int *finishD)
{
	*startD = avail;
	while(startA <= finishA && startB <= finishB)
	{
		switch(compare(terms[startA].expon, terms[startB].expon))
		{
			case -1: attach(terms[startB].coef, terms[startB].expon);
					  startB++;
					  break;

			case 1: attach(terms[startA].coef, terms[startA].expon);
					  startA++;
					  break;
  			case 0: attach(terms[startA].coef+terms[startB].coef, terms[startB].expon);
					  startA++;
					  startB++;
					  break;
		}
	}
	
	for(;startA <= finishA; startA++)
		attach(terms[startA].coef, terms[startA].expon);
	
	for(;startB <= finishB; startB++)
		attach(terms[startB].coef, terms[startB].expon);

	*finishD= avail;
}

int main()
{
	int startA, finishA, startB, finishB, startD, finishD;
	int n,i,e;
	float c;
	printf("How many terms in polynomial A\n");
	scanf("%d",&n);
	for(startA=0,i=0;i<n;i++)
	{
		printf("enter the coef & exponent\n");
		scanf("%f%d", &c, &e);
		attach(c,e);
	}
	finishA= avail -1;
	
	printf("How many terms in polynomial B\n");
	scanf("%d",&n);
	for(startB=avail,i=0;i<n;i++)
	{
		printf("enter the coef & exponent\n");
		scanf("%f%d", &c, &e);
		attach(c,e);
	}
	finishB= avail -1;	

	padd(startA, finishA, startB, finishB, &startD, &finishD);
	
	printf("\nPolynomial A is:\n");
	
	for(;startA <= finishA; startA++)
		printf("%.0f *x%d + ",terms[startA].coef, terms[startA].expon);

	printf("\nPolynomial B is:\n");
	
	for(;startB <= finishB; startB++)
		printf("%.0f *x%d + ",terms[startB].coef, terms[startB].expon);

	printf("\nSum Polynomial is:\n");
	
	for(;startD <= finishD; startD++)
		printf("%.0f *x%d + ",terms[startD].coef, terms[startD].expon);

	return 0;
}


