#include<stdio.h>
#include<stdlib.h>
typedef struct 
{
	int key;
}element;
element heap[20];
int n=0;
void push(int item)
{
int i=++n;
	while((i!=1) && item>heap[i/2].key)
	{
		heap[i].key=heap[i/2].key;
		i=i/2;
	}
	heap[i].key=item;
}
void pop()
{
	int item,p,c;
	element temp;
	if(n==0)
		printf("heap empty\n");
	else
	{
		item=heap[1].key;
		temp=heap[n--];
		p=1;
		c=2;
		while(c<=n)
		{
			if(c<n && (heap[c].key<heap[c+1].key))
				c++;
			if(temp.key >=heap[c].key)
				break;
			heap[p]=heap[c];
			p=c;
			c*=2;
		}
		heap[p]=temp;
		printf("element %d\n",item);
	}
}
void display()
{
	int i;
	if(n==0)
		printf("empr\ty\n");
	else
	{
	for(i=1;i<=n;i++)
		printf("%d\t",heap[i].key);
	printf("\n");
	}
}
void main()
{
        int i,j;
	
        //root=NULL;
        while(1)
        {
                printf(" 1 insert 2 pop 3 display\n");
                scanf("%d",&i);
                switch(i)
                {
                        case 1:printf("eneter data\n");
                               scanf("%d",&j);
                               push(j);
                               break;
			case 2:/*printf("Enete key\n");
                               scanf("%d",&n);
                               j=search(root,n);
                               if(j)
                                       printf("Dta found\n");
                               else
                                       printf("DATA NO\n");*/
			       pop();
                               break;
                        case 3:display();
                               break;
                }
        }
}
   	
