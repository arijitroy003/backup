#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <math.h>
#include <ctype.h>
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
		//printf("\n %d is pushed onto the stack.\n",item);
	}
}

char pop(struct stack * stk) 
{ 
    if (!isEmpty(stk))
        	return stk->arr[stk->top--];
     
    return '$';     
}

char peek(struct stack *stk)
{
	return stk->arr[stk->top];
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
int isOperand(char ch)
{
	return ((ch>='A' && ch<='Z') || (ch>='a' && ch<='z') || (ch>='0' && ch<='9'));
}

int prec(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
				return 1;
		case '*':
		case '/':
				return 2;
		case '^':
				return 3;			
	}
	return -1;
}

char * intopost(char *exp)
{
	int i,k;
	struct stack *stk = create(strlen(exp));

	for(i=0,k=-1;exp[i];++i)
	{	
		// operand
		if(isOperand(exp[i]))
			exp[++k]=exp[i];
		else if(exp[i]=='(')
			push(stk,exp[i]);
		else if(exp[i]==')')
		{
			while(!isEmpty(stk) && peek(stk) != '(')
				exp[++k]=pop(stk);
			if(!isEmpty(stk) && peek(stk) != '(')
			{
				printf("Invalid Expression.\n");
				//return '$';
			}
			else
				pop(stk);
		}
		else //operator
		{
			while(!isEmpty(stk) && prec(exp[i])<=prec(peek(stk)))
				exp[++k]=pop(stk);
			push(stk,exp[i]);
		}
	}

	while(!isEmpty(stk))
		exp[++k]=pop(stk);

	exp[++k]='\0';
	return exp;
	// printf("%s \n",exp);
}

int posteval(char *exp)
{
	int i,k;
	struct stack *stk = create(strlen(exp));

	for(i=0;exp[i];++i)
	{
		if(isdigit(exp[i]))
		{
			push(stk,exp[i]-'0');
			//printf("%d is pushed\n",exp[i]-'0');
			//display(stk);
		}
		else
		{
			int val1=pop(stk);
			int val2=pop(stk);
			switch(exp[i])
			{
				case '+':
						push(stk,val2+val1);
						break;
				case '-':
						push(stk,val2-val1);
						break;
				case '*':
						push(stk,val2*val1);
						break;
				case '/':
						push(stk,val2/val1);	
						break;
				display(stk);
			}
		}
	}
	return pop(stk);
}

int main()
{
	char exp[100];
	printf("Enter the infix expression : ");
	scanf("%[^\n]s",exp);

	printf("The infix expression is %s\n",exp);
	printf("The postfix expression is %s\n",intopost(exp));
	printf("The postfix expression evaluates to %d.\n",posteval(exp));
	printf("\n");

}