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
void inorder(struct node *root) 
{ 
	if (root != NULL) 
	{ 
		inorder(root->left); 
		printf("%d \n", root->key); 
		inorder(root->right); 
	} 
} 
struct node* insert(struct node* node, int key) 
{ 
	if (node == NULL) return newNode(key); 
	if (key < node->key) 
		node->left = insert(node->left, key); 
	else if (key > node->key) 
		node->right = insert(node->right, key); 
	return node; 
} 

struct node* search(struct node* root, int key) 
{ 
	if (root==NULL||root->key == key) 
	return root; 	
	if (root->key < key) 
	return search(root->right, key); 
	return search(root->left, key); 
} 

int countl(struct node *temp)
{
	if(temp==NULL)
	return 0;
	return 1+countl(temp->left);
}
int countr(struct node *temp)
{
	if(temp==NULL)
	return 0;
	return 1+countr(temp->right);
}
int count(struct node* node)  
{  
    if(node == NULL)      
        return 0;  
    if(node->left == NULL && node->right == NULL)  
        return 1;         
    else
        return count(node->left)+count(node->right);  
} 

int fullCount(struct node* root) 
{ 
    if (root == NULL) 
       return 0; 
   
    int res = 0; 
    if  (root->left && root->right)  
       res++; 
   
    res += (fullCount(root->left)+fullCount(root->right)); 
    return res; 
}

bool ancestors(struct node *root, int target) 
{ 
  if (root == NULL)
     return false; 
  
  if (root->key == target) 
     return true;
  if(ancestors(root->left, target)||ancestors(root->right, target))
  { 
    c++;
    return true; 
  } 
  return false;
  
}
int desc(struct node*root)
{
	if(root==NULL)
		return 0;
	if(root->left!=NULL)
	{
		c=c+1;
		c=desc(root->left);
	}
	if(root->right!=NULL)
	{
		c=c+1;
		c=desc(root->right);
	}
	return c;
}



struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left; 
    return current; 
} 



struct node* deleteNode(struct node* root, int key) 
{ 
    
    if (root == NULL) return root; 
  

    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  

    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
  
    else
    { 
     
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        
        struct node* temp = minValueNode(root->right); 

        root->key = temp->key; 
  
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
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
	printf("Create a node, Enter the root:\n");
	struct node *root = NULL,*temp; 
	//scanf("%d",&n);
	n=50;
	root = insert(root,n); 
	insert(root, 30); insert(root, 20); insert(root, 40); insert(root, 70); insert(root, 60); insert(root, 80); 
	printf("1. Insert \n2. Delete\n3. Finding an element\n4. Finding min element\n4. Finding max element \n5. Finding max element \n6. Left child of the given node\n");
	printf("7. Rightchild of the given node\n8. Find no. of nodes leaves node full nodes ancestor descendants\n");
	while(1)
	{
		printf("Choice:\n");
		scanf("%d",&n);
		switch(n)
		{		
			case 1:	printf("Input:\n"); 
					scanf("%d",&n); 
					insert(root,n); 
					break;
			case 2: printf("Enter deleted element:\n"); scanf("%d",&n); 
					printf("\nBefore: \n");
					inorder(root);
					root = deleteNode(root,n);
					printf("\nAfter: \n");
					inorder(root);
					printf("\n\n");
					break;
			case 3: printf("Search element:\n"); scanf("%d",&n); 
					if(search(root,n)) 
						printf("Found\n");
					else 
						printf("Not Found\n");
					break;
			case 4: temp=root;
					while(temp->left!=NULL)
					temp=temp->left;
					printf("Minimum element is: %d\n",temp->key);
					break;
			case 5: temp=root;
					while(temp->right!=NULL)
					temp=temp->right;
					printf("Maximum element is: %d\n",temp->key);
					break;
			case 6: temp=root;
					printf("Left child:\n"); scanf("%d",&n); 
					while(temp!=NULL&&temp->key!=n)
					{	
						if(n<temp->key) temp=temp->left;
						else temp=temp->right;
					}
					printf("Left child is: %d\n",temp->left->key);
					break;
			case 7: temp=root;
					printf("Right child:\n"); scanf("%d",&n); 
					while(temp!=NULL&&temp->key!=n)
					{	
						if(n<temp->key) temp=temp->left;
						else temp=temp->right;
					}
					printf("Left child is: %d\n",temp->right->key);
					break;
			case 8: printf("No. of nodes: %d\n",countl(root)+countr(root)+1);
					printf("No. of leaf nodes: %d\n",count(root));
					printf("No. of Full nodes: %d\n",fullCount(root));
					//printf("Enter ancestors element:\n"); scanf("%d",&n); 
					//ancestors(root,n); printf("Anccestors: %d\n",c); printf("\n");
					printf("Enter descendants element:\n"); scanf("%d",&n);
					temp=root;
					//printf("Temp-Key %d\n",temp->key);
					while(temp!=NULL&&temp->key!=n)			
					{
						if(n>temp->key)	temp=temp->right;
						else temp=temp->left;
					}
					if(temp!=NULL)
					c=0;
					printf("Descendant: %d\n",desc(temp)); printf("\n");					
					break;
			default: inorder(root); exit(1);			
		}			
	}	 
} 

