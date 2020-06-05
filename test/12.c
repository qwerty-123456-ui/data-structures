#include<stdio.h>
#include<stdlib.h>
typedef struct node *treeptr;
typedef struct node
{
	treeptr llink;
	treeptr rlink;
	int data;
}node;
treeptr root;
void insert(treeptr *root,int d)
{
	if(*root==NULL)
	{
		(*root)=(treeptr)malloc(sizeof(node));
		(*root)->data=d;
		(*root)->llink=(*root)->rlink=NULL;
	}
	else if(d>(*root)->data)
		insert(&((*root)->rlink),d);
	else
		insert(&((*root)->llink),d);
}
int search(treeptr root,int d)
{
	if(root==NULL)
		return 0;
	else if(root->data==d)
		return 1;
	else if(d>root->data)
		return search(root->rlink,d);
	else
		return search(root->llink,d);
}
void inorder(treeptr ptr)
{
	if(ptr)
	{
		inorder(ptr->llink);
		printf("%5d",ptr->data);
		inorder(ptr->rlink);
	}
}
void main()
{
	int i,n,j;
	root=NULL;
	while(1)
	{
		printf(" 1 insert 2 serach 3 inorder\n");
		scanf("%d",&i);
		switch(i)
		{
			case 1:printf("eneter data\n");
			       scanf("%d",&n);
			       insert(&root,n);
			       break;
			case 2:printf("Enete key\n");
			       scanf("%d",&n);
			       j=search(root,n);
			       if(j)
				       printf("Dta found\n");
			       else
				       printf("DATA NO\n");
			       break;
			case 3:inorder(root);
			       break;
		}
	}
}
