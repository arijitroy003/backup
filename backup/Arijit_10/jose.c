#include <stdio.h>
#include <stdlib.h>

struct node
{
	int d;
	struct node *next,*prev;
};


struct node * create1(struct node *p)
{
	int ch;
	struct node *root,*q;
	root=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data : ");
	scanf("%d",&root->d);
	root->prev=NULL;
	root->next=NULL;
	p=root;
	while(ch!=0)
	{
		printf("\nPress 1 to Insert more  :: Press 0 to complete list :  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				q=(struct node*)malloc(sizeof(struct node));
				printf("Enter the data : ");
				scanf("%d",&q->d);
				q->next=NULL;
				q->prev=root;
				root->next=q;
				root=q;
				break;
			case 0:
					root->next=p;
					p->prev=root;
					break;
		}
	}
	return p;
}

int josephus(int n, int k) 
{ 
  if (n == 1) 
    return 1; 
  else
    return (josephus(n - 1, k) + k-1) % n + 1; 
} 

void display(struct node *r)
{
   struct node *p,*q;
   p=r;
   q=r;
   if(r==NULL)
   	printf("Empty list");
   else
   {  
	   printf("\n\tThe Linked List is ");
	   while(p->next!=q)
	   {
	     printf("  %d  ",p->d);
	     p=p->next;
	   }
	   printf("  %d  ",p->d);
   }
   printf("\n");
}

int count(struct node *r)
 {
    int i=0;
    struct node *p,*q;
    p=r;
    q=r;
    while(p->next!=q)
    {
      ++i;
      p=p->next;
    }
    ++i;
	return i;
 }


struct node * execute(struct node * r,int k)
{
	int i;
	struct node *p,*q;
	p=r;
	for(i=0;i<k;i++)
		p=p->next;
	printf("\nDeleted element is %d\n",p->d );
	q=p->prev;
	p=p->next;
	q->next=p;
	p->prev=q;
	return p;	
}

struct node * shift(struct node *r,int pos)
{
	int i;
	struct node *p;
	p=r;
	while(p->d!=pos)
		p=p->next;

	return p;
}


int main()
{
	system("clear");
	printf("\n\n\t\t------------ Josephus Problem --------------\n\n\n");
	int ch,i,n,k,pos;
	struct node *r=NULL;
    struct node *x=NULL;
    
    r=create1(r);
    display(r);
    printf("Enter starting poistion : ");
    scanf("%d",&pos);
    r=shift(r,pos);
   
    printf("\n\n\tEnter value of k : ");
    scanf("%d",&k);
    n=count(r);
    printf("Therefore : n = %d  and k = %d and start = %d \n",n,k,pos);
  
    	while(count(r)!=1)
    	{
    		r=execute(r,k);
    		display(r);
    	}

    printf("\n");
   // printf("count %d\n",josephus(7,2) );

}