#include<stdio.h>
#include<stdlib.h>
typedef struct
{
        int key;
}element;
typedef struct queue *sp;
typedef  struct queue
{
        sp link;
        element data;
}queue;
sp front[10],rear[10];
void push(int i,element item)
{
        sp temp;
        temp=(sp)malloc(sizeof(queue));
        temp->data=item;
	if(front[i])
		rear[i]->link=temp;
	else
		front[i]=temp;
        rear[i]=temp;
        rear[i]->link=NULL;
}
element pop(int i)
{
        element item;
        sp temp;
        if(front[i]==NULL)
        {
                printf("stack empty\n");
        }
        else
        {
                temp=front[i];
                item=temp->data;
                front[i]=front[i]->link;
                free(temp);
                return item;
        }
}
void display(int i)
{
        sp temp;
        if(front[i]==NULL)
        {
                printf("stack empty\n");
        }
        else
        {
                for(temp=front[i];temp!=rear[i];temp=temp->link)
                        printf("%d\t",temp->data.key);
		 printf("%d\t",temp->data.key);
                printf("\n");
        }
}
void main()
{
        int i,n;
        element item;
        for(i=0;i<10;i++)
                front[i]=NULL;
        while(1)
        {
                printf("Enter 1 psh 2 pop 3 disp\n");
                scanf("%d",&i);
                if(i!=4)
                {
                        printf("enter stack no\n");
                        scanf("%d",&n);
                }
                switch(i)
                {
                        case 1:printf("enbter datw\n");
                               scanf("%d",&item.key);
                               push(n-1,item);
                               break;
                        case 2:if(front[n-1]==NULL)
                               {
                                       printf("stack empty\n");

                               }
                               else
                               {
                                       item=pop(n-1);
                                       printf("popped is %d\n",item.key);
                               }
                               break;
                        case 3:display(n-1);
                               break;
                        case 4:exit(1);
                }
        }
}

