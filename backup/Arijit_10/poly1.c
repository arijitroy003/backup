#include<stdio.h>
#include<stdlib.h>

struct node
{
    float coef;
    int expo;
    struct node *next;
};

struct node *create(struct node *);
struct node *insert_s(struct node *,float,int);
struct node *insert(struct node *,float,int);
void display(struct node *ptr);
void poly_add(struct node *,struct node *);
void poly_sub(struct node *,struct node *);
void poly_mult(struct node *,struct node *);

int main( )
{
    int ch;
    struct node *start1=NULL,*start2=NULL;
   
    printf("\nEnter polynomial 1 :\n");
    start1=create(start1);

    printf("Polynomial 1 is :  ");
    display(start1);

    printf("\nEnter polynomial 2 :\n");
    start2=create(start2);
    
    printf("Polynomial 2 is :  ");
    display(start2);
    
    do{
    
        printf("\n 1. Add two polynomials \n 2. Subtract two polynomials \n 3. Multiply polynomials\n 4. Exit\n");
        printf("Enter your choice: \t\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: 
                    poly_add(start1, start2);
                    break;
            case 2:
                    poly_sub(start1, start2);
                    break;
            case 3:
                    poly_mult(start1, start2);
                    break;
            case 4:
                    exit(1);
                    break;
        }
    }while(1);   
    
}

struct node *create(struct node *start)
{
    int i,n,ex;
    float co;
    printf("Enter the number of terms : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter coeficient for term %d : ",i);
        scanf("%f",&co);
        printf("Enter exponent for term %d : ",i);
        scanf("%d",&ex);
        start=insert_s(start,co,ex);
    }
    return start;
}

struct node *insert_s(struct node *start,float co,int ex)
{
    struct node *ptr,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->coef=co;
    tmp->expo=ex;
    
    if(start==NULL || ex > start->expo)
    {
        tmp->next=start;
        start=tmp;
    }
    else   
    {
        ptr=start;
        while(ptr->next!=NULL && ptr->next->expo >= ex)
            ptr=ptr->next;
        tmp->next=ptr->next;
        ptr->next=tmp;
    }
    return start;
}
   
struct node *insert(struct node *start,float co,int ex)
{
    struct node *ptr,*tmp;
    tmp=(struct node *)malloc(sizeof(struct node));
    tmp->coef=co;
    tmp->expo=ex;
    
    if(start==NULL)
    {
        tmp->next=start;
        start=tmp;
    }
    else    /*Insert at the end */
    {
        ptr=start;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        tmp->next=ptr->next;
        ptr->next=tmp;
    }
    return start;
}

void display(struct node *ptr)
{
    if(ptr==NULL)
    {
        printf("Zero polynomial\n");
        return;
    }
    while(ptr!=NULL && (ptr->coef)!=0)
    {
        printf("(%.1fx^%d)", ptr->coef,ptr->expo);
        ptr=ptr->next;
        if(ptr!=NULL && (ptr->coef)!=0)
            printf(" + ");
        else
            printf("\n");
    }
}

void poly_add(struct node *p1,struct node *p2)
{
    struct node *start3;
    start3=NULL;
   
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo > p2->expo)
        {
            start3=insert(start3,p1->coef,p1->expo);
            p1=p1->next;
        }
        else if(p2->expo > p1->expo)
        {
            start3=insert(start3,p2->coef,p2->expo);
            p2=p2->next;
        }
        else if(p1->expo==p2->expo)
        {
            start3=insert(start3,p1->coef+p2->coef,p1->expo);
            p1=p1->next;
            p2=p2->next;
        }
    }
    
    while(p1!=NULL)
    {
        start3=insert(start3,p1->coef,p1->expo);
        p1=p1->next;
    }
   
    while(p2!=NULL)
    {
        start3=insert(start3,p2->coef,p2->expo);
        p2=p2->next;
    }
    printf("Added polynomial is : ");
    display(start3);
}

void poly_sub(struct node *p1,struct node *p2)
{
    struct node *start3;
    start3=NULL;
   
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->expo > p2->expo)
        {
            start3=insert(start3,p1->coef,p1->expo);
            p1=p1->next;
        }
        else if(p2->expo > p1->expo)
        {
            start3=insert(start3,p2->coef,p2->expo);
            p2=p2->next;
        }
        else if(p1->expo==p2->expo)
        {
            start3=insert(start3,p1->coef-p2->coef,p1->expo);
            p1=p1->next;
            p2=p2->next;
        }
    }
    
    while(p1!=NULL)
    {
        start3=insert(start3,p1->coef,p1->expo);
        p1=p1->next;
    }
   
    while(p2!=NULL)
    {
        start3=insert(start3,p2->coef,p2->expo);
        p2=p2->next;
    }
    printf("Subtracted polynomial is : ");
    display(start3);
}

void poly_mult(struct node *p1, struct node *p2)
{
    struct node *start3;
    struct node *p2_beg = p2;
    start3=NULL;
    if(p1==NULL || p2==NULL)
    {
        printf("Multiplied polynomial is zero polynomial\n");
        return;
    }
    while(p1!=NULL)
    {
        p2=p2_beg;
        while(p2!=NULL)
        {
            start3=insert_s(start3,p1->coef*p2->coef,p1->expo+p2->expo);
            p2=p2->next;   
        }
        p1=p1->next;
    }   
    printf("Multiplied polynomial is : ");
    display(start3);
}