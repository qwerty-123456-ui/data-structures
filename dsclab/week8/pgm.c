#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)>(y)?1:((x)==(y)?0:-1))
struct node
{
	float coef;
	int exp;
	struct node *link;
};
typedef struct node *polypointer;
void attach(float coefficient,int exponent ,polypointer *ptr)
{
	polypointer temp;
	temp=(polypointer)malloc(sizeof(struct node));
	temp->coef=coefficient;
	temp->exp=exponent;
	(*ptr)->link=temp;
	*ptr=temp;
	(*ptr)->link=NULL;
}
polypointer cadd(polypointer a1,polypointer b1)
{
	polypointer a,b,c,lastC,startA;
	int sum,done=0;
	startA=a;
	//polypointer a,b;
	a=a1->link;
	b=b1->link;
	c=(polypointer)malloc(sizeof(struct node));
	c->exp=-1;
	lastC=c;
	while(a != a1 && b!=b1)
	{
		switch(COMPARE(a->exp,b->exp))
		{
			case 1:attach(a->coef,a->exp,&lastC);
			       a=a1->link;
			       break;
			case 0://if(startA==a)
				 //      done=1;
				       sum=a->coef+b->coef;
				       if(sum)
					       attach(sum,a->exp,&lastC);
				       a=a1->link;
				       b=b1->link;
			       
			       break;
			case -1:attach(b->coef,b->exp,&lastC);
				b=b1->link;
				break;
		}
	}//while(!done);
	//for(;a != a1;a=a->link)
	//	attach(a->coef,a->exp,&lastC);
	 // for(;b != b1;b=b->link)
           //     attach(b->coef,b->exp,&lastC);
	lastC->link=c;
	return c;
}
void printpoly(polypointer k)
{
	k=k->link;
	while(((k->link)->exp)!=-1)
	{
		printf("%.0fx^%d+",k->coef,k->exp);
		k=k->link;
	}
	printf("%.0fx^%d",k->coef,k->exp);
	printf("\n");
}
int main()
{
	polypointer a,b,c,endA,endB;
	int n,i,expon;
	float coef;
	a=(polypointer)malloc(sizeof(struct node));
	a->exp=-1;
	b=(polypointer)malloc(sizeof(struct node));
	b->exp=-1;
	printf("Enter the no. of terms for first polynomial\n");
	scanf("%d",&n);
	endA=a;
	for(i=0;i<n;i++)
	{
		printf("enter the coefficient\n");
		scanf("%f",&coef);
		printf("enter the exponent\n");
		scanf("%d",&expon);
		attach(coef,expon,&endA);
	}
	endA->link=a;
	printf("Enter the no. of terms for second polynomial\n");
	scanf("%d",&n);
	endB=b;
	 for(i=0;i<n;i++)
        {
                printf("enter the coefficient\n");
                scanf("%f",&coef);
                printf("enter the exponent\n");
                scanf("%d",&expon);
                attach(coef,expon,&endB);
        }
        endB->link=b;
	c=cadd(a,b);
	printpoly(a);
	printpoly(b);
	printpoly(c);
}

