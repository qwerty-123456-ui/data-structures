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
void copy(element *start,element *end,element *nq)
{
	while(start!=end)
	{
		*nq=*start;
		nq++;
		start++;
	}
}
void queuefull()
{
	element *nq;
	nq=(element *)malloc(2*size*sizeof(element));
	int start=(front+1)%size;
	if(start<2)
		copy(queue+start,queue+size+start-1,nq);
	else
	{
		copy(queue+start,queue-size,nq);
		copy(queue,queue+rear+1,nq+size-start);
	}
	front =2*size-1;
	rear=size-2;
	size*=2;
	free(queue);
	queue=nq;
}
void addq(element item)
{
	rear=(rear+1)%size;
	if(front==rear)
	{
		queuefull();
		rear=(rear+1)%size;
	}
	queue[rear]=item;
}
element deleteq()
{
	element item;
	if(front==rear)
	{
		item.key=-1;
		return item;
	}
		 front=(front +1)%size;
                return queue[front];

}
void display()
{
	int i;
	if(front!=rear)
	{
		for(i=(front+1)%size;i!=rear;i=(i+1)%size)
			printf("%d\t",queue[i].key);
		printf("%d\n",queue[i].key);
	}
	else
		printf("QUEUE empty\n");
}
/*void main()
{
        int i,n;
        element item;
        for(i=0;i<10;i++)
                top[i]=NULL;
        while(1)
        {
                printf("Enter 1 insert 2 pop 3 display 4 exit\n");
                scanf("%d",&i);
                if(i!=4)
                {
                        printf("Enter stack no\n");
                        scanf("%d",&n);
                }
                switch(i)
                {
                        case 1:printf("Enetre element\n");
                               scanf("%d",&item.key);
                               push(n-1,item);
                               break;
                        case 2:if(top[n-1]) printf("item delteed is %d\n",pop(n-1).key);
                                       else
                                               printf("Stack empty\n");
                               break;
                        case 3:display(n-1);
                               break;
                        case 4:exit(1);
                }
        }
}*/
/*void main()
{
        int i,n;
        element item;
        for(i=0;i<10;i++)
                top[i]=NULL;
        while(1)
        {
                printf("Enter 1 insert 2 pop 3 display 4 exit\n");
                scanf("%d",&i);
                if(i!=4)
                {
                        printf("Enter stack no\n");
                        scanf("%d",&n);
                }
                switch(i)
                {
                        case 1:printf("Enetre element\n");
                               scanf("%d",&item.key);
                               push(n-1,item);
                               break;
                        case 2:if(top[n-1]) printf("item delteed is %d\n",pop(n-1).key);
                                       else
                                               printf("Stack empty\n");
                               break;
                        case 3:display(n-1);
                               break;
                        case 4:exit(1);
                }
        }
}*/
void main()
{
        int i,n;
        element item;
	create();
        //for(i=0;i<10;i++)
          //      top[i]=NULL;
        while(1)
        {
                printf("Enter 1 insert 2 pop 3 display 4 exit\n");
                scanf("%d",&i);
            //    if(i!=4)
              //  {
                //        printf("Enter stack no\n");
                  //      scanf("%d",&n);
                //}
                switch(i)
                {
                        case 1:printf("Enetre element\n");
                               scanf("%d",&item.key);
                               addq(item);
                               break;
                        case 2:i=deleteq().key;
			       if(i!=-1)
			       printf("item delteed is %d\n",i);
                                       else
                                               printf("Stack empty\n");
                               break;
                        case 3:display();
                               break;
                        case 4:exit(1);
                }
        }
}


