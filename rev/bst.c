#include<stdio.h>
#include<stdlib.h>
typedef struct node *tp;
typedef struct node
{
	tp rlink;
	tp llink;
	int data;
}node;
tp root=NULL;
void insert(tp *root,int d)
{
	if((*root)==NULL)
	{
		(*root)=(tp)malloc(sizeof(node));
		(*root)->data=d;
		(*root)->llink=(*root)->rlink=NULL;
		return;
	}
	else if(d>(*root)->data)
		insert(&((*root)->rlink),d);
	else
		insert(&((*root)->llink),d);
}
int search(tp root,int d)
{
	if(root==NULL)
		return 0;
	else if(root->data==d)
		return 1;
	else if(d>root->data)
		return search(root->rlink,d);
	else
		return search(root->rlink,d);
}
void in(tp ptr)
{
	if(ptr)
	{
		in(ptr->llink);
		printf("%d\t",ptr->data);
		in(ptr->rlink);
	}
}
void main()
{
	int i,n;
	int a;
	root=NULL;
	while(1)
	{
		printf("Enter 1 in 2 search 3 in 4 exit\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("Enter data\n");
			       scanf("%d",&n);
			       insert(&root,n);
			       break;
			case 2:printf("enter key\n");
			       scanf("%d",&n);
			       a=search(root,n);
			       if(a)
				       printf("found\n");
			       else
				       printf("not there\n");
			       break;
			case 3:in(root);
			       break;
			case 4:exit(0);
		}
	}
}
