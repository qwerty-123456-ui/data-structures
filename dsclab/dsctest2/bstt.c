#include<stdio.h>
#include<stdlib.h>
typedef struct node *tptr;
typedef struct node
{
	int data;
	tptr rlink;
	tptr llink;
}node;
void insert(tptr *root,int d)
{
	if((*root)==NULL)
	{
		(*root)=(tptr)malloc(sizeof(node));
		(*root)->data=d;
		(*root)->rlink=NULL;
		(*root)->llink=NULL;
		return;
	}
	else if(d>((*root)->data))
			insert(&((*root)->rlink),d);
	else// if(d<((*root)->llink)
                        insert(&((*root)->llink),d);
}
void inorder(tptr ptr)
{
	if(ptr)
	{
		inorder(ptr->llink);
		printf("%d",ptr->data);
		 inorder(ptr->rlink);
	}
}
void preorder(tptr ptr)
{
        if(ptr)
        {
                //void inorder(tptr
		//inorder(ptr->llink);
                printf("%d",ptr->data);
                 preorder(ptr->llink);
		 preorder(ptr->rlink);
        }
}
void postorder(tptr ptr)
{
        if(ptr)
        {
                postorder(ptr->llink);
		postorder(ptr->rlink);
                printf("%d",ptr->data);
          //       inorder(ptr->rlink);
        }
}
void main()
{
	int c,i;
	tptr t=NULL;
	while(1)
	{
	printf("enttre");
	scanf("%d",&c);
	switch(c)
	{
		case 1:printf("e");
		       scanf("%d",&i);
		       insert(&t,i);
		       break;
		case 2:inorder(t);
		       break;
		case 3:preorder(t);
		       break;
		case 4:postorder(t);
		       break;
	}
	}
}



			

