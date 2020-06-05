#include<stdio.h>
#include<stdlib.h>
typedef struct
{
	int key;
}element;
int front=0
int rear=0;
int capacity=1;
element *queue;
void addq()
{
	int j,n;
	element *nq;
	if(front==((rear+1)%capacity))
	{

