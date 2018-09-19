#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#define MAX_QUEUE_SIZE 1000

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
/**
 Implement:
 DONE insert // insert value into tree
 DONE get_node_count // get count of values stored
 DONE print_values // prints the values in the tree, from min to max
 delete_tree
 DONE is_in_tree // returns true if given value exists in the tree
 get_height // returns the height in nodes (single node's height is 1)
 DONE get_min // returns the minimum value stored in the tree
 DONE get_max // returns the maximum value stored in the tree
 is_binary_search_tree
 delete_value
 get_successor // returns next-highest value in tree after given value, -1 if none

*/

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

//Pointer to pointer so we can have return type void.
void insert(node **rootRef, int value)
{
	if(NULL == *rootRef)
	{
		*rootRef = newNode(value);
	}
	else if (value <= (*rootRef)->data)
	{	
		insert(&((*rootRef)->left), value);
	}

	else if (value > (*rootRef)->data)
	{	
		insert(&((*rootRef)->right), value);
	}
}

bool is_in_tree(node *root, int value)
{
	if(NULL == root)
	{
		return false;
	}
	else if(value == root->data)
	{
		return true;
	}
	else if(value <= root->data)
	{	
		is_in_tree(root->left, value);
	}
	else if(value > root->data)
	{	
		is_in_tree(root->right, value);
	}
}

int findMin(node *root)
{
	if(NULL == root)
	{
		printf("\nEmpty tree.\n");
		exit(0);
	}
	else
	{
		while(root->left)
		{
			root = root->left;
		}
		return root->data;
	}

}

int findMax(node *root)
{
	if(NULL == root)
	{
		printf("\nEmpty tree.\n");
		exit(0);
	}
	else
	{
		while(root->right)
		{
			root = root->right;
		}
		return root->data;
	}


}

int get_node_count(node *root)
{
	int count = 1;
	if(NULL == root)
	{
		printf("\nEmpty tree.\n");
		exit(0);
	}
	else
	{
		if(root->left)
		{
			count += get_node_count(root->left);
		}
		if(root->right)
		{
			count += get_node_count(root->right);
		}
		return count;
	}

}

int get_height(node *root)
{
	if(root == NULL)
	{
		return -1;
	}
	return MAX(get_height(root->left), get_height(root->right)) + 1;
}

int main()
{

	node* root = NULL;
	int value[] = {4,7,1,12,45,6, -5, 0, 274, 34836, -99};
	int i;
	for(i = 0 ; i < sizeof(value)/sizeof(value[0]) ; i++)
		insert(&root, value[i]);
	inorder(root);
	// printf("\n");
	// postorder(root);
	// printf("\n");
	// preorder(root);
	// printf("\n");
	//levelTraverse(root);
	assert(is_in_tree(root, 7) == true);
	assert(is_in_tree(root, 77) == false);
	printf("\nMin value: %d\n", findMin(root));
	printf("\nMax value: %d\n", findMax(root));
	printf("\nNode count: %d\n", get_node_count(root));
	printf("\nHeight of Tree: %d\n", get_height(root));
	printf("\n");
	return 0;
}