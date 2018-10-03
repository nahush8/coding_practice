#include<bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = (2 * i) + 1;
	int r = (2 * i) + 2;

	if(arr[l] > arr[largest] && l < n)
	{
		largest = l;
	}
	// If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
    {
        largest = r; 
    }
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
}
/* A utility function to print array of size n */
void printArray(int arr[], int n) 
{ 
    for (int i=0; i<n; ++i) 
        cout << arr[i] << " "; 
    cout << "\n"; 
} 

int main(void)
{
	int arr[] = {12, 11, 13, 5, 6, 7}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
  	for(int i = n/2 - 1 ; i >=0 ; i--)
    	heapify(arr, n, i); 
  
    cout << "Sorted array is \n"; 
    printArray(arr, n); 
	return 0;
}