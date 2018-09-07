#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int myStrlen(char *str)
{
	if(str == NULL)
	{
		printf("\nNot a valid string\n");
		exit(EXIT_FAILURE);
	}
	int count = 0;
	while(*(str++) != '\0')
		++count;

	return count;
}

void myStrcpy(char *s1, char *s2)
{

	if((NULL == s1) || (NULL == s2))
	{
		printf("\nNot valid strings\n");
		exit(EXIT_FAILURE);
	}


}

int myStrcmp(char *s1, char *s2)
{
	
}

int main(void)
{
	char s1[] = "Hello world";
	char s2[] = "Hello";

	printf("\nLength of string is: %d\n", myStrlen(s1));
	return 0;
}