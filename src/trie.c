#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABETS 26
#define WORDS 5

struct trieNode {
	struct trieNode *children[ALPHABETS];
	int isEnd;
};

void inittrie();
struct trieNode *getNode();
void insert();
int search();

struct trieNode *getNode()
{
	struct trieNode *node = NULL;
	node = (struct trieNode *)malloc(sizeof(struct trieNode));

	if (node)
	{
		int i;
		node -> isEnd = 0;

		for (i = 0; i < ALPHABETS; i++)
		{
			node -> children[i] = NULL;
		}
	}

	return node;
}

void insert(struct trieNode *root, char *key)
{
	int index;
	int level;
	struct trieNode *crawlNode = root;

	for (level = 0; level < strlen(key); level++)
	{
		index = ((int)key[level] - (int)'a');

		if (!crawlNode -> children[index]) {
			crawlNode -> children[index] = getNode();
		}

		crawlNode = crawlNode -> children[index];
	}

	crawlNode -> isEnd = 1;
}

int search(struct trieNode *root, char *key)
{
	int index;
	int level;
	struct trieNode *crawlNode = root;

	for (level = 0; level < strlen(key); level++)
	{
		index = ((int)key[level] - (int)'a');

		if (!crawlNode -> children[index]) {
			return 0;
		}

		crawlNode = crawlNode -> children[index];
	}

	return crawlNode -> isEnd;
}

void inittrie()
{
	struct trieNode *root = NULL;
	char keys[WORDS][8] = {"bag", "boy", "goat", "helm", "boat"};
	int i;

	printf("\n\nTrie\n\n");
	root = getNode();


	for (i = 0; i < WORDS; i++)
	{
		insert(root, keys[i]);
	}

	printf("Found: helm= %d\n", search(root, "helm"));
	printf("Found: boy= %d\n", search(root, "boy"));
	printf("Not Found: ball= %d\n", search(root, "ball"));
}
