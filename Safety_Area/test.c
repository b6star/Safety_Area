/*Queue Test
#include <stdio.h>
#include "circular_queue.h"

int main()
{
	QueueType queue;
	init(&queue);
	enqueue(&queue, 1, 2);
	enqueue(&queue, 3, 4);
	enqueue(&queue, 5, 6);
	enqueue(&queue, 7, 8);
	int a, b;
	int* ptr1, * ptr2;
	ptr1 = &a;
	ptr2 = &b;
	dequeue(&queue, ptr1, ptr2);
	print_Queue(&queue);
	printf("<%d, %d>\n", *ptr1, *ptr2);
	return 0;
	*/