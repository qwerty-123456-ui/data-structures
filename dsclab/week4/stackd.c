#include<stdio.h>
#include<stdlib.h>
#define MALLOC(p,s)
#define REALLOC(p,s)
typedef struct
{
	int key;
}element;
element stack[0];
MALLOC(stack,sizeof(element));
int capacity=1;
int top=-1;
void stackFull();
void push(int *,element);
element pop(int *);
void main()
{
        element item;
        int i,n;
        while(1)
        {
                printf("Enter 1 for push   2: for pop    3:for display      and 4 for exit \n");
                scanf("%d",&n);
                switch (n)
                {
                        case 1: printf("Enter element \n");
				//printf("e");
                                scanf("%d",&item.key);
				//printf("e");
                                push(&top,item);
                                break;
                        case 2:if(top >=0)
                               {
                                       item=pop(&top);
                                printf("The element popped is %d \n",item.key);
                               }
                               else
                                       printf("Stack empty \n");

                                break;
                        case 3:if(top == -1)
                                       printf("STACK EMPTY \n");
                               else
                               {
                                printf("The elements of stack \n");
                               for(i=0;i<=top;i++)
                                   printf("%d \t",stack[i].key);
                               printf("\n");
                               }
                               break;
                        case 4:exit(0);
                               break;
                }
        }
}
void push(int *top,element item)
{
	//printf("e");
        if(*top>=(capacity-1))
        {
		//printf("e");
		stackFull();
        }
	//printf("error");
        *(stack+(++(*top)))=item;
}
element pop(int *top)
{
        if(*top<0)
        {
              printf("Stack empty \n");
        }
        else
                return *(stack+((*top)--));
}
void stackFull()
{
	REALLOC(stack,2*capacity*sizeof(*stack));
	capacity *=2;
}
