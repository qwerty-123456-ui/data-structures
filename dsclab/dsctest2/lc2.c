#include<stdio.h>
#include<stdlib.h>
#define COMPARE((x)>(y)?1:((x)==(y)?0:-1))

typedef struct polynode *polyptr;
typedef struct polynode
{
	int exp;
	float coef;
	polyptr link;
}polynode;
polyptr heada,headb,headc,lastc;
void attach(float c,int e,polyptr *ptr)
{
	polyptr temp;
	temp=(polyptr)malloc(sizeof(polynode));
	temp->exp=e;
	temp->coef=c;
	(*ptr)->link=temp;
	*ptr=temp;
}
void cpadd(polyptr a,polyptr b)
{
	int sum,done=0;
	polyptr starta;
	a=a->link;
	b=b->link;
	headc=(polyptr)malloc(sizeof(polynode));
	headc->exp=-1;
	lastc=headc;
	switch(COMPARE(a->expo
