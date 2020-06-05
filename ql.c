#include<stdio.h>
#include<stdlib.h>
typedef struct element
{
	int key;
}element;
typedef struct queue *qp;
typedef struct queue
{
	qp link;
	element data;
}queue;
qp rear[10],front[10];
void add(element item, int i)
{
	qp temp;
	temp=(qp)malloc(sizeof(queue));
	temp->data=item;
	if(front[i])
		rear[i]->link=temp;
	else
		front[i]=temp;
	rear[i]=temp;
	rear[i]->link=NULL;
}
element delete(int i)
{
	qp temp;
	element item;
	if(front[i])
	{
		temp=front[i];
		item=temp->data;
		front[i]=front[i]->link;
		free(temp);
	}
	else
		item.key=-1;
	return item;
}
void display(int i)
{
	qp temp;
	if(front[i])
	{
		for(temp=front[i];temp;temp=temp->link)
			printf("%d\t",temp->data.key);
		printf("\n\n");
	}
	else
		printf("empty\n");
}
void main()
{
	element item;
	int ch,n;
	while(1)
	{
		printf("Enter 1 insert 2 delete 3 display 4 exit\n");
		scanf("%d",&ch);
		if(ch !=4)
		{
			printf("Enter the queueno\n");
			scanf("%d",&n);
		}
		switch(ch)
		{
			case 1: printf("Enter the element\n");
				scanf("%d",&item.key);
				add(item,n-1);
				break;
			case 2:item=delete(n-1);
			       if(item.key==-1)
				printf("queue empty\n");
			       else
				       printf("elememt deleted is %d\n",item.key);
			       break;
			case 3:printf("queue is ");
			       display(n-1);
			       break;
			case 4:exit(0);
		}
	}
}
	
