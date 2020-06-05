#include<stdlib.h>
#include <stdio.h>
#define SWAP(x,y,t)((t)=(x),(x)=(y),(y)=(t))
#define COMPARE(x,y)((x)>(y)? 1:(x)==(y)?0:-1)
void sort (int [],int n);
//int binsearch(int [],int ,int,int);

void main()
{
	int choice=1,a[100],n,search,i;
	while(choice)
{
	int ch;
	printf("enter 1 to read array \t enter 2 to print array \t enter 3 to sort array \t enter 4 to search array \n");
	scanf("%d",&ch);
	switch(ch){
		case 1: printf(" enter the size");
			scanf("%d",&n);
			printf("enter the elements \n");
			for(i=0;i<n;i++)
				scanf("%d",&a[i]);
			break;
	        case 2:for(i=0;i<n;i++)
                                printf("%d",a[i]);
                        break;
                case 3:sort(a,n);
		       printf("sorted array \n");
		       for(i=0;i<n;i++)
                                printf("%d",a[i]);
                        break;
               /* case 4:printf("enter the search elements \n");
		       scanf("%d",&ch);
		       search=binsearch(a,ch,0,n-1);
		       if(search>0)
			       printf(" the element is present in %d",search);
		       else 
			       printf(" the element is absent");
		       break;*/
		default:printf("wrong entry");
			//exit(0);
	}
	printf("you wish to continue enter 1 if yes 0 if no\n");
	scanf("%d",&choice);
	
}
}
void sort(int list [],int n)
{
	int i,j,s,t;
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



                                                                                                                                                                                                           
                    
