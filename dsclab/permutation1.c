#include<stdio.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
void perm(int *,int , int);
void main()
{
	int i,n,list[100];
	printf("Enter the size \n");
	scanf("%d",&n);
	printf("Enter the nos. \n");
	for(i=0;i<n;i++)
		scanf("%d",&list[i]);
	perm(list,0,n-1);
}
void perm(int *list,int i ,int n)
{
	int j,temp;
	if(i==n)
	{
		for(j=0;j<=n;j++)
			printf("%d",list[j]);
		printf("   ");
	}
	else
	{
		for(j=i;j<=n;j++)
		{
			SWAP(list[i],list[j],temp);
			perm(list,i+1,n);
			SWAP(list[i],list[j],temp);
		}
	}
}
