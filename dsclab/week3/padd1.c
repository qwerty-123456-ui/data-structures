#include<stdio.h>
#include<stdlib.h>
#define COMPARE(x,y)((x)>(y)?-1:(x)==(y)?0:1)
typedef struct
{
	int d;
	int coef[10];
}poly;

poly Zero()
{
	poly a;
	printf("Enter the degree : ");
	scanf("%d",&a.d);
	//printf("\n degree is %d ",a.d);
	for(int i=0;i<=a.d;i++)
		a.coef[i]=0;
	return a;
}

int isZero(poly p)
{
	for(int i=0;i<=p.d;i++)
		if(p.coef[i] != 0)
			return 0;
	return 1;
}

poly Attach(poly p, int d, int c)
{
	p.coef[d]=c;
	if(d>p.d)
		for(int i=p.d +1 ;i<d;i++)
			p.coef[i]=0;
	return p;
}

int Coef(poly p,int d)
{
	return p.coef[d];
}

poly Rem(poly p,int d)
{
	p.coef[d]=0;
	if(d==p.d)
		p.d--;
	return p;
}
int lead_exp(poly a)
{
	return a.d;
}


poly Add(poly a,poly b)
{
	int sum;
	poly d;
	        d=Zero();
        while(!isZero(a) && !isZero(b))
        {
                switch(COMPARE(lead_exp(a),lead_exp(b)))
                {
                        case -1:d=Attach(d,lead_exp(a),Coef(a,lead_exp(a)));
                                a=Rem(a,lead_exp(a));
                                break;
                        case 0:sum =Coef(a,lead_exp(a))+Coef(b,lead_exp(b));
                               if(sum)
                                      d= Attach(d,lead_exp(a),sum);
                               a=Rem(a,lead_exp(a));
                               b=Rem(b,lead_exp(b));
                               break;
                        case 1:d=Attach(d,lead_exp(b),Coef(b,lead_exp(b)));
                               b=Rem(b,lead_exp(b));
                               break;
                }
	}
	return d;
}
void print(poly p)
{
	for(int i=p.d ; i>0 ;i--)
		printf("%dx^%d +",p.coef[i],i);
	printf("%d\n",p.coef[0]);
}

int main()
{
	poly a,b;

	a=Zero();
	printf("Enter the coef in descending order \n ");
	for(int j=a.d;j>=0;j--)
		scanf("%d",&a.coef[j]);
	b=Zero();
        printf("Enter the coef in descending order \n ");
        for(int j=b.d;j>=0;j--)
                scanf("%d",&b.coef[j]);

	printf("Poly 1: ");
	print(a);
	 printf("Poly 2: ");
        print(b);
	poly d;
	d=Add(a,b);
	printf("Sum is : ");
	print(d);
}

