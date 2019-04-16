#include<stdio.h>
#include<stdlib.h>
#define max 10
int a[max],front=-1,rear=-1,n=max-1;
void cqinsert(int item)
{
	if((rear+1)%n==front)
		printf("The cqueue is full");
	else if(front==-1&&rear==-1)
	{
		front=rear=0;
		a[rear]=item;
	}
	else{
		rear=(rear+1)%n;
		a[rear]=item;
	}
}
int cqdel()
{
	int t=0;
	if((front==-1)&&(rear==-1))
		printf("The cqueue is empty");
	else if(front==rear)
	{
		t=a[front];
		front=rear=-1;
	}
	else
	{
		t=a[front];
		front=(front+1)%n;
	}
	return t;
}
void display()
{
	int i;
	for(i=front;i<rear+1;i++)
		printf("%d ",a[i] );

}
int main()
{
	system("clear");
	printf("\n\n\t\t------------ Circular Queue --------------\n\n\n");
	int ch,t;
	while(1)
	{
	printf("\n 1. Insert\n 2. Delete\n 3. Display\n 4. Exit");
	printf("\n Enter your choice: ");
	scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nEnter the element:");
				scanf("%d",&t);
				cqinsert(t);
				break;
			case 2:
				t=cqdel();
				if(t!=0)
					printf("The deleted element is: %d",t);
				break;
			case 3:
					display();
					break;
			case 4:
				exit(1);
		}
	}
}
			
