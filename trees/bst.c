#include<stdio.h>
#include<stdlib.h>

#define MAX_QUEUE_SIZE 1000

typedef struct TreeNode
{	
	int data;
	struct TreeNode* left;
	struct TreeNode* right;

}node;

node* newNode(int value)
{

	node* temp = (node*)malloc(sizeof(node));
	if(!temp)
	{
		printf("\nCannot allocate memory.\n");
		exit(EXIT_FAILURE);
	}
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void inorder(node *root)
{
	if(NULL == root)
		return;
	inorder(root->left);
	printf("%d\t",root->data);
	inorder(root->right);
}

void preorder(node *root)
{
	if(NULL == root)
		return;
	printf("%d\t",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root)
{
	if(NULL == root)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\t",root->data);
}

node** createQueue(){
 	node **queue = (node**)malloc(sizeof(node*) * MAX_QUEUE_SIZE);
 	return queue;
}
 
void enQueue(node** queue, int* rear, node* newNode)
{
	queue[*rear] = newNode;
	(*rear)++;	

}

node* deQueue(node** queue, int* front)
{
	return queue[(*front)++];
 
}

void levelTraverse(node* root)
{
	int rear=0 , front=0;
	node** queue = createQueue();
	node* temp = root;

	while(temp)
	{
		printf("%d\t",temp->data);
		if(temp->left)
			enQueue(queue, &rear, temp->left);
		if(temp->right)
			enQueue(queue, &rear, temp->right);
		temp = deQueue(queue, &front);
	}

}
int main()
{

	node* root = NULL;
	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->right = newNode(4);
	root->right->left = newNode(5);
	
	inorder(root);
	printf("\n");
	postorder(root);
	printf("\n");
	preorder(root);
	printf("\n");
	//levelTraverse(root);
	printf("\n");
	return 0;
}