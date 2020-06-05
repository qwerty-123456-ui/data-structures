#include<stdio.h>
#include<stdlib.h>
#define MAX_DEGREE 101
#define COMPARE(x,y)((x)>(y)?1:((x)==(y)?0:1))
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
}p;
p zero()
{
	p d;
	int i;
	int n;
	printf("enter the degree \n");
	scanf("%d",&d.degree);
	for(i=0;i<d.degree;i++)
		d.coef[i]=0;
	return d;
}
int isZero(p p1)
{
	int i,flag=0;
	for(i=0;i<=p1.degree;i++)
	{
		if(p1.coef[i] == 0)
			continue;
		else if(p1.coef[i]!=0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return 0;
	else
		return 1;
}
void readPoly(p p1,int degree)
{
	int i;
	for(i=;i<=degree;i++)
	{
		printf("Enter the coefficients of x^%d\n",i);
		scanf("%e",&p1.coef[i]);
	}
}
p  attach(p p1,int coeff, int d1)
{
	p1.coef[d1]=coeff;
	if(d1>p1.degree)
		for(int i=p1.degree+1;i<d1;i++)
			p1.coef[i]=0;
	return p1;
}
int coef(p p1,int exp)
{
	return p1.coef[exp];
}
int lead_exp(p p1)
{ 
	return (p1.degree);
	
}
p remov(p p1,int exp)
{
	p1.coef[exp]=0;
	if(exp==p1.degree)
		p1.degree--;
        return p1;
}
void main()
{
	p a,b,d;
	int sum;
	printf("Enter the degree of polynomial a and b \n");
	scanf("%d%d",&a.degree,&b.degree);
	readPoly(a,a.degree);
	readPoly(b,b.degree);
	d=zero();
	while(!isZero(a) && !isZero(b))
	{
		switch(COMPARE(lead_exp(a),lead_exp(b)))
		{
			case -1:d=attach(d,coef(b,lead_exp(b)),lead_exp(b));
				b=remov(b,lead_exp(b));
				break;
		        case 0:sum =coef(a,lead_exp(a))+coef(b,lead_exp(b));
			       if(sum)
				       attach(d,sum,lead_exp(a));
			       a=remov(a,lead_exp(a));
			       b=remov(b,lead_exp(b));
			       break;
			case 1:d=attach(d,coef(a,lead_exp(a)),lead_exp(a));
			       a=remov(a,lead_exp(a));
			       break;
		}
	}
	printf("POLYNOMIAL IS \n");
	for(int i=d.degree;i>0;i--)
		printf("%fx^%d + ",d.coef[i],i);
	printf("%f\n",d.coef[0]);
}

