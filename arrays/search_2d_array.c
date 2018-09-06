#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ROWS 4
#define COLS 4

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
		mid = (start + end) >> 1;
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

//In a 2-D matrix, every row is increasingly sorted from left to right, and every column is
//increasingly sorted from top to bottom. Please implement a function to check whether a number is in such a
//matrix or not.

bool search_recursive(int *arr, int value, int row1, int col1, int row2, int col2)
{
	if((value < *(arr + row1 * COLS + col1)) || (value > *(arr + row2 * COLS + col2)))
		return false;

	if( (value == *(arr + row1 * COLS + col1)) || (value == *(arr + row2 * COLS + col2)))
		return true;
	
	int saveRow1 = row1, saveCol1 = col1;
	int saveRow2 =  row2, saveCol2 = col2;

	int midRow =  (row1 + row2) / 2;
	int midCol = (col1 + col2) / 2;
	//Binary search on diagonal
	while(((midRow != row1 || midCol != col1) && (midRow != row2 || midCol != col2)))
	{
		if(value == *(arr + midRow * COLS + midCol))
			return true;
		else if (value > *(arr + midRow * COLS + midCol))
		{
			row1 = midRow;
			col1 = midCol;

		}
		else if(value < *(arr + midRow * COLS + midCol))
		{		
			row2 = midRow;
			col2 = midCol;
		}
		midRow = (row1 + row2) / 2;
	    midCol = (col1 + col2) / 2;
	}

	bool found = false;
	if(midRow < ROWS - 1)
		found = search_recursive(arr, value, midRow + 1, saveCol1, saveRow2, midCol);
	if(!found && (midCol < COLS - 1))
		found = search_recursive(arr, value, saveRow1, midCol + 1, midRow, saveCol2);

	return found;

}

int main(void)
{
	//int arr[][3] ={{1,3,5},{7,8,9},{11,13,15}};
	int arr[ROWS][COLS] = {1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15};
	//int arr[][3] ={{1,3,5},{7,8,9},{11,13,15}};
	//int arr[][3] ={{1,3,5},{7,8,9},{11,13,15}};
	printf("\n%s\n", (search_recursive((int*)arr, 7 , 0, 0, ROWS-1, COLS-1) ? "true" : "false")); 
	return 0;	
}