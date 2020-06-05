#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}element;
element *queue=NULL;
int rear=0;
int front=0;
int size=2;
void create()
{
	queue=(element *)malloc(size*sizeof(element));
}
void copy(element *start,element *end,element *nq)
{
	while(start != end)
	{
		*nq=*start;
		nq++;
		start++;
	}
}
void queuefull()
{
	element *nq;
	nq=(element *)malloc(2*size*sizeof(queue));
	int start=(front+1)%size;
	if(start<2)
		copy(queue+start,queue+start+size-1,nq);
	else
	{
		copy(queue+start,queue+size,nq);
		copy(queue,queue+rear+1,nq+size-start);
	}
	front=2*size-1;
	rear=size*2;
	free(queue);
	queue=nq;
}
void enQueue(element item)
{
	rear=(rear+1)%size;
	if(front==rear)
	{
		queuefull();
		rear=(rear+1)%size;
	}
		queue[rear]=item;
}
element dequeue()
{
	element item;
	if(front==rear)
	{
		item.key=-1;
		return item;
	}
		front=(front+1)%size;
		return queue[front];
}
void display()
{
	int i=front+1;
	if(front==rear)
		printf("\n Queue is empty\n");
	else
	{
		printf("\n");
		for(i=(front+1)%size ; i!= rear;i=(i+1)%size)
		{
			printf("%d\t",queue[i].key);
		}
		printf("%d",queue[i].key);
		printf("\n front =%d \t rear=%d\n",front,rear);
	}
}
int main()
{
	int choice;
	int n;
	element item;
	create();
	do
	{
		printf("enter choice\n");
		printf("MENU\n");
		printf("1 insert 2 delete 3 display 4 exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("enter element\n");
			       scanf("%d",&n);
			       item.key=n;
			       enQueue(item);
			       break;
			case 2:item=dequeue();
			       if(item.key==-1)
				       printf("queue is empty\n");
			       else
				       printf("element deleled is %d\n",item.key);
			       break;
			case 3:display();
			       break;
			case 4:printf("operation complete \n");
			       break;
			default:printf("invalid choice\n");
				break;
		}
	}while(choice != 4);
}

