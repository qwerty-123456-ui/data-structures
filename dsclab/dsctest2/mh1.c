#include<stdio.h>
#include<stdlib.h>
#define MAXELEMENTS 10
typedef struct
{
	int key;
}element;
element heap[MAXELEMENTS];
int n=0;
void push(element item)
{
	int i;
	i=++n;
	while((i!=1)&&(item.key>heap[i/2].key))
	{
		heap[i].key=heap[i/2].key;
		i=i/2;
	}
	heap[i].key=item.key;
}
void pop()
{
	int item;
	element temp;
	int parent ,child;
	if(n==0)
		printf("heap empty\n");
	else
	{
		item=heap[1].key;
		temp=heap[n--];
		parent=1;
		child=2;
		while(child<=n)
		{
			if(child<n && (heap[child].key<heap[child+1].key))
				child++;
			if(temp.key>=heap[child].key)
				break;
			heap[parent]=heap[child];
			parent=child;
			child*=2;
		}
		heap[parent]=temp;
		printf("Element removed is %d\n",item);
	}
}
void display()
{
	int i;
	for(i=1;i<=n;i++)
		printf("%d\t",heap[i].key);
	printf("\n");
}
int main()
{
	int choice;
	int x;
	element e;
	while(1)
	{
		printf("Enter 1:to insert 2:delete 3:display \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:if(n==MAXELEMENTS)
				       printf("heap full\n");
			       else
			       {
				       printf("Enter the element \n");
				       scanf("%d",&x);
				       e.key=x;
				       push(e);
			       }
			       break;
			case 2:pop();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
			       break;
			default:printf("invalid hcoice \n");
		}
	}
	return 0;
}

