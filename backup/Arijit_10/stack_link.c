#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10
int stack_count;

struct node
{
	int data;
	struct node *down; 
};

struct stack
{
	int index;
	int top;
	int size;
	struct node *down;
	struct stack *next;
};

struct stack *head=NULL;

struct stack *create_stack(int n)
{
	struct stack *temp;
	temp=(struct stack *)malloc(sizeof(struct stack));
	temp->top=-1;
	temp->size=n;
	temp->index=++stack_count;
	//printf("Enter element for stack %d : ",++stack_count);
	temp->down=NULL;
	temp->next=NULL;
	return temp;
}

void create(int n)
{
	struct stack *p;
	p=head;
	if(head==NULL)
		head=create_stack(n);
	else
	{
		while(p->next!=NULL)
			p=p->next;
		p->next=create_stack(n);
	}
}
void push(struct stack *stk,int item)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=item;
	temp->down=NULL;
}

void pop(struct stack *stk)
{
	
}

void display_stack(struct stack *root)
{
	struct stack *temp;
	if(root==NULL)
		printf("Stack is empty\n");
	else
	{
		temp=root;
		while(temp!=NULL)
		{
			printf(" %d",temp->data);
			temp=temp->down;
		}
	}
}

int main()
{
	struct stack *root;
	root=create_stack(root);

	display_stack(root);
}