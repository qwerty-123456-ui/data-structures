#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int key;
} element;

int front=0;
int rear=0;

int capacity=1;

element *queue;

void addq()
{	
	int j, n;
	element *newQ;
	
	if(front == ((rear+1) % capacity))
    {
		printf("Queue full...doubling the capacity of the queue[NEW CAPACITY= %d]\n", 2*capacity);
		newQ = (element*)malloc(2*capacity*sizeof(element));
		if(newQ==NULL) 		
		{	printf("insufficient memory\n");
			exit(0);
		}
		for(j=0;j < capacity;j++)		
			newQ[j].key = deleteq();
		front= 2*capacity-1;
		rear= capacity - 2;
		capacity *= 2;
		free(queue);
		queue=newQ;
	}
		
	rear = (rear+1) % capacity;	
	printf("Enter the element to be inserted into the queue\n");
	scanf("%d", &n);
	queue[rear].key=n;
}
		
int deleteq()
{
		front = (front+1) % capacity;
		return queue[front].key;
}

void display()
{
	int i;
	if(front == rear)
		printf("queue empty...\n");
	else
	{
		for(i=(front+1)%capacity;i != (rear+1)%capacity;i=(i+1)%capacity)
			printf("%d\t",queue[i].key);
	}
}

	
int main()
{
	unsigned int choice;
	
	queue = (element *)malloc(sizeof(element));
	if(queue==NULL) 
	{	printf("insufficient memory\n");
		exit(0);
	}
	while(1)
	{
		printf("1: addQ\n2:deleteQ\n3:displayQ\n4:exit\n");
		scanf("%u", &choice);
		switch(choice)
		{
			case 1: addq();
					break;

			case 2: if(front == rear)
						printf("queue empty...\n");
					else
					  	printf("Element removed is %d\n", deleteq());
					break;

			case 3: display();
					break;

			case 4: exit(0);
					break;

			default: printf("Invalid choice... try again\n");
		}
	}
	return 0;
}
