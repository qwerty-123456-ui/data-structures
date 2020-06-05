#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)==(y)?0:((x)>(y)?1:-1))
typedef struct pn *pp;
typedef struct pn
{
        float c;
        int e;
	pp link;
}pn;
pp ha,hb,hc,lc;
int a=0;
void attach(float coef,int exp,pp *ptr)
{
        /*if(a>=100)
        {
                printf("array full\n");
                exit(1);
        }*/
	pp temp;
	temp=(pp)malloc(sizeof(pn));
        temp->c=coef;
        temp->e=exp;
	temp->link=NULL;
	(*ptr)->link=temp;
	(*ptr)=temp;
}
void cpadd(pp a,pp b)
{
        pp start;
	hc=(pp)malloc(sizeof(pn));
        hc->e=-1;
	lc=hc;
	start=a;
	a=a->link;
	b=b->link;
	int done=0;
        do
	{
                switch(COMPARE(a->e,b->e))
                {
                        case 1:attach(a->c,a->e,&lc);
                               a=a->link;
                               break;
                        case -1:attach(b->c,b->e,&lc);
                               b=b->link;
                               break;
                        case 0:if(start==a) done=1;
			       else
			       {
				       attach(a->c+b->c,a->e,&lc);
                               a=a->link;
                               b=b->link;
			       }
                               break;
                }
        }while(!done);
      /*  for(;sa<=fa;sa++)
                attach(t[sa].c,t[sa].e);
        for(;sb<=fb;sb++)
                attach(t[sb].c,t[sb].e);
        *fd=a-1;*/
	lc->link=hc;
}
void main()
{
        int i,ex,n;
        float co;
	pp start;
        //int sa,fa,sb,fb,sd,fd;
	pp la,lb;
        ha=(pp)malloc(sizeof(pn));
        ha->e=-1;
        la=ha;
	hb=(pp)malloc(sizeof(pn));
        hb->e=-1;
        lb=hb;
        printf("Enter no of terms in A\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter coef and exp\n");
                scanf("%f%d",&co,&ex);
                attach(co,ex,&la);
        }
        la->link=ha;
        printf("Enter no of terms in B\n");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("Enter coef and exp\n");
                scanf("%f%d",&co,&ex);
                attach(co,ex,&lb);
        }
        lb->link=hb;
        cpadd(ha,hb);
        printf("poly a\n");
        for(start=ha->link;start->link!=ha;start=start->link)
                printf("%0.0fx^%d+",start->c,start->e);
	 printf("%0.0fx^%d\n",start->c,start->e);
        for(start=hb->link;start->link!=hb;start=start->link)
                printf("%0.0fx^%d+",start->c,start->e);
	 printf("%0.0fx^%d\n",start->c,start->e);
	for(start=hc->link;start->link!=hc;start=start->link)
                printf("%0.0fx^%d+",start->c,start->e);
	 printf("%0.0fx^%d\n",start->c,start->e);
}

