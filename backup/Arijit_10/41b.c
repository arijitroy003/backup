#include <stdio.h> 
#include <stdlib.h>  

struct node 
{ 
	int data; 
	struct node* left; 
	struct node* right; 
}; 

int bst(struct node* node, int min, int max) 
{
	if (node==NULL) return 1; 
	if (node->data < min || node->data > max) 	return 0; 			
	return	bst(node->left, min, node->data-1) && bst(node->right, node->data+1, max);
} 
struct node* newNode(int data) 
{ 
	struct node* node = (struct node*)malloc(sizeof(struct node)); 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 	
	return node; 
}
int main() 
{ 
	struct node *root = newNode(4); 
	root->left=newNode(2); 
	root->right=newNode(5); 
	root->left->left=newNode(1); 
	root->left->right=newNode(3); 	
	if(bst(root,0,100)) 
		printf("It is Binary Search Tree"); 
	else
		printf("It is not a Binary Search Tree"); 
} 
