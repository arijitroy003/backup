#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define TOL 0.0001

int deg;
double coef[4];

void read_input()
{
	printf("Enter the degree of the equation.\n");
	scanf("%d",&deg);
	if(deg==2)
	{
		printf("Enter co-efficients of the equation a(x^2) + bx + c .\n");
		printf("Enter a, b, c : ");
		scanf("%lf %lf %lf",&coef[2],&coef[1],&coef[0]);		
	}
	else if(deg==3)
	{
		printf("Enter co-efficients of the equation a(x^3) + b(x^2) + cx + d .\n");
		printf("Enter a, b, c, d : ");
		scanf("%lf %lf %lf %lf",&coef[3],&coef[2],&coef[1],&coef[0]);
	}
	else
		printf("Upto degree 3 equation is supported.\n");	
}

double f(double x)
{
	int i;
	double t,f=0;
	for(i=0;i<=deg;i++)
	{
		t=coef[i]*pow(x,i);
		f+=t;

	}
	printf("%lf\n",f );
	return f;	
	
}
double df(double x)
{
	int i;
	double t,df=0;
	for(i=1;i<=deg;i++)
	{
		t=coef[i]*i*pow(x,i-1);
		df+=t;
	}
	return df;
}

int main()
{
	read_input();
	printf("f=%lf \n",f(3) );
}