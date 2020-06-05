#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}element;
element *queue=NULL;
int front=0;
int rear=0;
int size=2;
void create()
{
	queue=(element *)malloc(size*sizeof(element));
}
void copy(element *s,element *e,element *nq)
{
	while(s!=e)
	{
		*nq=*s;
		nq++;
		s++;
	}
}
void queuefull()
{
	element *nq;
	nq=(element *)malloc(2*size*sizeof(element));
	int start=(front +1)%size;
	if(start<2)
		copy(queue+start,queue+size+start-1,nq);
	else
	{
		copy(queue+start,queue-size,nq);
		copy(queue,queue+rear+1,nq+size-start);
	}
	front=2*size-1;
	rear=size-2;
	size*=2;
	free(queue);
	queue=nq;
}
void add(element item)
{
	rear=(rear+1)%size;
	if(front==rear)
	{
		queuefull();
		rear=(rear+1)%size;
	}
		queue[rear]=item;
}
element delete()
{
	element item;
	if(front==rear)
	{
		item.key=-1;
		return item;
	}
	else
	{
		front=(front+1)%size;
		return queue[front];
	}
}
void display()
{
	int i;
	if(front==rear)
		printf("Queue empty\n");
	else
	{
		for(i=(front+1)%size;i!=rear;i=(i+1)%size)
			printf("%d\t",queue[i].key);
		 printf("%d\n",queue[i].key);
	}
}
void main()
{
	int i,n;
	element item;
	create();
	while(1)
	{
		printf("Enter b1 insert 2 delete 3 display\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("Enter element\n");
			       scanf("%d",&item.key);
			       add(item);
			       break;
			case 2:item=delete();
			       if(item.key==-1)
				       printf("qeue empty\n");
			       else
				       printf("Element deleted is %d\n",item.key);
			       break;
			case 3:display();
			       break;
			case 4 :exit(1);
		}
	}
}
