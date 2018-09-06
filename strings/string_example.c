#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

// String replacement using Extra space

char* replace_blanks(char *str)
{
	char *temp;
	temp = (char*)malloc(100 * sizeof(char));
	int i, j = 0;
	for(i = 0 ; i < strlen(str) ; i++)
	{
		if(' ' == *(str + i))
		{
			strcpy(temp + j, "\%20");
			j++;
			j++;
				j++;
		}

		else
		{
			*(temp + j) = *(str+ i);
			j++;
		}
	}
	return temp;
}

// String replacement without extra space

char* string_replacement(char *str)
{
	char *temp = str;
	int numOfBlanks = 0;
	int i = 0;
	while(*temp != '\0')
	{
		if (*temp == ' ')
			++numOfBlanks;
		temp++;
	}
	printf("\nNumber of Blanks: %d\n", numOfBlanks);
	return str;
}

int main(void)
{
char str[100];
strcpy(str, "We are happy");
printf("\nString before Replacement: %s\n",str);
printf("\nString After Replacement: %s\n",string_replacement(str));
	return 0;
}