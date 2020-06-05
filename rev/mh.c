#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int key;
}element;
element heap[20];
int n=0;
void add(int item)
{
	int i=++n;
	while(i!=1 && item> heap[i/2].key)
	{
		heap[i].key=heap[i/2].key;
		i/=2;
	}
	heap[i].key=item;
}
void del()
{
	int item,p,c;
	element temp;
	if(n==0)
		printf("empty\n");
	else
	{
		p=1;
		c=2;
		item=heap[1].key;
		temp=heap[n--];
		while(c<=n)
		{
			if(c<n && heap[c].key<=heap[c+1].key)
				c++;
			if(temp.key>=heap[c].key)
				break;
			heap[p]=heap[c];
			p=c;
			c*=2;
		}
		heap[p]=temp;
		printf("element delted is %d\n",item);
	}
}
void disp()
{
	if(n==0)
		   printf("empty\n");
	else
	{
		for(int i=1;i<=n;i++)
			printf("%d\t",heap[i].key);
		printf("\n");
	}
}
void main()
{
	int i,c;
	while(1)
	{
		printf("enter 1 add 2 del 3 disp 4 exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:if(n>20)
				       printf("full\n");
			       else
			       {
				       printf("data \n");
				       scanf("%d",&c);
				       add(c);
			       }
			       break;
			case 2:del();
			       break;
			case 3:disp();
			       break;
			case 4:exit(0);
		}
	}
}
