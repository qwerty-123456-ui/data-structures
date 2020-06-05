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
void dinsert()
{
	nodeptr temp;
	int n;
	temp=(nodeptr)malloc(sizeof(node));
	printf("Enter the data to be inserted \n");
	scanf("%d",&n);
	temp->data=n;
	temp->rlink=head->rlink;
	temp->llink=head;
	head->rlink->llink=temp;
	head->rlink=temp;
}
void delete()
{
	nodeptr temp;
	temp=head->rlink;
	if(temp==head)
		printf("head node not permitted\n");
	else
	{
		head->rlink=temp->rlink;
		temp->rlink->llink=head;
		printf("THE element deleted is  %d\n",temp->data);
		free(temp);
	}
}
void displayf()
{
	nodeptr temp;
	printf("The elemets ares \n");
	if(head->rlink==head)
		printf("Empty list\n");
	else
	{
		for(temp=head->rlink;temp->rlink != head ;temp=temp->rlink)
			printf("%d\t",temp->data);
		printf("%d\n",temp->data);
	}
}
void displayb()
{
        nodeptr temp;
        printf("The elemets ares \n");
        if(head->rlink==head)
                printf("Empty list\n");
        else
        {
                for(temp=head->rlink;temp->rlink != head ;temp=temp->rlink);
		for(temp;temp->llink!=head;temp=temp->llink)
                        printf("%d\t",temp->data);
                printf("%d\n",temp->data);
        }
}
void main()
{
	int ch;
	head=(nodeptr)malloc(sizeof(node));
	head->llink=head;
	head->rlink=head;
	while(1)
	{
		printf("enter 1 fo insert 2 delte 3 dis fow 4 dis back 5 exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:dinsert();
			       break;
			case 2:delete();
			       break;
			case 3:displayf();
			       break;
			case 4:displayb();
			       break;
			case 5: exit(0);
		}
	}
}
