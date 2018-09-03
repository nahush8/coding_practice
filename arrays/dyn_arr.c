#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INITIAL_VECTOR_CAPACITY 10

typedef struct VECTOR
{
	int size; //Actual occupancy
	int capacity; //Total space
	int* ptr; //Pointer to the array
}vector;

void vector_init(vector *v)
{
	v->size = 0;
	v->capacity = INITIAL_VECTOR_CAPACITY;
	v->ptr = (int*)malloc(v->capacity * sizeof(int));	
}

int get_size(vector *v)
{
	return v->size;
}

int get_capacity(vector *v)
{
	return v->capacity;
}

bool is_empty(vector *v)
{
	if(0 == v->size)
		return true;
	else
		return false;
		
}

bool is_full(vector *v)
{
	if(v->size == v->capacity)
		return true;
	else
		return false;
}

int at(vector *v, int index)
{	
	if(is_empty(v))
	{
		printf("\nTrying to access index which does not exist. Exiting ..\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		return *(v->ptr + index);
	}
}

bool resize(vector *v, bool flag)
{
	if(0 == flag)
		v->ptr = (int*)realloc(v->ptr, v->capacity * 2 * sizeof(int));
	else if(1 == flag)
		v->ptr = (int*)realloc(v->ptr, v->capacity / 2 * sizeof(int));
		

	if (NULL != v->ptr)
	{
		if(0 == flag)
			v->capacity = v->capacity * 2;
		else if(1 == flag)
			v->capacity = v->capacity / 2;
		return true;
	}
	else
		return false;
}

void push_back(vector *v, int value)
{
	if(is_full(v))
	{
		bool rtn = resize(v, 0);
		if(false == rtn)
		{
			printf("\nNot enough memory. Exiting ..\n");
			exit(EXIT_FAILURE);
		}
	}

	*(v->ptr + v->size++) =  value;
}

int pop(vector *v)
{
	if(is_empty(v))
	{
		printf("\n Empty List. Exiting ..\n");
		exit(EXIT_FAILURE);
	}
	if(v->size < 0.25 * v->capacity)
		resize(v, 1);

	return *(v->ptr + --v->size);
}


int main()
{
	vector v;
	vector_init(&v);
	printf("\nSize is : [%d]\n", get_size(&v));
	printf("\ncapacity is : [%d]\n", get_capacity(&v));
	int i = 0;
	for(i = 0 ; i < 10 ; i++)
	{
		push_back(&v,i);
		printf("\nElement at %d is : [%d]\n",i ,at(&v, i));
	}

	push_back(&v,10);

	printf("\nElement at %d is : [%d]\n",i ,at(&v, 10));
	printf("\nSize is : [%d]\n", get_size(&v));
	printf("\ncapacity is : [%d]\n", get_capacity(&v));

	for(i = 0 ; i < 10 ; i++)
	{
		printf("\nElement popped: %d\n", pop(&v));
	}
	printf("\nLAST popped element:%d\n" , pop(&v));
	printf("\nSize is : [%d]\n", get_size(&v));
	printf("\ncapacity is : [%d]\n", get_capacity(&v));

	return 0;
}
