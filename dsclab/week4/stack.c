#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
typedef struct
{
	int key;
}element;
element stack[MAX_SIZE];
int top=-1;
void push(int *,element);
element pop(int *);
void Stack_empty();
int main()
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
				scanf("%d",&item.key);
				push(&top,item);
				break;
		        case 2://if(top >=0)
			       //{
				       item=pop(&top);
				printf(" %d \n",item.key);
			      // }
			       //else
				 //      printf("Stack empty \n");

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
	
	if(*top>=MAX_SIZE)
	{
		printf("Stack full\n");
	
	}
	stack[++(*top)]=item;
}
element pop(int *top)
{
	element a;
	a.key='\0'-0;
	if(*top<0)
	{
	      printf("Stack empty \n");
	      printf("no of ELEMENTS POPPED are");
	      return a;
	}

	else{
		printf("THe element poppped is");
		return stack[(*top)--];
}}

	           



