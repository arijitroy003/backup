#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};

// struct node *root;

struct node * create(struct node *root)
{
	if(root==NULL){
		int item;
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		printf("Enter number to insert : ");
		scanf("%d",&item);
		temp->data=item;
		temp->next=NULL;
		root=temp;
		return root;	
	}
		
}

void display(struct node *root)
{
	struct node *p;
	p=root;
	printf("Linked list  ");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n\n\n");
}

struct node *insert_end(struct node *root)
{
	int item;
	struct node *temp,*p;
	p=root;
	if(root==NULL)
		root=create(root);
	else
	{
		while(p->next!=NULL)
			p=p->next;
		printf("Enter number to insert : ");
		scanf("%d",&item);
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=item;
		temp->next=NULL;
		p->next=temp;
		return root;
	}
}

void insert_begin(struct node **root,int item)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	temp->data=item;
	temp->next=*root;
	*root=temp;
}

void ordered(struct node *root)
{
	struct node *p=root;
	if(root==NULL)
		printf("Ordered.\n");
	else if(p->data >= p->next->data )
	{
		while(p->next!=NULL)
		{
			if(p->data < p->next->data){
				printf("Not Ordered.\n");
			}
			p=p->next;
		}
	}
	else if(p->data <= p->next->data)
	{
		while(p->next!=NULL)
		{
			if(p->data > p->next->data){
				printf("Not Ordered.\n");
			}
			p=p->next;
		}
	}
	else
			printf("Ordered.\n");
}

void reverse(struct node **root)
{
	struct node *prev=NULL,*next=NULL;
	struct node * curr=*root;
	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;

		curr=next;
	}
	*root=prev;
}

int main()
{
	int ch,item;
	struct node *  root=NULL;
	while(1)
	{
		printf("1. Create 2. insert_end 3. display 4. insert_begin\n");
		printf("Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				root=create(root);
				break;
			case 2:
				root=insert_end(root);
				break;
			case 3:
				display(root);
				break;
			case 4:
				printf("Enter number to insert : ");
				scanf("%d",&item);
				insert_begin(&root,item);
				break;
			case 5:
				ordered(root);
				break;

			case 6:
				reverse(&root);
				display(root);
				break;
			case 0:
				exit(1);
		}
	}

	
}