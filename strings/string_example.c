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

char* string_replacement(char *str, int DELTA)
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
	char *newStr = str;
	newStr += strlen(str) + numOfBlanks * DELTA;

	while(temp != str)
	{
		if(*temp == ' ')
		{
			*(newStr--) = '0';
			*(newStr--) = '2';
			*(newStr--) = '%';
		}
		else
		{
			*(newStr--) = *temp;
		}
		temp--;

	}

	if(*temp == ' ')
		{
			*(newStr--) = '0';
			*(newStr--) = '2';
			*(newStr--) = '%';
		}
	printf("\nNumber of Blanks: %d\n", numOfBlanks);
	return str;
		
}

int main(void)
{
char str[100];
strcpy(str, "Program works.");
printf("\nString before Replacement: %s\n",str);
printf("\nString After Replacement: %s\n",string_replacement(str, 2));
	return 0;
}