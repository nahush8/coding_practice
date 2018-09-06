#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 3
#define COLS 1

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
}

bool binary_search(int *arr, int value)
{
	int start = 0;
	int end = ROWS * COLS;
	int mid;

	while(start <= end)
	{
		mid = (start + end) /2;
		if(value == *(arr + mid))
			return true;
		else if(value > *(arr + mid)) 
		{
			start = mid + 1;
		}
		else if(value < *(arr + mid))
		{
			end = mid - 1;
		}
	}
	return false;
}

int main(void)
{
	//int arr[][3] ={{1,3,5},{7,8,9},{11,13,15}};
	int arr[3][1] ={1,3,15};
	//int arr[][3] ={{1,3,5},{7,8,9},{11,13,15}};
	//int arr[][3] ={{1,3,5},{7,8,9},{11,13,15}};
	printf("\n%s\n", (binary_search((int*)arr,15) ? "true" : "false")); 
	return 0;	
}