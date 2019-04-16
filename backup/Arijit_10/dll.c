#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *next,*prev;
};
struct node *head;

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
		}
	}
	return p;
}

void display(struct node *r)
{
   struct node *p;
   if(r==NULL)
   printf("Empty list");
   else
   {  
	   p=r;
	   printf("\n\tThe Linked List is ");
	   while(p!=NULL)
	   {
	       
	     printf("  %d  ",p->d);
	     p=p->next;
	   }
   }
}

struct node* insert_befor_nth(struct node *r)
{
	int i,p,f=0;
	struct node *s,*q;
	s=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter data for the node: ");
    scanf("%d",&q->d);
	
	printf("Eter a position before which we insert node : ");
	scanf("%d",&p);
	if(p==1)
	{
		q->next=s;
		s->prev=q;
		s=q;
	}
	else
	{
		for(i=1;i<=p-2;++i)
		{
			s=s->next;
			if(s==NULL)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
		    printf("POSITION not found");
	        free(q); 
		}
		else
		{
			q->next=s->next;
			s->next=q;
			q->prev=s;
			q->next->prev=q;
		}
	}
	return r;
}

struct node* insert_befor_ele(struct node *r)
{
	int f=0,a;
	struct node *p,*s,*q;
	p=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
    scanf("%d",&q->d);
	//q->next='\0';
	printf("Enter element before which we are going to insert a node : ");
	scanf("%d",&a);
	if(p->d==a)
	{
		q->next=p;
		p->prev=q;
		p=q;
	}
	else
	{
		while(p->next->d!=a)
		{
			p=p->next;
			if(p==NULL)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			printf("Data not found");
	        free(q);
		}
		else
		{
			q->next=p->next;
			p->next=q;
			q->prev=p;
			q->next->prev=q;
		}
	}
	return r;
}

struct node* delete_befor_nth(struct node *r)
{
	int i,k,f=0;
	struct node *p,*q;
	p=r;
	printf("Eter a position before which we delete a node : ");
	scanf("%d",&k);
	if(k==1)
		printf("Nothing exists to delete!");
	if(k==2)
	{
		q=p->next;
		p->next=NULL;
		q->prev=NULL;
		r=q;
		free(p);
	}
	else
	{
		for(i=1;i<=k-3;++i)
		{
			p=p->next;
			if(p==NULL)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
		    printf("POSITION not found");
	        free(q); 
		}
		else
		{
			q=p->next;
			p->next=q->next;
			q->next=NULL;
			free(q);
		}
	}
	return r;
} 

struct node*delete_befor_ele(struct node *r)
{
	int i,k,f=0;
	struct node*p,*q,*w;
	printf("Enter an element and before that element will be deleted :");
	scanf("%d",&k);
	w=r;
	p=w->next;
	if(r==NULL)
	printf("Nothing to delete!");
	else
	{
		if(w->d==k)
		printf("There is no element to delete!");
	}
	if(p->d==k)
	{
		w->next=p->next;
		p->next=NULL;
		free(p);
	}
	else
	{
		while(p->next->d!=k)
		{
			w=w->next;
			p=p->next;
			if(p->next==NULL)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		printf("Data not found");
		else
		{
			w->next=p->next;
			p->next=NULL;
			free(p);
		}
	}
	return r;
}

struct node* merge_and_sort(struct node*r,struct node*x)
	{
		int f,i,t;
		struct node *p,*q,*s;
		x=create1(x);
		p=r;
		if(r==NULL)
		r=x;
		else
		{
			while(p->next!=NULL)
			p=p->next;
			p->next=x;
		}
		s=NULL;
		if(q==NULL)
			printf("Empty list");
		do
		{
			f=0;
			q=r;
			while(q->next!=s)
			{
				if(q->d>=q->next->d)
				{
					t=q->d;
					q->d=q->next->d;
					q->next->d=t;
					f=1;
				}
				q=q->next;
			}
			s=q;
		}while(f);
		return r;
	}


int main()
{
	system("clear");
	printf("\n\n\t\t------------ Double Linked List --------------\n\n\n");
    int ch,t;
    struct node *r=NULL;
    struct node *x=NULL;
    while(1)
    {
    	printf("\n\n1.Create linked list \n2.Print the list \n3.Insert an element m before nth element\n4.Insert an element m before n\n5.Delete element present before nth element \n6.Delete element present before a node n \n7.Merge two lists in ascending order \n8.Exit\n\n");
    	printf("\n\n\tEnter your choice: ");
	    scanf("%d",&ch);
	    switch(ch)
	    {
	   		case 1:
	   			r=create1(r);
	   			break;
	   		case 2:
	   			display(r);
	   			break;
	   		case 3:
	   			r=insert_befor_nth(r);
     			display(r);
          		break;
          	case 4:
          		r=insert_befor_ele(r);
          		display(r);
          		break;
          	case 5:
          		r=delete_befor_nth(r);
            	display(r);
            	break;
            case 6:
            	r=delete_befor_ele(r);
                display(r);
            	break;
            case 7:
            	r=merge_and_sort(r,x);
            	display(r);
            	break; 
	   		case 8:
	   			exit(1);
	   			break;
	    }
	}
}