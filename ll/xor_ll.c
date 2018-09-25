#include<stdio.h>
#include<stdlib.h>
#include<inttypes.h>



typedef struct XOR_NODE
{
	int data;
	struct XOR_NODE *npx; // XOR of next and previoud pointer

}node;


node* XOR(node *a, node* b)
{
	//uintptr_t is an unsigned int that holds a pointer.
	// Used typically for int like operations on pointer. 
	return(node*)((uintptr_t)(a) ^ (uintptr_t)(b)); 
}

node* newNode(int data)
{
	node *temp = (node*) malloc(sizeof(node));
	temp->data = data;
	temp->npx = NULL;
	return temp;
}
// Inserts at Head position
void insert(node **headRef, int data)
{
	node *new_node = newNode(data);
	new_node->npx = XOR(*headRef, NULL);
	if(NULL != *headRef)
	{
		node *next = XOR((*headRef)->npx, NULL);
		(*headRef)->npx = XOR(new_node, next);
	}

	*headRef = new_node;
}

void printList(node *head)
{
	printf("\n");
	node *curr = head;
	node *prev = NULL;
	node *next;

	while(NULL != curr)
	{
		printf("%d -->", curr->data);
		next = XOR(curr->npx, prev);

		prev = curr;
		curr = next;

	}
	printf("\n");
}

int main(void)
{
	node *head = NULL;
	insert(&head, 5);
		printList(head);
	insert(&head, 86);
		printList(head);
	insert(&head, 6);
		printList(head);
	insert(&head, 3);
	printList(head);
	return 0;
}