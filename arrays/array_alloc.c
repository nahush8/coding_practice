#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_SIZE 10
#define MAX_ROWS 4
#define MAX_COLS 3

int* oneDArray(int);
int* twoDArray(int, int);
void print_array (int*, int);
void p2p_print(int**, int, int);
int** p2p(int, int);
int** array_of_pointers(int, int);

int main(void)
{
	int size_of_array = MAX_SIZE;
	srand (time(NULL));
	int rows = MAX_ROWS;
	int cols = MAX_COLS;
	//int *ptr = oneDArray(size_of_array);
	//int *ptr = twoDArray(MAX_ROWS, MAX_COLS);
	//print_array(ptr, MAX_ROWS * MAX_COLS);
	int **ptr = array_of_pointers(rows,cols);
	p2p_print(ptr, rows, cols);
	return 0;

}

int* oneDArray(int capacity)
{
	int *arr = (int* ) malloc(capacity * sizeof(int));
	int i;
	for (i = 0 ; i < capacity ; i++)
	{
		*(arr+i) = rand()%50;
	}
	return arr;
}

void print_array(int *ptr, int capacity)
{
	int i;
	printf("\n");
	for(i = 0 ; i < capacity ; i++)
			printf("%d\t",*(ptr+i));
	printf("\n");
}

void p2p_print(int **ptr, int r, int c)
{
	int i,j;
	printf("\n");
	for(i = 0 ; i < r ; i++)
		for(j = 0 ; j < c ; j++)
			printf("%d\t",*(*(ptr+i)+j));
	printf("\n");
}

int* twoDArray(int r, int c)
{
	int *arr = (int*)malloc(r * c * sizeof(int));
	int i,j;
	for(i = 0 ; i < r; i++)
		for(j = 0; j < c; j++)
			*(arr+ i*c + j) = rand()%30;
	return arr;
}

int** p2p(int r, int c)
{
	int **arr;
	arr = (int**)malloc(r * sizeof(int*));
	int i,j;
	for(i = 0 ; i < r ; i++)
		*(arr+i) = (int*)malloc(c * sizeof(int));

	for(i = 0 ; i < r ; i++)
		for (j = 0 ; j < c ; j++)
			*(*(arr+i)+j) = rand()%20;

	return arr;

}

int** array_of_pointers(int r, int c)
{
	int *arr[r];
	int i, ;
	for(i = 0 ; i < r ; i++)
		*(arr+i) = (int*)malloc(c * sizeof(int));

	for(i = 0 ; i < r ; i++)
		for (j = 0 ; j < c ; j++)
			*(*(arr+i)+j) = rand()%20;

	return arr;

}