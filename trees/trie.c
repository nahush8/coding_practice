#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>

#define ALPHABET_SIZE 26
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

//TODO: Add code to sort array of strings using Tries

//trie node
typedef struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;

}node;

node* getNode()
{
	node *temp = (node*)malloc(sizeof(node));
	if(temp)
	{
		int i;
		temp->isEndOfWord = false;
		for(i = 0 ; i < ALPHABET_SIZE ; i++)
		{
			temp->children[i] = NULL;
		}
	}
	return temp;
}

void insert(node *root, const char *key)
{
	if(NULL == root)
	{
		printf("\nEmpty trie\n");
		return;
	}
	else
	{
		int i;
		int length = strlen(key);
		int index;
		node *ptr = root;

		for(i = 0 ; i < length ; i++)
		{
			index = CHAR_TO_INDEX(key[i]);
			if(!ptr->children[index])
			{
				ptr->children[index] = getNode();
			}
			ptr = ptr->children[index] ;
		}
		ptr->isEndOfWord = true;
	}

}

bool search(node *root, const char *key)
{
	if(NULL == root)
	{
		printf("\nEmpty trie\n");
		exit(0);
	}
	else
	{
		int i;
		int length = strlen(key);
		int index;
		node *ptr = root;

		for(i = 0 ; i < length ; i++)
		{
			index = CHAR_TO_INDEX(key[i]);
			if(!ptr->children[index])
				return false;
			ptr = ptr->children[index] ;
		}
		ptr->isEndOfWord = true;
		return (NULL != ptr && ptr->isEndOfWord);
	}



}

int main(void)
{
	// Input keys (use only 'a' through 'z' and lower case)
    char keys[][8] = {"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
 
    char output[][32] = {"Not present in trie", "Present in trie"};
 
 
    node *root = getNode();
    int i = 0 ;
    // Insert all the keys into the tree
    for(i = 0 ; i < ARRAY_SIZE(keys); i++)
    {
    	insert(root, keys[i]);
    }
  	// Search for different keys
    printf("%s --- %s\n", "the", output[search(root, "the")] );
    printf("%s --- %s\n", "these", output[search(root, "these")] );
    printf("%s --- %s\n", "their", output[search(root, "their")] );
    printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
      printf("%s --- %s\n", "answer", output[search(root, "answer")] );
        printf("%s --- %s\n", "answered", output[search(root, "answered")] );
 
    return 0;
}