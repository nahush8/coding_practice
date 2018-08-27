#include<stdio.h>
#include<stdlib.h>
#define MAX_LENGTH 10


typedef struct Node{
	int value;
	struct Node* next;
} Node;

Node* allocate(void){
	Node *temp = NULL;
	temp = (Node*)malloc(sizeof(Node));
	return temp;
}

void createList(Node *head){
	Node *temp = NULL, *curr = head;
	if (head == NULL){
		printf("\nUnable to create list w/o creating head. Existing ..\n");
		exit(0);
	}
	int i = 0;
	for(i = 0 ; i < MAX_LENGTH-1 ; i++){
		temp = allocate();
		if(temp != 0){
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

void printList(Node *head){
	Node *curr = head;
	while(curr != NULL){
		if(curr -> next == NULL)
			printf("%d",curr->value);
		else 
			printf("%d -->",curr->value);
		curr = curr->next;
	}
	printf("\n");
}

int getLength(Node *head){
	int length = 0;
	Node *curr = head;
	while(curr != NULL){
		curr = curr->next;
		length++;
	}
	return length;
}
void bubbleSort(Node *head){
	Node *curr = head;
	int temp, length = 0, itr = 0;
	length = getLength(head);
	curr = head;
	while(length > 0){
		while(itr < length - 1){
			if(curr->value > curr->next->value){
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


void mergeSort(Node *head){
	
	

}

int main(){
	Node *head = NULL;
	head = allocate();
	if (head != NULL){
		head->value = 40;
	}
//	printf("\n%d\n",head);
	createList(head);
	printf("\n");
	printList(head);
	bubbleSort(head);
return 0;
}
