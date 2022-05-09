#include <stdio.h>
#include <stdlib.h>

#define STACKSIZE 100

struct stack {
    int top;
    int items [STACKSIZE];
};

void initstack();
int stacktop(struct stack *s);
int pop(struct stack *s);
void push(struct stack *s, int x);
int empty(struct stack *s);

int stacktop(struct stack *s)
{
    if (empty(s)) {
        printf("Stack underflow");
        return -1;
    }

    return s -> items[s -> top];
}

int pop(struct stack *s)
{
    if (empty(s)) {
        printf("Stack underflow");
        return -1;
    }

    return s -> items[s -> top--];
}

void push(struct stack *s, int x)
{
    if (s -> top == STACKSIZE - 1) {
        printf("Stack overflow");
        exit(1);
    }

    printf("push --- %d\n", x);
    s -> items[++s -> top] = x;
}

int empty(struct stack *s)
{
    if (s -> top == -1) {
        return 1;
    }

    return 0;
}

void initstack()
{
    int i;
    struct stack p;
    p.top = -1;

    printf("\n\nStack\n\n");
    push(&p, 2);
    push(&p, 3);
    push(&p, 4);
    push(&p, 5);
    push(&p, 6);
    push(&p, 7);

    for (i = p.top; i >= 0; i--) {
        printf("top before pop --- %d\n", p.top);
        printf("pop --- %d\n", pop(&p));
        printf("top after pop --- %d\n", p.top);
    }
}
