#include <stdio.h>
#include<stdlib.h>
#define max 3
typedef struct
{
	int key;
}ele;

typedef struct queue *quptr;
typedef struct queue
{
	ele data;
	quptr link;
}queue;

quptr f[max],r[max];

void add(int i,int n)
{ 
	quptr temp, ptr;
	temp=(quptr)malloc(sizeof(queue));
	temp->link=NULL;
	temp->data.key=n;
	if(f[i]==NULL)
		f[i]=temp;
	else
	{ 
		for(ptr=f[i];ptr->link!=NULL;ptr=ptr->link);
		ptr->link=temp;
	}
	r[i]=temp;
}

void del(int i)
{ 
	int a;
	quptr temp;
	temp=f[i];
	if(f[i]==NULL)
		printf("Empty\n");
	else
	{
		a=temp->data.key;
		temp=temp->link;
		f[i]=temp;
		printf("%d has been removed\n",a);
	}
}

void display()
{
	int i;
	quptr j;
     
	for(i=0;i<max;i++)
	{
		printf("Queue no.%d :\n",i+1);
		if(f[i] == NULL)
           printf("Queue Empty\n--------------------\n");
        else   
		{
		   	for(j = f[i]; j != NULL ; j = j->link)
        	    printf("%d\t",j->data.key);
			printf("\n--------------------\n");
		}
    }
}

int main()
{	
	int choice=4, i, j;
	ele x;    
    
    for(i=0;i<max;i++)
        f[i] = NULL;
		
       
    while(1)
	{
		printf("\n++++++++++++++++++++\n1.add to the queue\n2.delete from queue\n3.display all queues\n4.exit\n++++++++++++++++++++\n");
    	printf("Enter your choice\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
				printf("Enter the queue number(0-%d) and element to be added\n",max-1);
                scanf("%d%d",&i ,&x.key);//x is the element to be pushed
                add(i,x.key);
                break;

            case 2:
				printf("Enter the queue number(0-%d)\n",max-1);
                scanf("%d",&i);
                if(f[i] == NULL)
                    printf("Queue Empty\n");
                else
                    del(i);
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);
                break;

            default :
                printf("Invalid Choice");
        }
	}
    return 0;
}

