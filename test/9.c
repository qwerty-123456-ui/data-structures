#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)>(y)?1:((x)==(y)?0:-1))
typedef struct polynode *polyptr;
typedef struct polynode
{
	float coef;
	int exp;
	polyptr link;
}polynode;
polyptr heada,headb,headc,lastc;
void attach(float c,int e,polyptr *ptr)
{
	polyptr temp;
	temp=(polyptr)malloc(sizeof(polynode));
	temp->coef=c;
	temp->exp=e;
	temp->link=NULL;
	(*ptr)->link=temp;
	(*ptr)=temp;
}
void padd(polyptr a,polyptr b)
{
	polyptr starta;
	int i,done=0;
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
			case 1:attach(a->coef,a->exp,&lastc);
			       a=a->link;
			       break;
			case -1:attach(b->coef,b->exp,&lastc);
                               b=b->link;
                               break;
			case 0:if(starta==a) done=1;
				       else
				       {
			       attach(a->coef+b->coef,a->exp,&lastc);
                               a=a->link;b=b->link;}
                               break;

		}
	}while(!done);
        lastc->link=headc;
}
void main()
{
	polyptr start,lasta,lastb;
	int i,n,e;
	float c;
	heada=(polyptr)malloc(sizeof(polynode));
        heada->exp=-1;
        lasta=heada;
        headb=(polyptr)malloc(sizeof(polynode));
        headb->exp=-1;
        lastb=headb;
	printf("Enter the terms in A\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enet coef and exp\n");
		scanf("%f%d",&c,&e);
		attach(c,e,&lasta);
	}
	lasta->link=heada;
	printf("Enter the terms in B\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("enet coef and exp\n");
                scanf("%f%d",&c,&e);
                attach(c,e,&lastb);
        }
        lastb->link=headb;
	padd(heada,headb);
	printf("Poly A\n");
	for(start=heada->link;start!=lasta;start=start->link)
		printf("%0.0fx^%d+",start->coef,start->exp);
	 printf("%0.0fx^%d\n",start->coef,start->exp);
	  printf("Poly B\n");
        for(start=headb->link;start!=lastb;start=start->link)
                printf("%0.0fx^%d+",start->coef,start->exp);
         printf("%0.0fx^%d\n",start->coef,start->exp);
	  printf("Poly C\n");
        for(start=headc->link;start!=lastc;start=start->link)
                printf("%0.0fx^%d+",start->coef,start->exp);
         printf("%0.0fx^%d\n",start->coef,start->exp);
}

