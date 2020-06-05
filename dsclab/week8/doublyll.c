#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *llink;
	struct node *rlink;
};
typedef struct node *nodepointer;
void insert(int item,nodepointer head)
{
	nodepointer temp;
	temp=(nodepointer)malloc(sizeof(struct node));
	temp->key=item;
	temp->llink=head;
	temp->rlink=head->rlink;
	head->rlink->llink=temp;
	head->rlink=temp;
	head=temp;
}
int del(int item,nodepointer head)
{
	if(head==NULL)
	{
		printf("Empty list\n");
		return 0;

	}
	head=head->rlink;
	if((head)->key==-1)
	{
		printf("cannot delete header node\n");
		return item;


