#include<stdio.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
void 	SORT(int *);
void main()
{
	int list[100];
 SORT(list);
}
void SORT(int list[100])
{
 int i,s=0,j,n,t;
 printf("enter the range");
 scanf("%d",&n);
 printf("enter the elements");
 for(i=0;i<n;i++)
 {
  scanf("%d",&list[i]);
 }
 for(i=0;i<n-1;i++)
 {
  s=i;
  for(j=1+i;j<n;j++)
  {
   if(list[j]<list[s])
   {
    s=j;
   }
   
  }
  SWAP(list[i],list[s],t);
  
 }
 for(i=0;i<n;i++)
 {
  printf("%d ",list[i]);
 }
}
