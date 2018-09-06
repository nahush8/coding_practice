#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 3
#define COLS 3

bool search(int *arr, int value)
{
	int i,j ;
	for(i = 0 ;  i < ROWS ; i++)
	{
		for(j = 0 ; j < COLS ; j++)
		{
			if(*(arr + i* COLS + j) == value)
				return true;
		}
	}

	return false;
}(

bool binary_search(int *arr, int value)
{
	
}

int main(void)
{
	int arr[][3] ={{1,3,5},{7,8,9},{11,13,15}};
	printf("\n%s\n", (search((int*)arr,13) ? "true" : "false")); 
	return 0;	
}