#include<stdio.h>
#include<stdlib.h>
typedef struct node *treeptr;
typedef struct node
{
	int data;
	treeptr rlink;
	treeptr llink;
}node;
void insert(treeptr *root,int d)
{
	if((*root)==NULL)
	{
		*root=(treeptr)malloc(sizeof(node));
		(*root)->data=d;
		(*root)->llink=NULL;
		(*root)->rlink=NULL;
		return;
	}
	else if(d>((*root)->data))
		insert(&((*root)->rlink),d);
	else if(d<((*root)->data))
                insert(&((*root)->llink),d);
}
void inorder(treeptr ptr)
{
	if(ptr)
	{
		inorder(ptr->llink);
		printf("%d\t",ptr->data);
		inorder(ptr->rlink);
	}
}
void preorder(treeptr ptr)
{
        if(ptr)
        {
                printf("%d\t",ptr->data);
                preorder(ptr->llink);
		preorder(ptr->rlink);
        }
}
void postorder(treeptr ptr)
{
        if(ptr)
        {
                postorder(ptr->llink);
                postorder(ptr->rlink);
		printf("%d\t",ptr->data);
        }
}
int main()
{
	int choice=0,data;
	treeptr root=NULL;
	while(1)
	{
		printf("Enter 1 insert 2 inorder 3 preorder 4 postorder \n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter data to be inserted\n");
			       scanf("%d",&data);
			       insert(&root,data);
			       break;
			case 2:printf("inorder :\n");
			       inorder(root);
			       printf("\n");
			       break;
			case 3:printf("preorder :\n");
                               preorder(root);
			       printf("\n");
                               break;
			case 4:printf("postorder :\n");
                               postorder(root);
			       printf("\n");
                               break;
			default:printf("invalid\n");
				break;
		}
	}
	return 0;
}

