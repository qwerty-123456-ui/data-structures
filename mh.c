#include<stdio.h>
#include<stdlib.h>
#define MAXELEMENTS 20
typedef struct element
{
	int key;
}element;
element heap[MAXELEMENTS];
int n=0;
void push(int item)
{
	int i=++n;
	while(i!=1 && item>heap[i/2].key)
	{
		heap[i].key=heap[i/2].key;
		i=i/2;
	}
	heap[i].key=item;
}
void pop()
{
	int p,c,item;
	element temp;
	if(n==0)
		printf("Heap is empty\n");
	else
	{
		item=heap[1].key;
	        temp=heap[n--];
		p=1;
		c=2;
		while(c<=n)
		{
			if(c<n && (heap[c].key<heap[c+1].key))
				c++;
			if(temp.key>=heap[c].key)
				break;
			heap[p]=heap[c];
			p=c;
			c*=2;
		}
	
		heap[p]=temp;;
		printf("Elmenet deleted is %d\n",item);
}}
void display()
{
	int i;
	if(n==0)
		printf("heap emepoty\n");
	else
	{
		for(i=1;i<=n;i++)
			printf("%d\t",heap[i].key);
	}
}
void main()
{
	int i;
	int ch;
	while(1)
	{
		printf("Enter 1 insert 2del 3 display 4 exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(n==MAXELEMENTS)
				       printf("heap full\n");
			       else
			       {
				       printf("Element to be added\n");
				       scanf("%d",&i);
				       push(i);
			       }
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
		}}
}
