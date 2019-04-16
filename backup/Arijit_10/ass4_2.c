#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct qnode
{
	struct node *data;
	struct qnode *next;
};

int insert(struct node **root,int item);
int display(struct node **root,int level);

int notempty(struct qnode *front);
int queuein(struct qnode **rear,struct node *inp);
int queuedel(struct qnode **front);
struct node* bfs(struct node *root,int n);

int insert(struct node **root,int item)
{
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
		struct node *temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->left=NULL;
		temp->right=NULL;
		int n,ch;
		struct node *par=NULL;
		printf("\n\tDeclare the parent of the node::");
		scanf("%d",&n);
		par=bfs(*root,n);	

		if(par==NULL)
		{
			printf("\n\tItem not found in tree.");
			return 2;
		}	
		printf("\n\tEnter 1 if left child, 2 if right child:");
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
int notempty(struct qnode *front)
{
	if(front==NULL)
	{
		return 0;
	}
	else
		return 1;
}
int queuein(struct qnode **rear,struct node *inp)
{
	if(inp!=NULL)
	{
		struct qnode *temp=(struct qnode *)malloc(sizeof(struct qnode));
		temp->data=inp;
		temp->next=NULL;
		(*rear)->next=temp;
		*rear=temp;
	}
	return 0;
}
int queuedel(struct qnode **front)
{
	if(notempty(*front))
	{
		struct qnode *p=*front;
		(*front)=(*front)->next;
		free(p);
		p=NULL;
	}
	return 0;
}

struct node* bfs(struct node *root,int n)
{
	struct qnode *front=(struct qnode *)malloc(sizeof(struct qnode));
	front->data=root;
	front->next=NULL;
	struct qnode *rear=front;
	while(notempty(front))
	{
		queuein(&rear,(front->data)->left);
		queuein(&rear,(front->data)->right);
		if((front->data)->data==n)
			return (front->data);
		queuedel(&front);
	}
	return NULL;
}

int equivalent(struct node* a,struct node* b)  
{
    if (a == NULL && b == NULL)  
    	return 1;  
    if (a != NULL && b != NULL)  
    	return (a->data == b->data && equivalent(a->left, b->left) && equivalent(a->right, b->right));       
    
    return 0;  
}

int similar(struct node* a,struct node* b) 
{ 
    if (a==NULL && b==NULL) 
        return 1; 
     // both non-empty -> compare them  
    if (a!=NULL && b!=NULL) 
        return similar(a->left, b->left) && similar(a->right, b->right); 
    return 0; 
}

int main()
{
	int ch=1,n;
	struct node* root1=NULL;
	struct node* root2=NULL;
	while (ch!=0)
	{
		printf("\n\tMENU::\n\t1.Insert Tree 1\n\t2.Insert Tree 2\n\t3.Display Tree 1\n\t4.Display Tree 2\n\t5.Check Equivalence\n\t6.Check Similar\n\t0.Exit\n\tEnter Choice::");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	
				printf("\n\tEnter number::");
				scanf("%d",&n);
				insert(&root1,n);
				break;
			case 2:	
				printf("\n\tEnter number::");
				scanf("%d",&n);
				insert(&root2,n);
				break;	
			case 3: 
				printf("\n");
				display(&root1,0);
				break;
			case 4:
				printf("\n");
				display(&root2,0);
				break;
			case 5:
					if(equivalent(root1,root2))	
						printf("It is equivalent\n");
					else
						printf("It is not equivalent\n");
					break;
			case 6:
					if(similar(root1,root2))	
						printf("It is similar\n");
					else
						printf("It is not similar\n");
					break;	
			case 0: 
				return 0;
				break;
			default:printf("\n\tInvalid Choice");
		}
	}
	return 0;
}