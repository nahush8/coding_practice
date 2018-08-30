#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 10


typedef struct Node
{
	int value;
	struct Node* next;
} Node;

Node* allocate(void)
{
	Node *temp = NULL;
	temp = (Node*)malloc(sizeof(Node));
	return temp;
}

void createList(Node *head)
{
	Node *temp = NULL, *curr = head;
	if (head == NULL)
	{
		printf("\nUnable to create list w/o creating head. Existing ..\n");
		exit(0);
	}
	int i = 0;
	for(i = 0 ; i < MAX_LENGTH-1 ; i++)
	{
		temp = allocate();
		if(temp != 0)
		{
			temp->value = rand()%1000;
			curr -> next = temp ;
			curr = curr -> next;	
		}
		else
		{
			printf("\nInsufficient memory: Exiting ..\n");
			exit(0);
		}	 
	}
}

void printList(Node *head)
{
	Node *curr = head;
	while(curr != NULL)
	{
		if(curr -> next == NULL)
			printf("%d",curr->value);
		else 
			printf("%d -->",curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int getLength(Node *head)
{
	int length = 0;
	Node *curr = head;
	while(curr != NULL)
	{
		curr = curr->next;
		length++;
	}
	return length;
}
void bubbleSort(Node *head)
{
	Node *curr = head;
	int temp, length = 0, itr = 0;
	length = getLength(head);
	curr = head;
	while(length > 0)
	{
		while(itr < length - 1)
		{
			if(curr->value > curr->next->value)
			{
				temp = curr->value;
				curr->value = curr->next->value;
				curr->next->value = temp;
			}
			curr = curr->next;
			itr++;
		}
		itr = 0;
		length--;
		curr = head;
	}
	printf("\nsorted list is: \n");
	printList(head);
}

void findMid(Node *head, Node** front, Node** back)
{
	Node *ptr1 = head, *ptr2=head->next;
		while(ptr2 != NULL)
		{
			ptr2 = ptr2->next;
			if(ptr2 != NULL)
			{
				ptr1 = ptr1->next;
				ptr2 = ptr2->next;
			}
		}
	*front = head;
	*back = ptr1->next;
	ptr1->next = NULL;
}

// Node* merge(Node *left, Node *right)
// {
// 	Node *curr = left->value <= right->value ? left : right;
// 	Node * result = curr;
// 	if (left->value <= right->value)
// 		left = left->next;
// 	else
// 		right = right->next;

// 	if(NULL == left){
// 		curr->next = right;
// 		return result;
// 	}
// 	else if(NULL == right){
// 		curr->next = left;
// 		return result;
// 	}

// 	if (left->value <= right->value)
// 	{
// 		curr->next = left;
// 		left= left->next;
// 		curr = curr->next;
// 	}
// 	else
// 	{
// 		curr->next = right;
// 		right = right->next;
// 		curr = curr->next;
// 	}
// 	return result;

// }

Node* merge(Node* left, Node* right)
{
	Node *result = NULL;
	if(NULL == left)
		return right;
	if(NULL == right)
		return left;

	if(left->value <= right->value)
	{
		result = left;
		result->next = merge(left->next,right);
	}
	else
	{
		result = right;
		result->next = merge(left,right->next);
	}
	return result;
}

void mergeSort(Node **headRef)
{
	Node *head = *headRef;
	Node *frontRef, *backRef;
	if((NULL == head) || (NULL == head->next)) 
		return;

	findMid(head, &frontRef, &backRef);
 	//printList(frontRef);
 	//printList(backRef);
	mergeSort(&frontRef);
	mergeSort(&backRef);

	*headRef = merge(frontRef,backRef);
	//printList(result);

}

int main()
{
	Node *head = NULL;
	head = allocate();
	if (head != NULL)
	{
		head->value = 40;
	}
//	printf("\n%d\n",head);
	createList(head);
	printf("\n");
	printList(head);
	//bubbleSort(head);
	//Node *mid = findMid(head);
	//printf("\nMidpoint is: %d\n",mid->value);
	mergeSort(&head);
	printList(head);
return 0;
}
