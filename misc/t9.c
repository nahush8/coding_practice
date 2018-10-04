#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char hashtable[10][5] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printwordUtil(int num[], char output[], int curr, int n)
{
	int i;
	if(curr == n)
	{
		printf("%s ", output);
		return;
	}
	for(i = 0  ; i < strlen(hashtable[num[curr]]) ; i++)
	{
		output[curr] = hashtable[num[curr]][i];
		printwordUtil(num, output, curr+1, n);
		if(0 == num[curr] || 1 == num[curr])
			return;
	}
}



void printwords(int num[], int n)
{
	char output[n+1];
	output[n] = '\0';
	printwordUtil(num, output, 0, n);
}

int main(){

	int num[] = {2,4,5};
	int n = sizeof(num)/sizeof(num[0]);
	printwords(num,n);
	printf("\n");

return 0;
}
