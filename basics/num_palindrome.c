#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool isPalindrome(int n)
{
	if(0 > n) n = -n;
	int save = n;
	int rev = 0;
	while(n > 0)
	{
		rev = rev * 10 + n % 10;
		n = n/10;
	}

	return (rev == save ? true: false);
} 



int main(void)
{

	int data[] = {0, 2, 33, 56, 3434, 565, 123, 00100, -200, -767, 78344387};
	int i;

	printf("\nPrints 1 if palindrome, 0 if not.\n");
	for(i = 0 ; i < (sizeof(data)/sizeof(data[0])); i++)
		printf("\nIs the number %d palindrome: [%d]\n",data[i],isPalindrome(data[i]));

	return 0;
}