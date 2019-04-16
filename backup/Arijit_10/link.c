#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};


struct node * createNode(struct node *p,int key)
{
	p=(struct node *)malloc(sizeof(struct node));
	p->data=key;
	p->next=NULL;
	printf("Start Node Created\n");
	return p;
}

void printList(struct node *p)
{
	printf("\n\nThe elements of the list are  ");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n\n");
}

int count(struct node *p)
{
	int c=0;
	while(p!=NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}

void insertBegin(struct node **p,int key)
{
	struct node *q;
	q=(struct node *)malloc(sizeof(struct node));
	q->data=key;
	q->next=*p;
	*p=q;
}

void insertEnd(struct node *p,int key)
{
	struct node *q;
	while(p!=NULL)
	{
		p=p->next;
	}
	q=(struct node *)malloc(sizeof(struct node));
	q->data=key;
	q->next=NULL;
	p->next=q;
}
int ordered(struct node *p)
{

}
int main()
{
	system("clear");
	printf("\n\n\t\t------------ Single Linked List --------------\n\n\n");
	int ch,key;
	struct node *root;

	do{
			
			 printf("\n\n 1. Create Linked List \n 2. Display the list \n 3. Count the number of elements in the list\n 4. Check whether a given list is ordered or not \n 5. Check whether two lists are equal or not \n 6. Concatenate two lists \n 7. Insert at Beginning \n 8. Insert at End \n 9. Insert integer 'm' after nth element \n 10. Insert integer 'm' after 'n' element \n 11. Insert integer 'm' before nth element \n 12. Insert integer 'm' before 'n' element \n");
			 printf("\n\nEnter your choice :  ");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1: 
						printf("Enter your element : ");
						scanf("%d",&key);
						root=createNode(root,key);
						break;
				case 2:
						printList(root);
						break;
				case 3: 
						printf("Number of elements in the list : %d",count(root));
						break;
				case 4:	
						if(ordered(root)==1)
							printf("List is ordered.\n");
						else
							printf("List is unordered.\n");
						break;
				case 5:
						break;
				case 6:
						printf("Enter your element : ");
						scanf("%d",&key);
						insertBegin(&root,key);
						break;
				case 7:
						printf("Enter your element : ");
						scanf("%d",&key);
						insertEnd(root,key);
						break;
				case 0:
						printf("Exiting ...\n");
						exit(1);
						break;


				default:
						printf("Please enter valid input.\n");
						break;
			}
	}while(1);
}