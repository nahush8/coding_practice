#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define INITIAL_VECTOR_CAPACITY 20

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
	if(0 == flag)   // Doubling the capacity
		v->ptr = (int*)realloc(v->ptr, v->capacity * 2 * sizeof(int));
	else if(1 == flag) // Half capacity
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

bool insert(vector *v, int index, int value)
{
	if((0 > index) || (v->size < index))
	{
		printf("\n Index cannot be less than 0 or more than the last stored index. Exiting ..\n");
		exit(EXIT_FAILURE);
	}

		// Inserting at the end
	if(index == v->size)
	{
		push_back(v, value);
		return true;
	}


	// Inserting at the beginning or middle
	v->size++;
	if(is_full(v))
	{
		bool rtn = resize(v, 0);
		if(false == rtn)
		{
			printf("\nNot enough memory. Exiting ..\n");
			exit(EXIT_FAILURE);
		}
	}
	v->size--;
	int i;
	for(i = v->size -1 ; i >= index ; i--)
	{
		*(v->ptr + i + 1) = *(v->ptr + i);
	}

	*(v->ptr + index) = value;
	v->size++;
	return true;
}

bool delete(vector *v, int index )
{
	if((0 > index) || (v->size < index))
	{
		printf("\n Index cannot be less than 0 or more than the last stored index. Exiting ..\n");
		exit(EXIT_FAILURE);
	}

		// Inserting at the end
	if(index == v->size)
	{
		pop(v);
		return true;
	}

	if(!is_empty(v))
	{
		int i;
		for(i = index+1 ; i < v->size ; i++)
		{
			*(v->ptr + i - 1) = *(v->ptr + i);
		}
		v->size--;
		return true;
	}
	else
		return false;
}

void print_elements(vector *v)
{
	int i;
	for(i = 0 ; i < v->size ; i++)
	{
		printf("\nElement at %d is : [%d]\n",i ,at(v, i));
	}

}

void print_stats(vector *v)
{
	printf("====================================\n");
	print_elements(v);
	printf("\nSize is : [%d]\n", get_size(v));
	printf("\ncapacity is : [%d]\n", get_capacity(v));
	printf("=====================================\n\n");
}

bool find(vector *v, int value)
{
	int i = 0 ;
	for(i = 0 ; i < v->size ; i++)
	{
		if(value == *(v->ptr + i))
		{
			printf("\nValue found at index: [%d]\n",i);
			return true;
		}
	}
	printf("\n Sorry! Value not found.\n");
	return false;

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
	}	
	push_back(&v,10);

	print_stats(&v);
	/*
	for(i = 0 ; i < 10 ; i++)
	{
		printf("\nElement popped: %d\n", pop(&v));
	}
	printf("\nLAST popped element:%d\n" , pop(&v));
	printf("\nSize is : [%d]\n", get_size(&v));
	printf("\ncapacity is : [%d]\n", get_capacity(&v));
	*/
	insert(&v, 3, 200);
	insert(&v, 8, 250);
	insert(&v, 10, 400);
	insert(&v, v.size, 500);

	print_stats(&v);

	delete(&v, 5);
	delete(&v, 2);
	delete(&v, 1);
	delete(&v, 4);
	delete(&v, 0);
	
	
	print_stats(&v);
	find(&v, 500);

	return 0;
}
