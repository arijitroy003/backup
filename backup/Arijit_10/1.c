#include<stdio.h>
#include<stdlib.h>
struct node
{
	int d;
	struct node *next;
};
struct node *head;
struct node* create1(struct node *r)
{
  int n,i;
  struct node *p,*q;
  // printf("Enter the number of items: ");
  // scanf("%d",&n);
  printf("\nEnter the data : ");
  //p=(struct node*)malloc(sizeof(struct node));
  // if(n==1)
  // {
     p=(struct node*)malloc(sizeof(struct node));
     scanf("%d",&p->d);
     p->next=NULL;
     r=p;
     return r;
  // }
  // else
  // {
  //    r=(struct node*)malloc(sizeof(struct node));
  //    scanf("%d",&r->d);
  //    r->next=NULL;
  //    q=r;
  //    for(i=1;i<n;++i)
  //    {
  //      p=(struct node*)malloc(sizeof(struct node));
  //      scanf("%d",&p->d);
  //      p->next=NULL;
  //      q->next=p;
  //      q=q->next;
  //    }
  // }  
     
}
struct node* create(struct node *r)
{
  int n,i;
  struct node *p,*q;
   printf("Enter the number of items: ");
   scanf("%d",&n);
  printf("\nEnter the data : ");
  p=(struct node*)malloc(sizeof(struct node));
   if(n==1)
   {
     p=(struct node*)malloc(sizeof(struct node));
     scanf("%d",&p->d);
     p->next=NULL;
     r=p;
     return r;
  }
  else
  {
     r=(struct node*)malloc(sizeof(struct node));
     scanf("%d",&r->d);
     r->next=NULL;
     q=r;
     for(i=1;i<n;++i)
     {
       p=(struct node*)malloc(sizeof(struct node));
       scanf("%d",&p->d);
       p->next=NULL;
       q->next=p;
       q=q->next;
     }
   }  
     return r;
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
 int count(struct node *r)
 {
    int i=0;
    struct node *p;
    p=r;
    while(p!=NULL)
    {
      ++i;
      p=p->next;
    }
    //printf("%d",i);
	return i;
  }
void order(struct node*r)
{
   struct node*p;
   p=r;
   int f=0;
   if(p->d>=p->next->d)
   {
     p=p->next;
     while(p->next!=NULL)
     {
        if(p->d<=p->next->d)
        { 
          f=1;
          break;
        }
        p=p->next;
     }
   }
   else
   {
    p=p->next;
    while(p->next!=NULL)
    {
      if(p->d>=p->next->d)
      { 
        f=1;
        break;
      }
      p=p->next;
    }
   }
   if(f==0)
   printf("\n\tList is ordered");
   else
   printf("\n\tList is not ordered");
               
}
void equal(struct node *p,struct node *r)
	{
	    struct node *q;
		int f=0;
		q=r;
		do
		{
		    if(p->d!=q->d)
		    {
		    	f=1;
		    	break;
		    }
		    p=p->next;
		    q=q->next;
		}while((p!='\0')&&(q!='\0'));
		if(f==0)
		printf("\n\tLists are equal");
		else
		printf("\n\tLists are not equal ");	
	}

void concate()
{

	int n,i,f=0;
    struct node *p,*q,*head1;
    printf("enter the number of item of first linked list:  ");
    scanf("%d",&n);
	printf(" enter the data: \n");
    if(n==1)
    {
    p=(struct node *)malloc(sizeof(struct node));
     scanf("%d",&p->d);
     p->next=NULL;
     head1=p;

 }
 else
 {
     head1=(struct node *)malloc(sizeof(struct node));
      scanf("%d",&head1->d);
  head1->next=NULL;
  q=head1;
  for(i=1;i<n;i++)
  {
      p=(struct node *)malloc(sizeof(struct node));
         scanf("%d",&p->d);
       p->next=NULL;
       q->next=p;
       q=q->next;
  }
}

      int n1,i1;
      struct node *p1,*q1,*head2;
      printf("\nEnter the number of item of second linked list:  ");
      scanf("%d",&n1);
      printf(" Enter the data: \n");
      if(n1==1)
      {
       p1=(struct node *)malloc(sizeof(struct node));
       scanf("%d",&p1->d);
       p1->next=NULL;
       head2=p1;

      }
      else
      {
       head2=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&head2->d);
      head2->next=NULL;
      q1=head2;
      for(i=1;i<n1;i++)
      {
        p1=(struct node *)malloc(sizeof(struct node));
           scanf("%d",&p1->d);
         p1->next=NULL;
         q1->next=p1;
         q1=q1->next;
      }
      
  }
  struct node*s=head1;
	if(s==NULL)
		s=head2;
	while(s->next!=NULL)
	{  
	  s=s->next;
	}
	s->next=head2;

	struct node *t;
      t=head1;
          while(t!=NULL)
          {
              printf(" \t%d",t->d);
              t=t->next;
          }
}
struct node* insertfornt(struct node *r)
{
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for newly created node : ");
	scanf("%d",&p->d);
	p->next=r;
	r=p;
	return r;
}
struct node* insertlast(struct node *r)
{
	struct node*p,*q;
	p=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element for a single node : ");
	scanf("%d",&q->d);
	q->next='\0';
	while(p->next!='\0')
	p=p->next;
	p->next=q;
	return r;
}
struct node* insert_after_nth(struct node *r)
{
	int i,k,f=0;
	struct node*p,*q;
	p=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
	scanf("%d",&q->d);
	/*printf("Enter the position after which the node will be inserted: ");
	scanf("%d",&q->d);*/
	//q->next='\0';
	printf("Enter the position after which the node will be inserted : ");
	scanf("%d",&k);
	
	if(k==1)
	{
		q->next=p->next;
		p->next=q;
	}
	else
	{
		for(i=1;i<=k-1;++i)
		{
			p=p->next;
			if(p==NULL)
			{
				f=1;
				break;
			}
		}
	}
	if(f==1)
	{
		printf("position not found");
		free(q);
	}
	else
	{
		q->next=p->next;
		p->next=q;
	}
	return r;
}
struct node*insert_after_ele(struct node *r)
{
	int k,a,f=0;
	struct node *p,*q;
	p=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
    scanf("%d",&q->d);
	//q->next='\0';
	printf("Eter a value after which we want to insert : ");
	scanf("%d",&a);
	while(p->d!=a)
	{
		p=p->next;
		if(p==NULL)
		{
			f=1;break;
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
	}
	return r;  
}
struct node* insert_befor_nth(struct node *r)
{
	int i,p,f=0;
	struct node *s,*q;
	s=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
    scanf("%d",&q->d);
	//q->next='\0';
	printf("Eter a position before which we insert node : ");
	scanf("%d",&p);
	if(p==1)
	{
		q->next=s;
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
		}
	}
	return r;
}
struct node* delet_first(struct node *r)
{
	struct node *p,*q;
	p=r;
	if(p==NULL)
	printf("List is empty");
	else
	{
		q=p->next;
		p->next=NULL;
		r=q;
		free(p);
	}
	return r;
}
struct node* delet_last(struct node *r)
{
	struct node *p,*q;
	p=r;
	if(r==NULL)
	printf("Empty list");
	else
	{
		while(p->next->next!=NULL)
		p=p->next;
		q=p->next;
		p->next=NULL;
		free(q);
	}
	return r;
}
struct node* delet_after_nth(struct node *r)
{
	int i,k,f=0;
	struct node*p,*q;
	p=r;
	printf("Enter the position after which the node will be deleted : ");
	scanf("%d",&k);
	if(k==1)
	{
		q=p->next;
		p->next=q->next;
		q->next=NULL;
		free(q);
	}
	else
	{
		for(i=0;i<=k-1;++i)
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
		printf("position not found");
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
struct node* delete_after_ele(struct node *r)
{
	int a,f=0;
	struct node *p,*q;
	p=r;
	printf("Eter a value after which we want to delet : ");
	scanf("%d",&a);
	while(p->d!=a)
	{
		p=p->next;
		if(p==NULL)
		{
			f=1;break;
		}
	}
	if(f==1)
	{
		printf("Data not found");
	} 
	else
	{
		q=p->next;
		p->next=q->next;
		q->next=NULL;
		free(q); 
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
	printf("Nothing exists to delet!");
	if(k==2)
	{
		q=p->next;
		p->next=NULL;
		//p->next=q->next;
		//q->next=NULL;
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
struct node*rev(struct node*r)
{
	int i,k,j,l,t;
	struct node*p,*q;
	p=r;
	q=r;
	l=count(r);
	i=0;
	j=l-1;
	if(r==NULL)
	printf("list is empty");
	else
	{
		while(i<j)
		{
			k=0;
			while(k<j)
			{
				q=q->next;
				k++;
			}
			t=p->d;
			p->d=q->d;
			q->d=t;
			i++;
			j--;
			p=p->next;
			q=r;
		}
	}
	return r;
}
void search(struct node*r)
{
	int i=1,k;
	struct node*p;
	p=r;
	printf("\nEnter the element to be searched : ");
	scanf("%d",&k);
	while(p->d!=k)
	{
		i++;
		p=p->next;
	}
	printf("Element %d found at %d th node.",k,i);
	
}
struct node* merge_and_sort(struct node*r,struct node*x)
	{
		int f,i,t;
		struct node *p,*q,*s;
		x=create(x);
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
	printf("\n\n\t\t------------ Single Linked List --------------\n\n\n");
  int ch,t;
  struct node *r,*p,*q,*x;
  r=NULL;
  p=NULL;
  x=NULL;
  q=NULL;
  while(1)
  {
  printf("\n\n1.Create linked list \n2.Print the list \n3.Count the number of elements \n4.Check order \n5.Check for equal or not \n6.Concate two lists \n7.Insert at front \n8.Insert at end \n9.Insert after nth position \n10.Insert after a value \n11.Insert before nth position \n12.Insert before a value \n13.Delete 1st node \n14.Delete last node \n15.Delete a node after nth element \n16.Delete a node after an element \n17.Delete element present before nth element \n18.Delete element present before a node n \n19.Reverse linked list\n20.Search for a element\n21.Merge two lists \n22.Exit");
  printf("\n\n\tEnter your choice: ");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:r=create1(r);
           break;
    case 2:display(r);
           break;        
    case 3:
    		printf("The number of elements is %d\n",count(r));
           break;
    case 4:
    		order(r);
           break;
    case 5:printf("Input data for another list : ");
	   		p=create(p);
           display(p);
	   		equal(p,r);
           break;
    case 6:
           concate();
           break;
    case 7://printf("Input data for  list : ");
             r=insertfornt(r);
             display(r);
             break;
    case 8:r=insertlast(r);
          display(r);
          break; 
    case 9:r=insert_after_nth(r);
           display(r);
           //insert_afterpos();
          break;
    case 10:r=insert_after_ele(r);
           display(r);
          break;
    case 11:r=insert_befor_nth(r);
     		display(r);
          break;
    case 12:r=insert_befor_ele(r);
         display(r);
          break;
     case 13:r=delet_first(r);
            display(r);
            break;
      case 14:r=delet_last(r);
       display(r);
            break;
       case 15:r=delet_after_nth(r);
       display(r);
            break; 
      case 16:r=delete_after_ele(r);
       display(r);
            break;
      case 17:r=delete_befor_nth(r);
           display(r);
            break;
      case 18:r=delete_befor_ele(r);
                    display(r);
            break; 
      case 19:r=rev(r);
              display(r);
            break;
    case 20:
            search(r);
             break;
    case 21:
            r=merge_and_sort(r,x);
            display(r);
            break;                               
    case 22:exit(1);              
  }
  }
  return 0;
}  
