#include<stdio.h>

int main(){

	int arr[]={1,1,1,2,2,2,5,6,6,6,-3,-3,-3,4,9,8,5,5,4,4,9,9};
	int m = 1 , result = 0, i = 0, setBits[32]={}, itr = 0;
	for (i = 0 ; i < 32 ; i++)
		setBits[i] = 0;
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
		m = 1;
		itr = 0;
		while(itr < 32){
			if(arr[i] & m)
				setBits[itr]++;
			m = m << 1;
			itr++; 
		}
	}
	m = 1;
	for(i = 0 ; i< 32 ;i++){
		setBits[i] = setBits[i] % 3 ;
	}
	for(i = 0 ;i < 32 ;i++){
		result += setBits[i]* (m << i);
	}
	printf("\n%d\n",result);
	return 0;
}
