#include<stdio.h>
#include<math.h>
struct poly
{
	float coeff;
	int exp;
};
struct poly a[50],b[50],c[50],d[50];
void main()
{
	int i=0;
	int deg1,deg2;
	int k=0,l=0,m=0;
	printf("Enter the highest degree of poly1 \n");
	scanf("%d",&deg1);
	for(i=0;i<=deg1;i++)
	{
		printf("\n Enter the coefficient of x^%d :",i);
		scanf("%f",&a[i].coeff);
		a[k++].exp=i;
	}
	printf("Enter the highest degree of poly2 \n");
	scanf("%d",&deg2);
        for(i=0;i<=deg2;i++)
        {
                printf("\n Enter the coefficient of x^%d :",i);
                scanf("%f",&b[i].coeff);
                b[k++].exp=i;
        }
      //primting first polynomial 
      printf("\n Expression 1= %.1f",a[0].coeff);
      for (i=1;i<deg1;i++)
      {
	      printf("+%.1fx^%d",a[i].coeff,a[i].exp);
      }
      //primting second polynomial
      printf("\n Expression 1= %.1f",b[0].coeff);
      for (i=1;i<deg2;i++)
      {
              printf("+%.1fx^%d",b[i].coeff,b[i].exp);

      }
      
   // addition
   if(deg1>deg2)
   {
	for(i=0;i<=deg2;i++)
	{
	c[m].coeff=a[i].coeff+b[i].coeff;
        c[m].exp=a[i].exp;
	m++;
	}
	for(i=deg2+1;i<=deg1;i++)
	{
		c[m].coeff=a[i].coeff;
		c[m].exp=a[i].exp;
		m++;
	}

   }
   else
   {
	    for(i=0;i<=deg1;i++)
        {
        c[m].coeff=a[i].coeff+b[i].coeff;
        c[m].exp=a[i].exp;
        m++;
        }
        for(i=deg1+1;i<=deg2;i++)
        {
                c[m].coeff=b[i].coeff;
                c[m].exp=b[i].exp;
                m++;
        }

   }

// printing the sum
printf("\n EXPRESSION After addition=%.1d",c[0].exp);
for(i=1;i<m;i++)
{
	printf("+%.1fx^%d",c[i].coeff,c[i].exp);
}
}
