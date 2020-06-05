#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int key;
}element;
typedef struct stack *sp;
typedef struct stack
{
	element data;
	sp link;
}stack;
sp top[10];
void push(int i,element item)
{
	sp t;
	t=(sp)malloc(sizeof(stack));
	t->data=item;
	t->link=top[i];
	top[i]=t;
}
element pop(int i)
{
	sp t=top[i];
	if(top[i] != NULL)
	{
		element item=t->data;
		top[i]=t->link;
		free(t);
		return item;
	}
	else
		printf("Stack empty\n");
}
void display(int i)
{
	sp t;
	if(!top[i])
		printf("Stack empty\n");
	else
	{
		printf("Stack %d\n",i+1);
		for(t=top[i];t;t=t->link)
			printf("%d\t",t->data.key);
	}
}
void main()
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
}
