#include<stdio.h>
#include<stdlib.h>
typedef struct n *np;
typedef struct n
{
	int data;
	np rlink;
	np llink;
}n;
np head;
void insert()
{
	int n;
	np temp;
	printf("Enter the info\n");
	scanf("%d",&n);
	temp=(np)malloc(sizeof(n));
	temp->data=n;
	temp->llink=head;
	temp->rlink=head->rlink;
	head->rlink->llink=temp;
	head->rlink=temp;
}
void delete()
{
	np temp=head->rlink;
	if(head->rlink==head)
		printf("head node not ");
	else
	{
		head->rlink=temp->rlink;
		temp->rlink->llink=head;
		printf("item removeed is %d :",temp->data);
	        free(temp);
	}
}
void displayf()
{
	np temp;
	temp=head->rlink;
	if(temp==head)
		printf("empty");
	else
	{
		for(;temp!=head;temp=temp->rlink)
			printf("%d\t",temp->data);
	}
}
void displayb()
{
        np temp;
        temp=head->rlink;
        if(temp==head)
                printf("empty");
        else
        {
                //for(;temp!=head;temp=temp->rlink);
		for(temp=head->llink;temp!=head;temp=temp->llink)
                        printf("%d\t",temp->data);
        }
}
int main()
{
	int c;
	head=(np)malloc(sizeof(n));
	head->rlink=head;
	head->llink=head;
	while(1)
	{
		printf("1 for i 2 del 3 display f 4 dis b\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:insert();
			       break;
			case 2:delete();
			       break;
			case 3:displayf();
			       break;
			case 4:displayb();
			       break;
		}
	}
}

