#include<stdio.h>
#include<stdlib.h>

#define MAX_ELEMENTS 100

typedef struct
{
	int key;
} element;

element heap[MAX_ELEMENTS];
int n = 0;

void push(int item)
{
	int i;
	
	i= ++n;
	while((i!=1) && ( item > heap[i/2].key))
	{
		heap[i].key = heap[i/2].key;
		i = i/2;
	}
	heap[i].key = item;
}
void pop()
{
	int item;
	element temp;
	int parent, child;
	if(n==0)
		printf("heap is empty\n");
	else
	{
		item = heap[1].key;
		temp = heap[n--];
		parent = 1;
		child = 2;
		while(child <= n)
		{
			if(child < n && (heap[child].key < heap[child+1].key))
				child++;
			if(temp.key >= heap[child].key)
				break;
			heap[parent] = heap[child];
			parent = child;
			child *= 2;
		}
		heap[parent] = temp;
		printf("Element removed from heap is %d\n", item);
	}	
}	

void display()
{
	int i;
	for(i=1; i<=n; i++)
		printf("%d\t", heap[i].key);
	printf("\n");
}

int main()
{
	unsigned int choice;
	int x;
	while(1)
	{
		printf("1:insert a node to heap \n2:delete a node from heap \n3:display the max heap\n4:exit\n");
		scanf("%u", &choice);
		switch(choice)
		{
			case 1: if(n == MAX_ELEMENTS)
					{
						printf("Heap is full\n");
						exit(1);
					}
					printf("Enter the element to be added to heap\n");
                	scanf("%d",&x);//x is the element to be pushed
					push(x);
					break;
			case 2: pop();
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
