#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX 10

struct stack
{
	int top;
	int size;
	int *arr;
};

struct stack * create(int n)
{
	struct stack * stk = (struct stack *)malloc(sizeof(struct stack));
	stk->top=-1;
	stk->size=n;
	stk->arr=(int *)malloc(n*sizeof(int *));
	return stk;
}

int isFull(struct stack* stk)
{
	return stk->top == stk->size - 1;
} 
    

int isEmpty(struct stack* stk)
{
	return stk->top == -1;
}

void push(struct stack *stk,int item)
{
	if(isFull(stk))
	{
		printf("Stack Overflow. \n");
		return;
	}
	else
	{
		stk->arr[++stk->top] = item;
		printf("\n %d is pushed onto the stack.\n",item);
	}
}

void pop(struct stack * stk) 
{ 
    if (isEmpty(stk))
    {
    	printf("Stack Underflow. \n");
    } 
    else
    {
    	printf("%d is popped\n",stk->arr[stk->top]);
    	stk->top--;
    }     
    
} 

void display(struct stack *stk)
{
	int p;
	if(stk->top==-1)
		printf("Stack is empty.\n");
	p=stk->top;
	while(isEmpty(stk)==0)
	{
		printf(" %d ",stk->arr[stk->top]);
		stk->top--;
	}
	stk->top=p;
}

void push_file(struct stack *stk,int item)
{
	if(isFull(stk))
	{
		printf("Stack Overflow. \n");
		return;
	}
	else
		stk->arr[++stk->top] = item;	
}
void print1(struct stack *stk)
{
	int p;
	if(stk->top==-1)
		printf("Stack is empty.\n");
	p=stk->top;
	while(isEmpty(stk)==0)
	{
		printf(" %d is popped.",stk->arr[stk->top]);
		stk->top--;
		printf(" Current stack : ");
		display(stk);
		printf("\n");
	}
	stk->top=p;
}

void print2(struct stack *stk)
{
	int p,i,j;
	int a[6];
	p=stk->top;
	i=stk->top;
	if(stk->top==-1)
		printf("Stack is empty.\n");

	while(isEmpty(stk)==0)
	{
		a[i]=stk->arr[stk->top];
		i--;
		stk->top--;
	}
	stk->top=p;
	i=p;
	while(isEmpty(stk)==0)
	{
		printf(" %d is an element.",stk->arr[stk->top]);
		stk->top--;
		printf(" Current stack : ");
		for(j=i;j>=0;j--)
			printf("%d ",a[j]);
		printf("\n");
	}
	stk->top=p;
}

void print3(struct stack *stk)
{
	struct stack *stk1 = create(6);
	int p,item;
	p=stk->top;
	while(isEmpty(stk)==0)
	{
		item=stk->arr[stk->top];
		stk->top--;
		push_file(stk1,item);
	}
	print1(stk1);
	stk->top=p;
}

void print4(struct stack *stk)
{
	struct stack *stk1 = create(6);

	int p,item;
	p=stk->top;
	while(isEmpty(stk)==0)
	{
		item=stk->arr[stk->top];
		stk->top--;
		push_file(stk1,item);
	}
	
	print2(stk1);
	stk->top=p;
}

void duplicate_top(struct stack * stk)
{
	int item=stk->arr[stk->top];
	push(stk,item);
}

bool check_equal(struct stack *stk1,struct stack *stk2)
{
	while(stk1->top != -1 || stk2->top != -1)
	{
		if(stk1->arr[stk1->top] != stk2->arr[stk2->top])
			return 0;
		stk1->top--;
		stk2->top--;
	}
	return 1;
}



void reverse_file()
{
	struct stack * stk_file =create(100);
	FILE *fp = fopen("file.txt","r");
	int num;
	if(fp == NULL)
		printf("Can't open file.\n");

	while(fscanf(fp,"%d",&num) == 1)
	{
		push_file(stk_file,num);
	}
	printf("\n\nThe file in reverse order is ");
	display(stk_file);
	printf("\n");
}

int main()
{
	system("clear");
	printf("\n\n\t\t------------ Stack operations in C --------------\n\n\n");
	struct stack * stk1 = create(5);
	struct stack * stkp = create(6);
	struct stack * stk_r[10];
	struct stack * stk_eq[2];
	int c,ch,ch1,ch2,ch3,n,count=1;
	int item,flag=1,dupe;

	while(1)
	{
		printf("\n 1. Create stack and enter elements\n 2. Print\n 3. Duplicate the top element on a stack\n 4. Print data from file in reverse\n 5. Boolean function for equality check\n 6. Exit \n");
		printf("\n\tEnter your choice :  ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
					do
					{
						printf("\n 1. Create stack\n 2. End creation\n");
						printf("\n\tEnter your choice :  ");
						scanf("%d",&ch3);
						switch(ch3)
						{
							case 1:
									printf("Enter max size of stack %d : ",count);
									scanf("%d",&n);
									stk_r[count] = create(n);
									flag=1;
									while(1)
									{
										printf("\n 1. Push\n 2. Print\n");
										printf("Enter your choice :  ");
										scanf("%d",&ch2);
										switch(ch2)
										{
											case 1:
													printf("Enter item to push : ");
													scanf("%d",&item);
													push(stk_r[count],item);
													break;
											case 2:
													display(stk_r[count]);
													flag=0;
													break;
										}
										if(flag==0)
											break;
									}
									count++;
									break;
							case 2:
									break;
						}
					}while(ch3!=2);					
					break;
			case 2:	
					ch=1;
					printf("Enter the stack : \n\n");
					while(ch==1)
					{
						printf("Enter 1 to Push :: ");
						scanf("%d",&ch);
						printf("Enter element to push :: ");
						scanf("%d",&item);
						push(stkp,item);
					}
					printf("\n\n1. From top to bottom.\n");
					printf("2. From bottom to top.\n");
					printf("\nEnter your choice :  ");
					scanf("%d",&ch1);
					switch(ch1)
					{
						case 1:
								printf("\n----Stack becoming empty (top to bottom)----\n\n");
								print1(stkp);
								
								printf("\n----Stack remaining unchanged (top to bottom)----\n\n");
								print2(stkp);
								break;
						case 2:
								printf("\n----Stack becoming empty (bottom to top)----\n\n");
								print3(stkp);
								
								printf("\n----Stack remaining unchanged (bottom to top)----\n\n");
								print4(stkp);
								break;
					}
					break;
			case 3:
						push(stk1,10);
						push(stk1,20);
						push(stk1,30);
						display(stk1);
						duplicate_top(stk1);
						display(stk1);
					break;

			case 4:
					reverse_file();
					break;

			case 5:
					printf("\nStack 1\n");
					stk_eq[1] = create(10);
					do{
						printf("\nPress 1 to Push\n");
						printf("Press 2 to Finish\n");
						printf("Choice :  ");
						scanf("%d",&c);
						switch(c)
						{
							case 1:
									printf("Enter item to push : ");
									scanf("%d",&item);
									push(stk_eq[1],item);
									break;
							case 2:
									display(stk_eq[1]);
									break;
						}
					}while(c!=2);
					printf("\nStack 2\n");
					stk_eq[2] = create(10);
					do{
						printf("\nPress 1 to Push\n");
						printf("Press 2 to Finish\n");
						printf("Choice :  ");
						scanf("%d",&c);
						switch(c)
						{
							case 1:
									printf("Enter item to push : ");
									scanf("%d",&item);
									push(stk_eq[2],item);
									break;
							case 2:
									display(stk_eq[2]);
									break;
						}
					}while(c!=2);
					if(check_equal(stk_eq[1],stk_eq[2]))
						printf("\n\t------Stacks are equal.------\n");
					else
						printf("\n\t------Stacks are not equal.------\n");
					break;
			case 6:
					printf("Exiting . . . \n");
					exit(1);
					break;
		}
	}

}