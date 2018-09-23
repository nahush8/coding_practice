#include<bits/stdc++.h>
using namespace std;


#define ALPHABET_SIZE 26
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

typedef struct Trie
{
	Trie *children[ALPHABET_SIZE];	
    // index is set when node is a leaf
    // node, otherwise -1;
	int index;
	Trie()
	{
		for(int i = 0; i < ALPHABET_SIZE ; i++)
		{
			children[i] = NULL;
		}
		index  = -1;
	}

}node;

void insert(node *root, string str, int index)
{
	if(NULL == root)
	{
		printf("\nEmpty trie\n");
		return;
	}
	else
	{
		char ind;
		node *ptr = root;
		for(int i = 0 ; i < str.size() ; i++)
		{
			ind = str[i] - 'a';
			if(!ptr->children[ind])
			{
				ptr->children[ind] = new Trie();
			}
			ptr = ptr->children[ind] ;
		}
		ptr->index = index;
	}

}

bool preorder(node *root, string arr[])
{
	if(NULL == root)
	{
		return false;
	}
	for(int i = 0 ; i < ALPHABET_SIZE ; i++)
	{
		if(NULL != root->children[i])
		{
			if(-1 != root->children[i]->index)
			{
				cout<< arr[root->children[i]->index]<< endl;
			}
			preorder(root->children[i], arr);
		}	
	}

}

void printSorted(string arr[], int n)
{
	node *root = new Trie();
	printf("\nArray size: %d\n", n);
	for(int i = 0 ; i < n ; i++)
	{
		insert(root, arr[i], i);
	}
	preorder(root, arr);
}

int main()
{
 	string arr[] = {"geeks", "for", "geeks", "a", "portal", 
        "to", "learn", "can", "be", "computer", 
        "science", "zoom", "yup", "fire", "in", "data""geeks", "for", "geeks"};
    printSorted(arr, ARRAY_SIZE(arr));
    return 0;
}