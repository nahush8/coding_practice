#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef struct QNODE
{
	int key;
	struct QNODE *next;

}qnode;

qnode* createNode(int value)
{
	qnode *temp = (qnode*)malloc(sizeof(qnode));
	if(!temp)
	{
		printf("\nCannot allocate memory\n");
		exit(EXIT_FAILURE);
	}
	temp->key = value;
	temp->next = NULL;
	return temp;
}

void enqueue(int value, qnode **front, qnode **rear)
{
	qnode *temp = createNode(value);
	if(*rear == NULL)
	{
		*rear = temp;
		*front = temp;
		return;
	}
	else
	{
		(*rear)->next = temp;
		*rear = temp;
	}
}

int dequeue(qnode **front, qnode **rear)
{	
	if(NULL == *front)
	{
		printf("\nEmpty list\n");
		return;
	}
	int ret_val = (*front)->key;
	*front = (*front)->next;

	if(NULL == *front)
		*rear = NULL;

	return ret_val;

}

int main(void)
{
	qnode *front, *rear;
	front = NULL;
	rear = NULL;
	enqueue(10,&front,&rear);
	enqueue(78,&front,&rear);
	enqueue(34,&front,&rear);
	//dequeue(&front,&rear);
	assert(dequeue(&front, &rear) == 10);
	assert(dequeue(&front, &rear) == 78);
	assert(dequeue(&front, &rear) == 34);
	return 0;
}