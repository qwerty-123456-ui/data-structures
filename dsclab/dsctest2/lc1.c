#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define COMPARE(x,y)((x)>(y)?1:((x)==(y)?0:-1))
typedef struct polynode *polyptr;
typedef struct polynode
{
	int exp;
	float coef;
	polyptr link;
}polynode;
polyptr heada,headb,lastc,headc;
void attach(float c,int e,polyptr *ptr)
{
	polyptr temp;
	temp=(polyptr)malloc(sizeof(polynode));
	temp->coef=c;
	temp->exp=e;
	(*ptr)->link=temp;
	*ptr=temp;
}
void cpadd(polyptr a,polyptr b)
{
	polyptr starta;
	int sum,done=FALSE;
	starta=a;
	a=a->link;
	b=b->link;
	headc=(polyptr)malloc(sizeof(polynode));
	headc->exp=-1;
	lastc=headc;
	do
	{
		switch(COMPARE(a->exp,b->exp))
		{
			case -1:attach(b->coef,b->exp,&lastc);
				b=b->link;
				break;
			case 1:attach(a->coef,a->exp,&lastc);
			       a=a->link;
			       break;
			case 0:if(starta ==a)
				       done=TRUE;
			       else
			       {
				       sum=a->coef+b->coef;
				       if(sum)
				       {
					       attach(sum,a->exp,&lastc);
					       a=a->link;
					       b=b->link;
				       }
			       }
			       break;
		}
	}while(!done);
	lastc->link=headc;
}
int main()
{
	polyptr lasta,lastb,start,temp;
	int e,i,n;
	float c;
	heada=(polyptr)malloc(sizeof(polynode));
	headb=(polyptr)malloc(sizeof(polynode));
	heada->exp=-1;
	headb->exp=-1;
	lasta=heada;
	lastb=headb;
	printf("How many terms in poly a\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the coef and exponent \n");
		scanf("%f%d",&c,&e);
		attach(c,e,&lasta);
	}
	lasta->link=heada;
	printf("How many terms in poly b\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter the coef and exponent \n");
                scanf("%f%d",&c,&e);
                attach(c,e,&lastb);
        }
        lastb->link=headb;
	cpadd(heada,headb);
	printf("Polynomial A\n");
	for(start=heada->link;start!=lasta;start=start->link)
		printf("%f x^%d+",start->coef,start->exp);
	printf("%f x^%d\n",start->coef,start->exp);
	printf("Polynomial B\n");
        for(start=headb->link;start!=lastb;start=start->link)
                printf("%f x^%d+",start->coef,start->exp);
        printf("%f x^%d\n",start->coef,start->exp);
	printf("Polynomial A\n");
        for(start=headc->link;start!=lastc;start=start->link)
                printf("%f x^%d+",start->coef,start->exp);
        printf("%f x^%d\n",start->coef,start->exp);
}





