#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int key;
}e;
typedef struct stack *sp;
typedef struct stack
{
	e data;
	sp link;
}stack;
sp top[10];
void push(e item, int i)
{
	sp temp;
	temp=(sp)malloc(sizeof(stack));
	temp->data =item;
	temp->link=top[i];
	top[i]=temp;
}
void pop(int i)
{
	sp temp=top[i];
	element item;
	item=temp->data;
	top[i]=top[i]->link;
	printf("removing %d\n",item);
	free(temp);
}
void display()
{
	int i;
	sp j;
	for(i=0;i<10;i++)
	{
		printf("Stack no %d \n",i+1);
		if(top[i]==NULL)
			printf("stack emepty\n");
		for(j=top[i];j;j=j->link)
			printf("%dd\t",j->data.key);
	}
}



