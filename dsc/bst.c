#include<stdio.h>
#include<stdlib.h>

typedef struct node* treeptr;      
typedef struct node
{
	int data;
        treeptr left;
        treeptr right;
}node;

treeptr createNode(int value)
{
        treeptr newNode = malloc(sizeof(struct node));
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
}
      
      
treeptr insert(treeptr root, int data)
    {
        if (root == NULL) return createNode(data);
        if (data < root->data)
            root->left  = insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);   
     
        return root;
    }
    
void inorder(treeptr root)
{
        if(root == NULL) 
		return;
	inorder(root->left);
        printf("%d ->", root->data);
        inorder(root->right);
}

void preorder(treeptr root)
{
        if(root == NULL) 
		return;
	printf("%d ->", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(treeptr root)
{
        if(root == NULL) 
		return;
	postorder(root->left);
	postorder(root->right);
        printf("%d ->", root->data);
        
}

int main()
{
        treeptr root = NULL;
	printf("Inserting key 8\n");
        root = insert(root, 8);
	printf("Inserting key 3\n");
        insert(root, 3);
	printf("Inserting key 8\n");        
	insert(root, 1);
	printf("Inserting key 6\n");
        insert(root, 6);
	printf("Inserting key 8\n");
        insert(root, 7);
	printf("Inserting key 10\n");
        insert(root, 10);
	printf("Inserting key 14\n");
        insert(root, 14);
	printf("Inserting key 4\n");
        insert(root, 4);
	printf("Keys in inorder traversal\n");
        inorder(root);
	printf("\n");
	printf("Keys in preorder traversal\n");
	preorder(root);
	printf("\n");
	printf("Keys in postorder traversal\n");
	postorder(root);
	printf("\n");
}
