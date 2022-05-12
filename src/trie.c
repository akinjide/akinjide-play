#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assert.h"

#define ALPHABETS 26
#define WORDS 5

typedef struct TrieNode TrieNode;

struct TrieNode {
	TrieNode *children[ALPHABETS];
	int isEnd;
};

void runtrie();
TrieNode *getNode();
void insert();
int search();

void assertInt(char *name, int actual, int expect);

TrieNode *getNode()
{
	TrieNode *node = NULL;
	node = (TrieNode *)malloc(sizeof(TrieNode));

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

void insert(TrieNode *root, char *key)
{
	int index;
	int level;
	TrieNode *crawlNode = root;

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

int search(TrieNode *root, char *key)
{
	int index;
	int level;
	TrieNode *crawlNode = root;

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

void runtrie()
{
	TrieNode *root = NULL;
	char keys[WORDS][8] = {"bag", "boy", "goat", "helm", "boat"};
	int i;

	root = getNode();

	for (i = 0; i < WORDS; i++)
	{
		insert(root, keys[i]);
	}

    assertInt("Trie: should find `helm`", search(root, "helm"), 1);
    assertInt("Trie: should find `boy`", search(root, "boy"), 1);
    assertInt("Trie: should find `goat`", search(root, "goat"), 1);
    assertInt("Trie: should find `boat`", search(root, "boat"), 1);
    assertInt("Trie: should not find `ball`", search(root, "ball"), 0);
    assertInt("Trie: should not find `human`", search(root, "human"), 0);
}
