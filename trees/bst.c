#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<limits.h>
#define MAX_QUEUE_SIZE 10

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
/**
 Implement:
 DONE insert // insert value into tree
 DONE get_node_count // get count of values stored
 DONE print_values // prints the values in the tree, from min to max
 delete_tree
 DONE is_in_tree // returns true if given value exists in the tree
 DONE get_height // returns the height in nodes (single node's height is 1)
 DONE get_min // returns the minimum value stored in the tree
 DONE get_max // returns the maximum value stored in the tree
 is_binary_search_tree
 DONE delete_value
 get_successor // returns next-highest value in tree after given value, -1 if none

*/

typedef struct TreeNode
{	
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}node;


typedef struct queue
{
	int front, rear, size;
	int cap;
	node **arr;
}queue;

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

queue* createQueue(int cap){
	queue *q = (queue*) malloc(sizeof(queue));
	if(!q)
	{
		printf("\nUnable to allocate memory\n");
		exit(EXIT_FAILURE);
	}
	q->front = 0;
	q->rear = cap-1;
	q->cap = cap;
	q->size = 0;
 	q->arr = (node**)malloc(sizeof(node*) * cap);
 	return q;
}

bool isFull(queue *q)
{
	return (q->size == q->cap);
}

bool isEmpty(queue *q)
{
	return (0 == q->size);
}
 
void enQueue(queue *q, node* newNode)
{
	if(!isFull(q))
	{
		q->arr[++q->rear % q->cap] = newNode;
		q->size++;
	}
	else
	{
		printf("\nQueue is full. Cannot enqueue. Dequeue something first.\n");
		return;
	}

}

node* deQueue(queue *q)
{
	if(!isEmpty(q))
	{
		q->size--;
		return q->arr[q->front++ % q->cap];
	}
	else
	{
		//printf("\nQueue is Empty. Cannot Dequeue. \n");
		return NULL;
	}
 
}

void levelTraverse(node* root)
{
	int rear=0 , front=0;
	queue *q = createQueue(MAX_QUEUE_SIZE);
	node* temp = root;

	while(temp)
	{
		printf("%d\t",temp->data);
		if(temp->left)
			enQueue(q, temp->left);
		if(temp->right)
			enQueue(q, temp->right);
		temp = deQueue(q);
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

node* findMin(node *root)
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
		return root;
	}

}

int findMinVal(node *root)
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


void delete(node **rootRef, int value)
{
	if(NULL == *rootRef)
	{
		printf("\nEmpty tree\n");
		exit(0);
	}
	else if(value < (*rootRef)->data)
	{
		delete(&((*rootRef)->left), value);
	}
	else if(value > (*rootRef)->data)
	{
		delete(&((*rootRef)->right), value);
	}
	else
	{
		//case 1: No child
		if(NULL == (*rootRef)->left && NULL == (*rootRef)->right)
		{
			free(*rootRef);
			*rootRef = NULL; 
		}
		//case 2: One child on the right
		else if(NULL == (*rootRef)->left)
		{
			node *temp = *rootRef;
			*rootRef = (*rootRef)->right;
			free(temp);
		}
		//case 2 : One child on the left
		else if(NULL == (*rootRef)->right)
		{
			node *temp = *rootRef;
			*rootRef = (*rootRef)->left;
			free(temp);
		}
		//Case 3: 2 Children.
		else
		{
			node *temp = findMin((*rootRef)->right);
			(*rootRef)->data = temp->data;
			delete(&((*rootRef)->right), temp->data);
		}	

	}
}


bool isBSTNaive(node *root)
{
	if(NULL == root)
	{
		return true;
	}

	if((NULL != root->left) && (findMax(root->left) > root->data))
	{
		return false;
	}
	
	if((NULL != root->right) && (findMinVal(root->right) < root->data))
	{
		return false;
	}	
	if(!(isBSTNaive(root->left)) || !isBSTNaive(root->right))
	{
		return false;
	}
	return true;
}

// Recursively check the values tightening the min/max bounds
bool isBSTUtil(node *root, int min, int max)
{
	if(NULL == root)
	{
		return true;
	}
	if(root->data < min || root->data > max)
	{
		return false;
	}
	return (isBSTUtil(root->left, min, root->data - 1) && isBSTUtil(root->right, root->data+1, max));
}

bool isBST(node *root)
{
	return isBSTUtil(root, INT_MIN, INT_MAX);    //Helper function. See description.
}

// Get the next highest value after a given valur
// Inorder successor.
// If right subtree is not null of the given node, then the succsessor is min value of node->right subtree. 
// If right subtree is null, start from root, and save the successor in each case
int get_successor(node *root, node *n)
{
	if(NULL == root || NULL == n)
	{
		printf("\n Invalid node. Exiting..\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if(NULL != n->right)
		{
			return findMinVal(n->right);
		}
		else
		{
			node *succ = NULL;
			while(root)
			{
				if(n->data < root->data)
				{
					succ = root;
					root=root->left;
				}
				else if(n->data > root->data)
				{
					root = root->right;
				}
				else
					break;
			}
			if(succ)
				return succ->data;
			else
			{
				printf("\nNode possibly doesn't exist\n");
			}
		}
	}

}

int main()
{

	node* root = NULL;
	//int value[] = {4,7,1,12,45,6, -5, 0, 274, 34836, -99};
	int value[] = {4,7,1,12, -5, -2, 2};
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
	node *min = findMin(root);
	printf("\nMin value: %d\n", min->data);
	printf("\nMax value: %d\n", findMax(root));
	printf("\nNode count: %d\n", get_node_count(root));
	printf("\nHeight of Tree: %d\n", get_height(root));
	printf("\n");
	levelTraverse(root);
	//delete(&root,4);
	printf("\n");
	levelTraverse(root);
		printf("\n");
	assert(isBSTNaive(root) == true);
	assert(isBST(root) == true);
	//root->right->data = 1;
	assert(root->data == 4);
	assert(get_successor(root, root->left->right) == 4);	
	return 0;
}