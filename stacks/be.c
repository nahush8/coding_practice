#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Stack
{
	char data;
	struct Stack *next;
}stack;

stack* newNode(char data)
{
	stack *temp = (stack*)malloc(sizeof(stack));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(stack **root, char new_data)
{
	stack *new_node = newNode(new_data);
	if (new_node == NULL)
  	{
     printf("Cannot allocate memory\n");
     exit(0);
  	}
	new_node->next = *root;
	*root = new_node;
}

bool isEmpty(stack **root)
{
	if(*root == NULL)
		return true;
	else
		return false;
}

char pop(stack **root)
{
	if(isEmpty(root))
	{
		printf("Stack empty\n");
     	exit(0);
	}
	else
	{
		stack *temp = *root;
		*root = (*root)->next;
		char popped = temp->data;
		free(temp);
		return popped;
	}

}

bool isMatching(char a, char b)
{
	if('(' == a && ')' == b)
		return true;
	if('{' == a && '}' == b)
		return true;
	if('[' == a && ']' == b)
		return true;
	else
		return false;

}

bool isBalanced(char expr[])
{
	stack *root = NULL;
	int i = 0 ;

	while(expr[i])
	{
		if(expr[i] == '{' || expr[i] == '[' || expr[i] == '(')
			push(&root, expr[i]);
		if(expr[i] == '}' || expr[i] == ']' || expr[i] == ')')
		{
			if(isEmpty(&root))
				return false;
			else if(!isMatching(pop(&root), expr[i]))
				return false;
		}
		i++;
	}

	if(isEmpty(&root))
		return true;
	else
		return false;

}

int main(void)
{

	char expr[100] = "([{}])[]({[})";
	if(isBalanced(expr))
		printf("\nBalanced\n");
	else
		printf("\nNot balanced\n");
	return 0;
}