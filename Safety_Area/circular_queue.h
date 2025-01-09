#include <stdio.h>
#include <stdlib.h>

#define SIZE 10000

typedef int element;

typedef struct {
	element data[SIZE][2];
	int rear, front;
}QueueType;

void init(QueueType* Q)
{
	Q->rear = Q->front = -1;
}

int is_empty(QueueType* Q)
{
	return Q->front == Q->rear;
}

int is_full(QueueType* Q)
{
	return Q->rear == SIZE - 1;
}

void enqueue(QueueType* Q, element e1, element e2)
{
	if (is_full(Q))
		printf("Overflow\n");
	else
	{
		Q->rear++;

		Q->data[Q->rear][0] = e1;
		Q->data[Q->rear][1] = e2;
	}
}

element dequeue(QueueType* Q, element *e1, element *e2)
{
	if (is_empty(Q))
	{
		printf("Empty\n");
		return 0;
	}
	else
	{
		Q->front++;
		*e1 = Q->data[Q->front][0];
		*e2 = Q->data[Q->front][1];
		return 1;
	}
}

void print_Queue(QueueType* Q)
{
	printf("Front Pos : %d\n, Rear Pos : %d\n", Q->front, Q->rear);
	for (int i = Q->front + 1; i <= Q->rear; i++)
	{
		printf("[%d, %d] ", Q->data[i][0], Q->data[i][1]);
	}
	printf("\n");
}