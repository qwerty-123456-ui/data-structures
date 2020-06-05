#include<stdio.h>
#include<stdlib.h>
typedef enum{false,true}boolean;
typedef struct node *treeptr;
typedef struct node
{
	int data;
       	treeptr  llink;
	treeptr rlink;
}node;
void insert(treeptr *root,int d)
{
	if((*root)==NULL)
	{
		(*root)=(treeptr)malloc(sizeof(node));
		(*root)->data=d;
		(*root)->llink=(*root)->rlink=NULL;
	}
	else if(d>((*root)->data))
		insert(&((*root)->rlink),d);
	else
		insert(&((*root)->llink),d);
}
boolean search(treeptr root,int d)
{
	if(root==NULL)
		return false;
	else if(d==(root->data))
		return true;
	else if(d>(root->data))
		return search((root->rlink),d);
	else
		return search((root->llink),d);
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
void main()
{
	treeptr root=NULL;
	int ch,data;
	while(1)
			      {
					  printf("Enter 1 insert 2 search 3 in 4 pre 5 post 6 exit\n");
					  scanf("%d",&ch);
					  switch(ch)
					  {
						  case 1:printf("Enter data\n");
							 scanf("%d",&data);
						         insert(&root,data);
							 break;
					          case 2:printf("Enter key\n");
                                                         scanf("%d",&data);
							 if(search(root,data))
								 printf("Dta found\n");
							 else
								 printf("Data not there\n");
						  case 3:inorder(root);
							 break;
						  case 4:preorder(root);
							 break;
						  case 5:postorder(root);
							 break;
						  case 6:exit(0);
					  }
				  }

}

