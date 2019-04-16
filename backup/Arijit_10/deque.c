#include<stdio.h>
#include<stdlib.h>
int front=-1,rear=-1,a[100],n;
void insertfront(int item)
{
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		a[front]=item;
	}
	else if(front==0)
	{
		printf("Insertion not possible .");
	}
	else
	{
		a[--front]=item;
	}
}
void deleterear()
{
	int t;
	if(front==-1 && front>rear)
	{
		printf("Deletion not possible .");
	}
	else
	{
		t=a[rear];
		rear--;
	}
}
void insertrear(int item)
{
	if(rear==-1 && front==-1)
	{
		rear=front=0;
		a[rear]=item;
	}
	else
	{
		if(rear==n)
		{
			printf("The queue is full.");
		}
		else
		{
			a[++rear]=item;
		}
	}
}
void deletefront()
{
	int t1;
	if(front==-1 && front>rear)
	{
		printf("Deletion not possible .");
	}
	else
	{
		t1=a[front];
		front++;
	}
}
void display()
{
	int i=front;
	printf("\n");
	printf("The deque is :\n");
	while(i<=rear)
	{
		printf("   %d",a[i]);
		i++;
	}
	printf("\n");
}
void main()
{
	system("clear");
	printf("\n\n\t\t------------ Double Ended Queue --------------\n\n\n");
	int c,item;
	printf("Enter the size of the queue :");
	scanf("%d",&n);
	while(1)
	{
		printf("\n 1. Insert front\n 2. Delete rear\n 3. Insert rear\n 4. Delete front\n 4. Display\n 5. Exit..\n");
		printf("Enter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1:			printf("Enter the value to insert at front position:");
							scanf("%d",&item);
							insertfront(item);
							display();
							break;
			case 2:			deleterear();
							display();
							break;
			case 3:			printf("Enter the value to insert at rear position:");
							scanf("%d",&item);
							insertrear(item);
							display();
							break;
			case 4:			deletefront();
							display();
							break;
			case 5:			exit(0);
			
		}
	}
	
}
