#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
/*
- ### Linked Lists
    - [ ] Description:
        - [ ] [Singly Linked Lists (video)](https://www.coursera.org/learn/data-structures/lecture/kHhgK/singly-linked-lists)
        - [ ] [CS 61B - Linked Lists 1 (video)](https://archive.org/details/ucberkeley_webcast_htzJdKoEmO0)
        - [ ] [CS 61B - Linked Lists 2 (video)](https://archive.org/details/ucberkeley_webcast_-c4I3gFYe3w)
    - [ ] [C Code (video)](https://www.youtube.com/watch?v=QN6FPiD0Gzo)
            - not the whole video, just portions about Node struct and memory allocation.
    - [ ] Linked List vs Arrays:
        - [Core Linked Lists Vs Arrays (video)](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/rjBs9/core-linked-lists-vs-arrays)
        - [In The Real World Linked Lists Vs Arrays (video)](https://www.coursera.org/learn/data-structures-optimizing-performance/lecture/QUaUd/in-the-real-world-lists-vs-arrays)
    - [ ] [why you should avoid linked lists (video)](https://www.youtube.com/watch?v=YQs6IC-vgmo)
    - [ ] Gotcha: you need pointer to pointer knowledge:
        (for when you pass a pointer to a function that may change the address where that pointer points)
        This page is just to get a grasp on ptr to ptr. I don't recommend this list traversal style. Readability and maintainability suffer due to cleverness.
        - [Pointers to Pointers](https://www.eskimo.com/~scs/cclass/int/sx8.html)
    - [ ] implement (I did with tail pointer & without):
        - [ ] size() - returns number of data elements in list
        - [ ] empty() - bool returns true if empty
        - [ ] value_at(index) - returns the value of the nth item (starting at 0 for first)
        - [ ] push_front(value) - adds an item to the front of the list
        - [ ] pop_front() - remove front item and return its value
        - [ ] push_back(value) - adds an item at the end
        - [ ] pop_back() - removes end item and returns its value
        - [ ] front() - get value of front item
        - [ ] back() - get value of end item
        - [ ] insert(index, value) - insert value at index, so current item at that index is pointed to by new item at index
        - [ ] erase(index) - removes node at given index
        - [ ] value_n_from_end(n) - returns the value of the node at nth position from the end of the list
        - [ ] reverse() - reverses the list
        - [ ] remove_value(value) - removes the first item in the list with this value
    - [ ] Doubly-linked List
        - [Description (video)](https://www.coursera.org/learn/data-structures/lecture/jpGKD/doubly-linked-lists)
        - No need to implement
*/

typedef struct Node
{
	int data;
	struct Node *next;

}node;


bool isEmpty(node *head)
{
	if(NULL == head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

node* allocate()
{
	node *temp = (node*)malloc(sizeof(node));
	return temp;
}

node* goToEnd(node *head)
{
	node *itr = head;
	while(NULL != itr->next) 
	{
		itr = itr->next;
	}
	return itr;
}
void push_back(node **head, int value)
{
	// This is the first time call. Create head.
	if(NULL == *head)
	{
		*head = allocate();
		(*head)->next = NULL;
		(*head)->data = value;
	}
	else  // List already exits, travel to the last node and add the new node.
	{
		node *itr= goToEnd(*head);
		node *temp = allocate();
		itr->next = temp;
		temp->data = value;
		temp->next = NULL;
	}
}

int pop_back(node *head)
{
	int retval;
	if(NULL == head->next)
	{
		retval = head->data;
		printf("\nPopping out last element.\n");
		printf("\nElement is: %d\n",retval);
		free(head);
		exit(EXIT_SUCCESS);
	}
	else
	{
		node *itr = head;
		while(NULL != itr->next->next)
		{
			itr = itr->next;
		}
		retval = itr->next->data;
		free(itr->next);
		itr->next = NULL;
		return retval;
	}
}

int pop_front(node **head)
{
	int retval;
	if((*head)->next == NULL)
	{
		retval = (*head)->data;
		printf("\nPopping out last element.\n");
		printf("\nElement is: %d\n",retval);
		free(*head);
		exit(EXIT_SUCCESS);
	}
	else
	{
		node *itr = (*head)->next;
		retval = (*head)->data;
		free(*head);
		*head = itr;
		return retval;
	}
}

void push_front(node **head, int value)
{
	// This is the first time call. Create head.
	if(NULL == *head)
	{
		*head = allocate();
		(*head)->next = NULL;
		(*head)->data = value;
	}
	else  // List already exits, travel to the last node and add the new node.
	{
		node *temp = allocate();
		temp->next = *head;
		temp->data = value;
		*head = temp;
	}
}

int size(node *head)
{
	node *itr = head;
	int count = 0;
	while(itr != NULL)
	{
		itr = itr->next;
		count++;
	}
	return count;
}

void printList(node *head)
{
	int i;
	if(isEmpty(head)){
		printf("\nList is empty.\n");
		exit(EXIT_FAILURE);
	}

	node *itr = head;
	printf("\n");
	while(itr->next != NULL)
	{
		printf("%d --> ", itr->data);
		itr = itr->next;
	}
	printf("%d",itr->data);
	printf("\n");
}

int valueAt(node *head, int index)
{
	if(index < 0 || index >= size(head))
	{
		printf("\nInvalid index value\n");
		exit(EXIT_FAILURE);
	}
	node *itr = head;
	int i = 0;
	if(0 == index)
	{
		return itr->data;
	}
	else if((size(head) -1 ) == index)
	{
		itr = goToEnd(head);
		return itr->data;
	}
	while( i++ < index)
	{	
		itr = itr->next;
	}
	return itr->data;
}

int main(void)
{
	node *head = NULL;

	assert(isEmpty(head) == true);
	//push_front(&head, 999);

	push_back(&head, 10);
	printList(head);
	assert(size(head) == 1);
	assert(isEmpty(head) == false);
	// assert(isEmpty(head) == false);

	push_back(&head, -20);
	printList(head);
	assert(size(head) == 2);

	push_back(&head, 30);
	printList(head);
	assert(size(head) == 3);

	push_back(&head, -350);
	printList(head);
	assert(size(head) == 4);


	// assert(pop_front(&head) == 10);
	// printList(head);
	// assert(size(head) == 3);

	// assert(pop_front(&head) == -20);
	// printList(head);
	// assert(size(head) == 2);

	// assert(pop_front(&head) == 30);
	// printList(head);
	// assert(size(head) == 1);

	// assert(pop_front(&head) == -350);
	// printList(head);
	// assert(size(head) == 0);

	// // assert(valueAt(head,0) == 999);
	// // assert(valueAt(head,1) == -20);
	// // assert(valueAt(head,2) == 30);
	// // assert(valueAt(head,3) == -350);
	// //assert(valueAt(head,-12) == 10);
	// //assert(valueAt(head,8) == 10);

	// push_back(&head, -100);
	// printList(head);
	// assert(size(head) == 5);

	// push_back(&head, 35);
	// printList(head);
	// assert(size(head) == 6);

	// push_back(&head, 32);
	// printList(head);
	// assert(size(head) == 7);

	// push_back(&head, 43);
	// printList(head);
	// assert(size(head) == 8);

	// push_front(&head, 800);
	// 	printList(head);
	// 	assert(size(head) == 9);
	// push_front(&head, 999);
	// 	printList(head);
	// 	assert(size(head) == 10);

	// assert(pop_back(head) == -350);
	// printList(head);
	// assert(size(head) == 3);


	// assert(pop_back(head) == 30);
	// printList(head);
	// assert(size(head) == 2);


	// assert(pop_back(head) == -20);
	// printList(head);
	// assert(size(head) == 1);


	// assert(pop_back(head) == 10);
	// printList(head);
	// assert(size(head) == 0);
	return 0;	
}