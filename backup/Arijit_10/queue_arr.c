#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#define MAX 10

struct queue
{
	int front;
	int rear;
	int size;
	int *arr;
};

struct queue * create(int n)
{
	struct queue * q = (struct queue *)malloc(sizeof(struct queue));
	q->front=-1;
	q->rear=-1;
	q->size=n;
	q->arr=(int *)malloc(n*sizeof(int *));
	return q;
}

