#include<stdio.h>
#include<stdlib.h>
typedef struct node *nodeptr;
typedef struct node
{
	nodeptr llink;
	nodeptr rlink;
	int data;
}node;
nodeptr head;
void insert()
{
	int n;
	nodeptr temp;
	temp=(nodeptr)malloc(sizeof(node));
	printf("Enter the info to be inserted \n");
	scanf("%d",&n);
	temp->data=n;
	temp->llink=head;
	temp->rlink=head->rlink;
	temp->rlink->llink=temp;
	head->rlink=temp;
}
void delete()
{
	nodeptr temp=head->rlink;
	if(head->rlink==head)
		printf("deletion of head node not permitted\n");
	else
	{
		head->rlink=temp->rlink;
		temp->rlink->llink=head;
		printf("removing node with data %d\n",temp->data);
		free(temp);
	}
}
void display()
{
	nodeptr temp;
	if(head->rlink==head)
		printf("empty list\n");
	else
	{
		for(temp=head->rlink;temp->rlink!=head;temp=temp->rlink)
			printf("%d\t",temp->data);
		printf("%d\t",temp->data);
		printf("\n\n");
	}
}
int main()
{
	int choice;
	head=(nodeptr)malloc(sizeof(node));
	head->rlink=head;
	head->llink=head;
	while(1)
	{
		printf("1:insert 2:delete 3 display 4 exit \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:insert();
			       break;
			case 2:delete();
			       break;
			case 3:display();
			       break;
			case 4:exit(0);
			       break;
			default:printf("invalid choice \n ");
				break;
		}
	}
	return 0;
}


