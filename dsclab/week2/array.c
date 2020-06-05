#include<stdio.h>
#include<stdlib.h>
int ** alloc(int ,int);
void read(int **,int ,int);
void printout(int **,int ,int);
void sum(int **,int,int);
void main()
{
	int i,r,c,**a;
	printf("Enter no of rows and columns\n");
	scanf("%d%d",&r,&c);
	a=alloc(r,c);
	read(a,r,c);
	printout(a,r,c);
	sum(a,r,c);
}
int **  alloc(int r,int c)
{
	int **a,i;
	 a=malloc(r*sizeof(int));
        for(i=0;i<r;i++)
		a[i]=malloc(c*sizeof(int));
	return a;
}
void read(int **a,int r,int c)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("enter the values of a[%d][%d] \n",i,j);
			scanf("%d",&a[i][j]);
		}
	}
}
void printout(int **a,int r,int c)
{
	   int i,j;
	   printf("The array is \n");
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        printf("%d \t",a[i][j]);
                }
		printf("\n");
        }
}
void sum(int **a,int r,int c)
{
	int i,j,sum=0;
        for(i=0;i<r;i++)
        {
                for(j=0;j<c;j++)
                {
                        sum += a[i][j];
                }
	}
       	printf("The sum is %d \n",sum);
        
}

	

