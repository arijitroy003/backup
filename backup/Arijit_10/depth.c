#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	// int depth;
	struct node *left;
	struct node *right;
};
struct node * dfs(struct node *root,int n)
{
	if(root->data==n)
		return root;
	{
		if(root->right!=NULL)
			return dfs(root->right,n);
		if(root->left!=NULL)
			return dfs(root->left,n);
	}	
	
}

int display(struct node **root,int level)
{
	int i=0;
	if(*root==NULL)
		return 0;
	display(&(*root)->right,level+1);
	for(i=0;i<=level;i++)
		printf("\t");
	printf("%d\n",(*root)->data);
	display(&(*root)->left,level+1);
	return 1;
}


int isBST(struct node* node)  
{  
  if (node == NULL)  
    return 1;  

  if (node->left != NULL && node->left->data > node->data)  
    return 0;  

  if (node->right != NULL && node->right->data < node->data)  
    return 0;  
  
  if (!isBST(node->left) || !isBST(node->right))  
    return 0;  
 
  return 1;  
} 


int insert(struct node **root,int item)
{
	int ch;
	if(*root==NULL)
	{
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->left=NULL;
		temp->right=NULL;
		*root=temp;
		printf("\n\tRoot Set\n");
	}
	else
	{
		struct node *par = NULL;
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->left=NULL;
		temp->right=NULL;
		printf("Enter the parent node : ");
		int parent;
		scanf("%d",&parent);
		par=dfs(*root,parent);
		if(par==NULL)
		{
			printf("\n\tItem not found in tree.");
			return 2;
		}	
		printf("Enter 1 for LEFT child or 2 for RIGHT child ? \n");
		scanf("%d",&ch);
		if(ch==1)
		{
			if(par->left==NULL)
				par->left=temp;
			else
				printf("\n\tChild already present.");
		}
		else if(ch==2)
		{
			if(par->right==NULL)
				par->right=temp;
			else
				printf("\n\tChild already present.");
		}
		else
		{
			printf("\n\tInvalid choice.Exiting Insertion.");
			return 3;
		}
	}
	return 0;
}

int CheckFull(struct node * root)
{

}

int main()
{
	struct node *root=NULL;
	int ch,i,item;
	do{
		printf("\n1. INSERT\n2. DISPLAY\n3. Check depth\n4. Check if BST or NOT\n5. Exit");
		printf("\n\tEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					printf("\n\tEnter number : ");
					scanf("%d",&item);
					insert(&root,item);
					break;
			case 2:	
					printf("\n");
					display(&root,0);
					break;
			case 4:
					if(isBST(root))
						printf("It is a Binary Search Tree.\n");
					else
						printf("It is a NOT Binary Search Tree.\n");
					break;
			case 5:
					exit(1);
			default:
					printf("\n\tInvalid Choice");
					break;
		}
	}while(ch!=5);
}
