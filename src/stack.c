#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

typedef struct {
    int top;
    int items [STACKSIZE];
} Stack;

void runstack();
int stacktop(Stack *s);
int pop(Stack *s);
void push(Stack *s, int x);
int empty(Stack *s);

void assertInt(char *name, int actual, int expect);

int stacktop(Stack *s)
{
    if (empty(s)) {
        printf("Stack underflow");
        return -1;
    }

    return s -> items[s -> top];
}

int pop(Stack *s)
{
    if (empty(s)) {
        printf("Stack underflow\n");
        return -1;
    }

    return s -> items[s -> top--];
}

void push(Stack *s, int x)
{
    if (s -> top == STACKSIZE - 1) {
        printf("Stack overflow\n");
        exit(1);
    }

    s -> items[++s -> top] = x;
}

int empty(Stack *s)
{
    if (s -> top == -1) {
        return 1;
    }

    return 0;
}

void runstack()
{
    Stack p;
    p.top = -1;

    push(&p, 2);
    push(&p, 3);
    push(&p, 4);
    push(&p, 5);
    push(&p, 6);
    push(&p, 7);

    assertInt("Stack: should not be empty", empty(&p), 0);
    assertInt("Stack: should pop `7`", pop(&p), 7);
    assertInt("Stack: should pop `6`", pop(&p), 6);
    assertInt("Stack: should pop `5`", pop(&p), 5);
    assertInt("Stack: should return `4` as stacktop", stacktop(&p), 4);
    assertInt("Stack: should not be empty", empty(&p), 0);
    assertInt("Stack: should pop `4`", pop(&p), 4);
    assertInt("Stack: should pop `3`", pop(&p), 3);
    assertInt("Stack: should pop `2`", pop(&p), 2);
    assertInt("Stack: should not pop `-1`", pop(&p), -1);
    assertInt("Stack: should be empty", empty(&p), 1);
}
