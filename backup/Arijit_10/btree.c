#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;	
};

struct node * createNode(int item)
{
	struct node * temp = (struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
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

}

struct node * search_parent(struct node  *root,int item)
{
	if(root->data==item)
		return root;
	else if(root->left!=NULL)
		return search_parent(root->left,item);
	else if(root->right!=NULL)
		return search_parent(root->right,item);
}

int insert(struct node **root,int item)
{
	if(NULL==*root){
		*root=createNode(item);
		printf("Root node set.\n");
	}
	else{
		int left_right,parent_data;
		struct node *temp=createNode(item);
		struct node * parent=NULL;
		printf("Enter the parent node : ");
		scanf("%d",&parent_data);
		parent=search_parent(*root,parent_data);
		printf("Press 1 to Insert at Left\n");
		printf("Press 2 to Insert at Right\n");
		scanf("%d",&left_right);
		if(left_right==1)
			parent->left=temp;
		else if(left_right==2)
			parent->right=temp;
		else
		{
			printf("\n\tInvalid choice.Exiting Insertion.");
			return 1;
		}
	}
	return 1;
}

int main()
{
	int ch=1,n;
	struct node* root1=NULL;
	struct node* root2=NULL;
	while (ch!=0)
	{
		printf("\n\tMENU::\n\t1.Insert\n\t2.Delete\n\t3.Display as Tree\n\t0.Exit\n\n\tEnter Choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:	printf("\n\tEnter number::");
			scanf("%d",&n);
			insert(&root,n);
			break;
		case 2: printf("\n\tEnter number::");
			scanf("%d",&n);
			//delete(&root,n);
			break;
		case 3:	printf("\n");
			display(&root,0);
			break;
		case 0: return 0;
			break;
		default:printf("\n\tInvalid Choice");
		}
	}

}