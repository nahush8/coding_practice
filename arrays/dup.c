#include<stdio.h>
#include<stdlib.h>

// In case the array has only one duplicated element. Array is from 0 to n-2 and one of the numbers
// is duplicated
int duplicate(int *ptr, int l)
{
	int i, sum_of_all = 0, n_sum = 0;;
	for(i = 0 ; i < l ; i++)
	{
		if(*(ptr + i) < 0 || *(ptr + i) > (l - 2))
		{
			printf("\n Invalid numbers.\n");
			exit(EXIT_FAILURE);
		}
		sum_of_all += *(ptr + i); 
		n_sum = ((l - 1) * ( l - 2)) >> 1 ; // Sum of n - 2 values is (n-1)*(n-2)/2
	}
	return sum_of_all - n_sum;
}

void swap(int *a, int *b)
{
	int temp;
	temp  = *a;
	*a = *b;
	*b = temp;
}

// N numbers ranging from 0 to n-1. It is not clear how many numbers 
// are duplicated or how many times a number gets duplicated

int unknown_duplicates(int *ptr, int l)
{
	int i;
	for(i = 0 ; i < l ; i++)
	{
		if(*(ptr + i) < 0 || *(ptr + i) > (l - 1))
		{
			printf("\n Invalid numbers.\n");
			exit(EXIT_FAILURE);
		}
	}

	for(i = 0 ; i < l ; i++)
	{

		while(*(ptr + i) != i)
		{
			if(*(ptr + i) == *(ptr + *(ptr + i)))
				return *(ptr + i);	
				
			swap((ptr+i),(ptr+*(ptr+i)));	
		}

	}
	printf("\nNO Duplicates\n");
	exit(EXIT_FAILURE);
}

int main(void)
{
	int data[] = {2,3,1,0,5,5,4,4,6};
	//int data[] = {0,0};
	//int data[] = {2,3,1,0,5,5,4,4,19};
	//int data[] = {2,3,1,0,5,6};

	int length = sizeof(data)/sizeof(data[0]);
	printf("\nDuplicate number is: %d\n", unknown_duplicates(data, length));
	return 0;
}
