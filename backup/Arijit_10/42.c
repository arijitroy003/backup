#include<stdio.h> 
#include<stdlib.h> 
#include <stdbool.h> 
int c=0;
struct node 
{ 
	int key; 
	struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	temp->key = item; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
/*struct node* insert(int data) 
{ 
    struct node* root = NULL; 
    root->key = data; 
    root->left = NULL; 
    root->right = NULL; 
    return(root); 
} */

struct node* insert(int data) 
{ 
	struct node *p; // node
    p = malloc(sizeof(struct node)); // allocating space to p
    p->key = data; // assinging data to p
    p->left = NULL; // making children NULL
    p->right= NULL;
    return(p); 
}  
int similar(struct node* a,struct node* b)  
{
    if (a == NULL && b == NULL)  return 1;  
    if (a != NULL && b != NULL)  
    return (a->key == b->key &&similar(a->left, b->left) && similar(a->right, b->right));       
    return 0;  
}
int similar2(struct node* a,struct node* b) 
{ 
    // 1. both empty  
    if (a==NULL && b==NULL) 
        return 1; 
  
    // 2. both non-empty -> compare them  
    if (a!=NULL && b!=NULL) 
    { 
        return 
		(
			similar2(a->left, b->left) 
			&& 
			similar2(a->right, b->right)
		); 
    } 
    return 0; 
}



int main() 
{ 
	/*
		   50 
		 /	  \ 
		30	  70 
		/ \   / \ 
	   20 40 60 80 */
	int n,a;
	struct node *root1 = insert(5),*root=insert(5);
	//root1->key=insert(5); 
	root1->left=insert(7); 
    root1->right =insert(15); 
    root1->left->left =insert(4); 
    root1->left->right =insert(9);  
    root1->right->right =insert(20); 
  
	
	root->left=insert(7); 
    root->right =insert(15); 
    root->left->left =insert(4); 
    root->left->right =insert(9);  
    root->right->right =insert(20); 
    
  	printf("\n2- Similar\n3- Equivalent\n");
	while(1)
	{
		printf("Choice:\n");
		scanf("%d",&n);
		switch(n)
		{		
			//case 1:	printf("Input:\n"); scanf("%d",&n); insert(root,n); break;
			case 2: 
					if(similar2(root,root1))	
						printf("It is similar\n");
					else
						printf("It is not similar\n");
					break;			
			case 3: 
					if(similar(root,root1))	
						printf("It is equivalent\n");
					else
						printf("It is not equivalent\n");
					break;
			default: exit(1);			
		}			
	}	 
}
