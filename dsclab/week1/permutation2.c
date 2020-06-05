#include<stdio.h>
#include<string.h>
#define N 10

void print(int *num,int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d",num[i]);
	printf("\n");
}
int main()
{
	int num[N];
	int *ptr;
	int temp;
	int i,j,n;
	printf("\n How many number you want");
	scanf("%d",&n);
	printf("enter the list of numbers");
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	for(j=1;j<=n;j++){
		for(i=0;i<n-1;i++)
		{
			temp=num[i];
			num[i]=num[i+1];
			num[i+1]=temp;
			print(num,n);
		}
	}

return 0;
}
