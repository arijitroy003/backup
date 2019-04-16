// C program to check if all leaves are at same level 
#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node *left, *right; 
}; 

// A utility function to allocate a new tree node 
struct Node* newNode(int data) 
{ 
	struct Node* node = (struct Node*) malloc(sizeof(struct Node)); 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

bool checkUtil(struct Node *root, int level, int *leafLevel) 
{ 
	if (root == NULL) return true; 
	if (root->left == NULL && root->right == NULL) 
	{ 
		if (*leafLevel == 0) 
		{ 
			*leafLevel = level; // Set first found leaf's level 
			return true; 
		} 
		return (level == *leafLevel); 
	} 
	return checkUtil(root->left, level+1, leafLevel) && checkUtil(root->right, level+1, leafLevel); 
} 

bool check(struct Node *root) 
{ 
int level = 0, leafLevel = 0; 
return checkUtil(root, level, &leafLevel); 
} 

int main() 
{ 
	
	struct Node *root = newNode(12); 
	root->left = newNode(5); 
	root->left->left = newNode(3); 
	root->left->right = newNode(9); 
	root->left->left->left = newNode(1); 
	root->left->right->left = newNode(1); 
	if (check(root)) 
		printf("Leaves are at same level\n"); 
	else
		printf("Leaves are not at same level\n"); 
	getchar(); 
	return 0; 
} 

