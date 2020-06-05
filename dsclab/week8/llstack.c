#include<stdio.h>
#include<stdlib.h>
//#define MALLOC(p,s)
typedef struct element
{
	int key;
}element;
//typedef struct stack *stackpointer;
struct stack
{
	element data;
	struct stack *link;
	 //struct stack *link;
};
//stackpointer top[100];
typedef struct stack *stackpointer;
//stackpointer top[10];
stackpointer top[10];
void push(element item,int i)
{
	 // printf("eeee\n");
	stackpointer temp;
	temp=(stackpointer)malloc(sizeof(struct stack));
//	MALLOC(temp,sizeof( stack));
	 // printf("eeee\n");
//  printf("eeee\n");
      //  element t=item;
//	  printf("eeee\n");
	  temp->data=item;
//printf("eeee\n");

	temp->link=top[i];
//	printf("eeee\n");

	top[i]=temp;
//	printf("eeee\n");

}
element pop(int i)
{
	stackpointer temp=top[i];
	element item;
	if(!temp)
	{
		item.key=-1;
		return item;
	}
	item=top[i]->data;
	top[i]=top[i]->link;
	free(temp);
	return item;
}
void display(int i)
{
	stackpointer temp;
	temp=top[i];
	if(top[i]==NULL)
	{
		printf("Stack is empty\n");
		return;
	}
	printf("stack %d is \n",i+1);
	for(;temp;temp=temp->link)
		printf("%d\n",temp->data.key);
	printf("\n");
}
int main()
{
	int stackno,choice;
	element item;
	while(1)
	{
		printf("Enter \n 1 Push \n 2 pop \n 3 display \n 4 exit\n");
		scanf("%d",&choice);
		if(choice !=4 )
		{
			printf("Enter the stack no.\n");
			scanf("%d",&stackno);
		}
		switch (choice)
		{
			case 1:printf("Enter data to be inserted\n");
			       scanf("%d",&item.key);
			//       printf("eeee\n");
		//	       *top=stackno;
			       push(item,stackno-1);
			  //       printf("eeee\n");

			       break;
			case 2:item =pop(stackno-1);
			       if(item.key==-1)
				       printf("Stack empty\n");
			       else
				       printf("Element deleted is %d\n",item.key);
			       break;
			case 3:display(stackno-1);
			       break;
			case 4:printf("operation completed\n");
			       exit(0);
		}
	}
	return 0;
}


