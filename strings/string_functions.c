#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

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

	if(NULL == s1)
	{
		printf("\nNot valid strings\n");
		exit(EXIT_FAILURE);
	}
	while(*s2 != '\0')
	{
		*s1++ = *s2++;
	}
	*s1 = '\0';
}

int myStrcmp(char *s1, char *s2)
{
	if((NULL == s1) || (NULL == s2))
	{
		printf("\nNot valid strings\n");
		exit(EXIT_FAILURE);
	}

	if(myStrlen(s1) == myStrlen(s2))
	{
		while(*s2 != '\0')
		{
			if(*s1++ == *s2++) 
				continue;
			else
			{
				return 1;
			}
		}
		return 0;
	}
	else
	{
		return 1;
	}
}

int main(void)
{
	char s1[100] = "TEST";
	char s2[] = "Hello testing if this works for longer strings";
 
	printf("\nLength of string1 is: %d\n", myStrlen(s1));
	printf("\nLength of string2 is: %d\n", myStrlen(s2));
	printf("\nString1 before copy: %s\n", s1);
	printf("\nString2 before copy: %s\n", s2);
	myStrcpy(s1,s2);

	printf("\nString1 After copy: %s\n", s1);
	printf("\nString2 After copy: %s\n", s2);

	printf("\nLength of string1 is: %d\n", myStrlen(s1));
	printf("\nLength of string2 is: %d\n", myStrlen(s2));

	assert( myStrcmp("Test", "TEST") == 1);
	assert( myStrcmp("Same string", "Same string") == 0);
	assert( myStrcmp("", "") == 0);
	assert( myStrcmp("Not same", " Blah") == 1);	
	return 0;
}