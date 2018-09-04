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

// N numbers ranging from 0 to n-1. It is not clear how many numbers 
// are duplicated or how many times a number gets duplicated

int unknown_duplicates(int *ptr, int l)
{
	return 0;
}

int main(void)
{
	int data[] = {0,1,2,3,4,5,5};
	int length = sizeof(data)/sizeof(data[0]);
	printf("\nDuplicate number is: %d\n", duplicate(data, length));
	return 0;
}
