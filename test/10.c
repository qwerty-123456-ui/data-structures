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
void insert()
{
	np t;
       int	i;
	t=(np)malloc(sizeof(node));
	printf("Enter data\n");
	scanf("%d",&t->data);
	t->llink=head;
	t->rlink=head->rlink;
	head->rlink->llink=t;
	head->rlink=t;
}
void delete()
{
	np t;
	int i;
	t=head->rlink;
	if(t==head)
		printf("head no\n");
	else
	{
		head->rlink=t->rlink;
		t->rlink->llink=head;
		i=t->data;
		printf("element deleted %d \n",i);
		free(t);
	}
}
void displayf()
{
	np t;
	for(t=head->rlink;t!=head;t=t->rlink)
		printf("%d\t",t->data);
}
void displayb()
{       
        np t;
        for(t=head->rlink;t->rlink!=head;t=t->rlink);
	for(;t!=head;t=t->llink)
                printf("%d\t",t->data);

}
void main()
{
       /* int i,n;
        element item;
        for(i=0;i<10;i++)
                top[i]=NULL;*/
	int i;
	head=(np)malloc(sizeof(node));
	head->rlink=head;
	head->llink=head;
        while(1)
        {
                printf("Enter 1 insert 2 pop 3 display 4 exit\n");
                scanf("%d",&i);
                /*if(i!=4)
                {
                        printf("Enter stack no\n");
                        scanf("%d",&n);
                }*/
                switch(i)
                {
                        case 1:/*printf("Enetre element\n");
                               scanf("%d",&item.key);
                               push(n-1,item);*/insert();
                               break;
                        case 2:/*if(top[n-1]) printf("item delteed is %d\n",pop(n-1).key);
                                       else
                                               printf("Stack empty\n");*/delete();
                               break;
                        case 3:displayf();
                               break;
			case 4:displayb();
			       break;
                        case 5:exit(1);
                }
        }
}

