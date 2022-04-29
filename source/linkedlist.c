#include <stdio.h>

struct node {
	int data;
	struct node *next;
};

void initlinkedlist()
{
	struct node n1, n2;

	n1.data = 5;
	n1.next = &n2;
	n2.data = 6;
	n2.next = NULL;

    printf("\n\nLinked List\n\n");
	printf("Node 1: %d\n", n1.data);
	printf("Node 2: %d\n", n1.next -> data);
	printf("Node 1 Address: %p\n", (void *)(n1.next));
	printf("Node 2 Address: %p\n", (void *)(n1.next -> next));
}
