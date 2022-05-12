#include <stdio.h>

void runlinkedlist();
void assertInt(char *name, int actual, int expect);

typedef struct Node Node;

struct Node {
	int data;
	Node *next;
};

void runlinkedlist()
{
	Node n1, n2;

	n1.data = 5;
	n1.next = &n2;
	n2.data = 6;
	n2.next = NULL;

	printf("Node 1 Address: %p\n", (void *)(n1.next));
	printf("Node 2 Address: %p\n", (void *)(n1.next -> next));

    assertInt("Linked List: node 1 should return `5`", n1.data, 5);
    assertInt("Linked List: node 2 should return `6`", n1.next -> data, 6);
}
