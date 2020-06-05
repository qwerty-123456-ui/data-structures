#include<stdio.h>
#include<stdlib.h>
typedef struct node *np;
typedef struct node
{
	np llink;
	np rlink;
	int data;
}node;
np head;
void add()
{
	np temp;
	temp=(np)malloc(sizeof(node));
	int i;
	printf("Enter data\n");
	scanf("%d",&i);
	temp->data=i;
	temp->rlink=head->rlink;
	temp->llink=head;
	head->rlink->llink=temp;
	head->rlink=temp;
}
void delete()
{
	np temp;
	if(head->rlink==head)
		printf("head there\n");
	else
	{
		temp=head->rlink;
		head->rlink=temp->rlink;
		temp->rlink->llink=head;
		printf("deleted is %d\n",temp->data);
		free(temp);
	}
}
void displayf()
{
	np temp;
	if(head->rlink==head)
                printf("head there\n");
	else
	{
		for(temp=head->rlink;temp!=head;temp=temp->rlink)
			printf("%d\t",temp->data);
		printf("\n");
	}
}
void displayr()
{       
        np temp;
	//head=(np)malloc(sizeof(node));
	//head->llink=head->rlink=head;
        if(head->rlink==head)
                printf("head there\n");
        else
        {
                for(temp=head->rlink;temp->rlink!=head;temp=temp->rlink);
		for(;temp!=head;temp=temp->llink)
                        printf("%d\t",temp->data);
                printf("\n");
        }
}
void main()
{
	int i;
	head=(np)malloc(sizeof(node));
        head->llink=head->rlink=head;
	while(1)
	{
		printf("Enter 1 add 2 del 3 dis fow 4 dis back 5 exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:add();
			       break;
			case 2:delete();
			       break;
			case 3:displayf();
			       break;
			case 4:displayr();
			       break;
			case 5 :exit(0);
		}
	}
}
