#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}el;
el heap[10];
int n=0;
void push(int item)
{
	int i;
	i=++n;
	while((i!=1)&&(item>heap[i/2].key))
	{
		heap[i].key=heap[i/2].key;
		i =i/2;
	}
	heap[i].key=item;
}
void delete()
{
	int item;
	el temp;
	int p,c;
	if(n==0)
		printf("heap empty\n");
	else
	{
		item=heap[1].key;
		temp=heap[n--];
		p=1;
		c=2;
		while(c<=n)
		{
			if(c<n &&(heap[c].key<heap[c+1].key))
					c++;
			if(temp.key>=heap[c].key)
				break;
			heap[p]=heap[c];
			p=c;
			c*=2;
		}
		heap[p]=temp;
		printf("delterd %d",item);
	}
}
void display()
{
	int i;
	if(n==0)
		printf("heap empty\n");
	else
	{
		for(i=1;i<=n;i++)
			printf("%d\t",heap[i].key);
	}
}
int main()
{
	int c,i;
	while(1)
	{
		printf("enter 1 in 2 del 3 disp\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:printf("enter \n");
			       scanf("%d",&i);
			       push(i);
			       break;
			case 2:delete();
			       break;
			case 3:display();
			       break;
			case 4 :exit(0);
		}

	}
}
