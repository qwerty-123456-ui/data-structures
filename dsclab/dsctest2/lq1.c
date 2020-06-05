#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int key;
}element;
typedef struct qu *q;
typedef struct qu
{
	element data;
}qu;
q f[10].r[10];
void addq(int i,element item)
{
	q temp;
	temp=(q)malloc(sizeof(qu));
	temp->data=item;
	if(front[i])
		rear->link=temp;
	else
		front[i]=temp;
	rear[i]=temp;
	rear[i]->link=NULL;
}
element rem(int i)
{
	q temp=front[i];
	element i;
	if(front[i])
	{
		item=temp->data;
		front[i]=front[i]->link;
	}
	else
	{
		item.key=-1;
	}
	free(temp);
	return item;
}
void display()
{
	q temp;
	temp=front[i];
	if(front[i]==NULL)
		print("Quueu wmpty\n")
	else
	{
		for(;temp;temp=temp->link)
			printf("%d",temp->data).key;
	}
}
