#include<stdio.h>

int main(){
	int arr[] = {1,1,2,2,3,3};
	int i = 0, result=0;
	for (i = 0 ; i < sizeof(arr)/sizeof(int) ; i++){
		result = result ^ arr[i];
	}
printf("%d\n",result);
return 0;
}
