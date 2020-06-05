#include<stdio.h>
#include<stdlib.h>
#define ISEMPTY(ptr)(!(ptr))
typedef struct listNode *listPointer;
typedef struct listNode
{
	int data;
	listPointer link;
}listNode;

listPointer create2()
{
	listPointer first=NULL;
	listPointer second=NULL;
	first=(listPointer)malloc(sizeof(struct listNode));
	second=(listPointer)malloc(sizeof(struct listNode));
        first->data=10;
        second->data=20;
	second->link=NULL;
	first->link=second;
	return first;
}
void  insert(listPointer *first,listPointer x)
{
	listPointer temp=NULL;
        temp=(listPointer)malloc(sizeof(struct listNode));
	temp->data=50;
	if(*first)
	{
		temp->link=x->link;
		x->link=temp;
	}
	else
	{
		temp->link=NULL;
		*first=temp;
	}
	//return *first;
}
void delete(listPointer *first,listPointer trail,listPointer x)
{
	if(trail)
	{
		trail->link=x->link;
	}
	else
		*first=(*first)->link;
        free(x);
}
void main()
{
        listPointer ptr=NULL;
        ptr=(listPointer)malloc(sizeof(struct listNode));
        //ptr->data=4;
        ptr=create2();
	listPointer ptr2=NULL;
	ptr2=(listPointer)malloc(sizeof(struct listNode));
	ptr2=ptr;
	// for(;ptr;ptr=ptr->link)
        //printf("%d\n",ptr->data);


	while(ptr2->link !=NULL)
	{
		ptr2=ptr2->link;
	}
	insert(&ptr,ptr2);
	//for(;ptr;ptr=ptr->link)
        //printf("%d\n",ptr->data);
	
	listPointer ptr3=NULL;
       	ptr3=(listPointer)malloc(sizeof(struct listNode));
        ptr3=ptr;
 	listPointer ptr4=NULL;
	ptr4=(listPointer)malloc(sizeof(struct listNode));
        ptr4=ptr;
	listPointer ptr5=NULL;
	   ptr5=(listPointer)malloc(sizeof(struct listNode));
        ptr5=ptr;


        for(;ptr3;ptr3=ptr3->link)
        printf("%d\n",ptr3->data);
	//ptr2=ptr3->link;
	ptr5=ptr5->link;
	delete(&ptr5,ptr5,ptr5=ptr5->link);
	printf("After deleting 20 node\n");
        for(;ptr4;ptr4=ptr4->link)
		 	 printf("%d\n",ptr4->data);

}

