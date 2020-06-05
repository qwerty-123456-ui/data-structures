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
		start++;
		nq++;
	}
}
void queuefull()
{
	element *nq;
	nq=(element *)malloc(2*size*sizeof(queue));
	int start=(front+1)%size;
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
void addq(element item)
{
	rear=(rear+1)%size;
	if(front == rear)
	{
		queuefull();
		rear=(rear+1)%size;
	}
	queue[rear]=item;
}
element deleteq()
{
	element item;
	if(front== rear)
	{
		item.key=32767;
		return item;
	}
	front=(front+1)%size;
	return queue[front];
}
void display()
{
	int i;
	if(front==rear)
		printf("Queue empty\n");
	else
	{
	for(i=(front+1)%size ;i!=rear;i=(i+1)%size)
	{
		printf("%d\t",queue[i].key);
	}
	printf("%d\n",queue[i].key);
	printf("front =%d \n rear=%d\n",front,rear);
	}
}
void main()
{
	int ch,n;
	element item;
	create();
	do{
	printf("enter choice\n");
	printf("Enter 1  insert 2 delete 3 display 4 exit\n");
	scanf("%d",&ch);
		switch(ch){
		case 1:printf("enter the element\n");
		       scanf("%d",&n);
		       item.key=n;
		       addq(item);
		       break;
		case 2:item=deleteq();
		       if(item.key==32767)
			       printf("Queue empty\n");
		       else
			       printf("The element deleted is %d\n",item.key);
		       break;
		case 3:display();
		       break;
		case 4:printf("byebye\n");
		       exit(0);
		       break;
	}
	}while(ch !=4);
}
		
