#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void inorder(struct node * root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	printf("%d ->",root->data );
	inorder(root->right);
}
void preorder(struct node * root)
{
	if(root==NULL)
		return;
	printf("%d ->",root->data );
	preorder(root->left);
	preorder(root->right);
}
void postorder(struct node * root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d ->",root->data );
}

struct node * create_node(int item)
{
	struct node * newNode=(struct node *)malloc(sizeof(struct node));
	newNode->data=item;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}

struct node * insert(struct node *root,int item)
{
	if(!root)
	{
		root=(struct node *)malloc(sizeof(struct node));
		root->data=item;
		root->left=NULL;
		root->right=NULL;
	}

	if((root->data) > item)
		root->left=insert(root->left,item);
	else
	{
		if(root->data < item)
			root->right=insert(root->right,item);
	}
	return root;
}

int main()
{
	int r,item,ch;
	struct node * root=(struct node *)malloc(sizeof(struct node));
	printf("Enter the root : ");
	scanf("%d",&r);
	root=create_node(r);
	printf("checking %d\n",root->data );
	do
	{
		printf("\n1. Insert \n 2. Inorder \n 3. Preorder\n 4. Postorder\n 5. Exit. \n");
		printf("\n\tEnter your choice :  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter element: \n");
				scanf("%d",&item);
				root=insert(root,item);
				break;
			case 2:
					printf("The inorder traversal is  ");
					inorder(root);
					break;
			case 3:
					printf("The preorder traversal is ");
					preorder(root);
					break;
			case 4:
					printf("The postorder traversal is  ");
					postorder(root);
					break;
			case 5:
					exit(1);
		}
	}while(ch!=5);
}