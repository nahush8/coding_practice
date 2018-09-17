#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
// With Arrays

typedef struct queue
{
	int front, rear, size;
	unsigned cap;
	int *arr;

}queue;

queue* createQueue(unsigned cap)
{
	queue *temp = (queue*)malloc(sizeof(queue));
	if(!temp)
	{
		printf("\nUnable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	temp->front = temp->size = 0;
	temp->rear = cap-1;  // Will do rear++ % cap to enqueue
	temp->cap = cap;
	temp->arr = (int*)malloc(sizeof(int) * cap);  
}

bool isFull(queue *q)
{
	return (q->size == q->cap);
}

bool isEmpty(queue *q)
{
	return (0 == q->size);
}

void enqueue(queue *q, int item)
{
	if(!isFull(q))
	{
		q->arr[++q->rear % q->cap] = item; 
		q->size++;
	}
	else
	{
		printf("\nQueue is full. Cannot enqueue. Dequeue something first.\n");
		return;
	}
}	

int dequeue(queue *q)
{
	if(!isEmpty(q))
	{
		int ret_item = q->arr[q->front++ % q->cap];
		q->size--;
		return ret_item;
	}
	else
	{
		printf("\nNothing to dequeue, Queue is empty. Add new items.\n");
		return;
	}
	
}	
int main(void)
{
	queue *head = createQueue(5);
	enqueue(head, 6);
	enqueue(head, 4);
	enqueue(head, 7);
	enqueue(head, 8);
	enqueue(head, 9);
	assert(isFull(head));
	assert(dequeue(head) == 6);
	assert(dequeue(head) == 4);
	assert(dequeue(head) == 7);
	assert(dequeue(head) == 8);
	assert(dequeue(head) == 9);
	dequeue(head);

	return 0;
}