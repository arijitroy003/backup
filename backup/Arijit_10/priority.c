#include<stdio.h>
#include<stdlib.h>
struct pq
{
	int data;
	int pri;
	struct pq *next;
};
struct pq *head=NULL;

void insert()
{
	int d,p,f=0;
	struct pq *ptr,*s,*w;
	ptr=(struct pq*)malloc(sizeof(struct pq));
	printf("\n\tEnter the data & priority: ");
	scanf("%d%d",&d,&p);
	ptr->data=d;
	ptr->pri=p;
	if(head==NULL)
	{
	   ptr->next=NULL;
		head=ptr;
	}
	else if(ptr->pri>head->pri)
	{
		ptr->next=head;
		head=ptr;
	}
	else
	{
		w=head;
		s=w->next;
		if(s==NULL)
		{
			w->next=ptr;
			ptr->next=NULL;
		}
		
		else
		{
		while(ptr->pri<s->pri)
		{
			s=s->next;
			w=w->next;
			if(s==NULL)
			{
				f=1;
				break;
			}
		}
		if(f==1)
		{
			ptr->next=NULL;
			w->next=ptr;
		}
		else
		{
			ptr->next=s;
			w->next=ptr;
		}
		}
	}			
}

int del()
{
	int d;
	struct pq *s;
	if(head==NULL)
	{
		printf("\nQueue empty.\n");
		return 0;
	}
	else{
		d=head->data;
		s=head;
		head=head->next;
		free(s);
		return d;
	}

}

void display()
{
	struct pq *s;
	s=head;
	printf("\nData\tPriority\n");
	printf("-----------------------\n");
	while(s!=NULL)
	{
		printf("  %d\t  %d\n",s->data,s->pri);
		s=s->next;
	}
}

int main()
{
	system("clear");
	int t,i;
	printf("\n\n\t\t------------ Priority Queue --------------\n\n\n");
	while(1)
	{
		printf("\n 1. Insert\n 2. Delete.\n 3. Display \n 4. Exit ");
		printf("\n \tEnter your choice : ");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
					insert();
					display();
					break;
			case 2:
				t=del();
				if(t==0)
					printf("\n Queue empty.\n");
				else
					printf("\n Delete successfull %d deleted.\n",t);
				display();
				break;
			case 3: 
					display();
					break;
			default:
					printf("Wrong Input \n");
					break;
			case 4:
				exit(0);
		}
	}
	
}
