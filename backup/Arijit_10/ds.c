#include<stdio.h>
// two list are equal or not
int main()
{
	p='\0';
	case 5: 
	       printf("Input data for another list : ");
	       p=create(p);
	       equal(p,r);
	       break;
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
		printf("Lists are equal");
		else
		printf("Lists are not equal ");	
	}       
}
//concate two list
 struct node *s;
 s='\0';
case 6: 
	       printf("Input data for another list : ");
           s=create(s);
           r=concate(r,s);
           break;
struct node*concate(struct node *r,struct node *s)
{
	struct node*p=r;
	if(r='\0')
	r=s;
	else
	{
		while(p->next!='\0')
		p=p->next;
		p->next=s;
	}
	return r;
}
//insert element at the begining of the list
r=insertfornt(r);
struct node*insertfornt(struct node *r)
{
	struct node*p;
	p=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for newly created node : ");
	scanf("%d",&p->d);
	p->next=r;
	r=p;
	return r;
}           
//insert element at the end of the list
struct node*insertlast(struct node *r)
{
	struct node*p,*q;
	p=r;
	q
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter the element for a single node : ");
	scanf("%d",&q->d);
	q->next='\0';
	while(p->next!='\0')
	p=p->next;
	p->next=q;
	return r;
}
//insert an element m after nth element
r=insert_after_nth(r);
struct node*insert_after_nth(struct node *r)
{
	int i,k,f=0;
	struct node*p,*q;
	p=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
	scanf("%d",&q->d);
	/*printf("Enter the position after which the node will be inserted: ");
	scanf("%d",&q->d);*/
	q->next='\0';
	printf("Enter the position after which the node will be inserted : ");
	scanf("%d",&k);
	if(k==1)
	{
		q->next=p->next;
		p->next=q;
	}
	else
	{
		for(i=0;i<=k-1;++i)
		{
			p=p->next;
			if(p='\0')
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
//insert m after n
r=insert_after_ele(r);
struct node*insert_after_ele(struct node *r)
{
	int k,a,f=0;
	struct node *p,*q;
	p=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
    scanf("%d",&q->d);
	q->next='\0';
	printf("Eter a value after which we want to insert : ");
	scanf("%d",&a);
	while(p->d!=a)
	{
		p=p->next;
		if(p=='\0')
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
//insert an integer m before nth element 
r=insert_befor_nth(r);
struct node*insert_befor_ele(struct node *r)
{
	int i,p,f=0;
	struct node *s,*q;
	s=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
    scanf("%d",&q->d);
	q->next='\0';
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
//insert m before n
r=insert_befor_ele(r);
struct node*insert_befor_nth(struct node *r)
{
	int f=0,a;
	struct node *p,*s,*q;
	p=r;
	q=(struct node*)malloc(sizeof(struct node));
	printf("Enter a no. for a node: ");
    scanf("%d",&q->d);
	q->next='\0';
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
//delet first node
r=delet_first(r);
struct node*delet_first(struct node *r)
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
//delet last node
r=delet_last(r);
struct node*delet_last(struct node *r)
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
//delete after nth element
r=delet_after_nth(r);
struct node*delet_after_nth(struct node *r)
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
			if(p='\0')
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
//delet present element after an element n
r=delete_after_ele(r);
struct node*delete_after_ele(struct node *r)
{
	int a,f=0;
	struct node *p,*q;
	p=r;
	printf("Eter a value after which we want to delet : ");
	scanf("%d",&a);
	while(p->d!=a)
	{
		p=p->next;
		if(p=='\0')
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
//delet before nth element
r=delete_befor_nth(r);
struct node*delete_befor_ele(struct node *r)
{
	int i,k,f=0;
	struct node *p,*q;
	s=r;
	printf("Eter a position before which we delete a node : ");
	scanf("%d",&k);
	if(k==1)
	printf("Nothing exists to delet!");
	if(k==2)
	{
		q=p->next;
		p->next=q->next;
		q->next=NULL;
		free(q);
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
//delete present element before element n
r=delete_befor_ele(r);
struct node*delete_befor_nth(struct node *r)
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
	else if(p->d==k)
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
//revese linked list
r=rev(r);
struct node*rev(struct node*r)
{
	int i,k,j,l,t;
	struct node*p,*q;
	p=r;
	q=r;
	l=count(r);
	i=0;
	j=l-1;
	if(r=NULL)
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
//searsh element
int t;
t=search(r);
int search(struct node*r)
{
	int i=1,k;
	struct node*p;
	p=r;
	printf("enter the element to be searched : ");
	scanf("%d",&k);
	while(p->d!=k)
	{
		i++;
		p=p->next;
	}
	printf("Element %d found at %d th node.",k,i);
	return r;
}
//merge two linked list in acending order
int main()
{
	struct node*x;
	x=NULL;
	r=merge_and_sort(r,x);
	struct node*merge_and_sort(struct node*r,struct node*x)
	{
		int f,i,t;
		struct node*p,*q,*s;
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
			s=ql
		}while(f);
		return r;
	}
}
