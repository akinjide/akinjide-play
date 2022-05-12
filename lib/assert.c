#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char status[][5] = {"FAIL", "PASS"};

void assert(char *name, int state)
{
    printf("[%s] %s\n", status[state], name);
}

void assertInt(char *name, int actual, int expect)
{
    if (actual != expect) {
    	assert(name, 0);
    	exit(1);
    }

    assert(name, 1);
}

void assertIntN(char *name, int *actual, int *expect, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        if (*(actual+i) != *(expect+i)) {
            printf("Error: expect=%d but got=%d\n", *(expect + i), *(actual + i));
            assert(name, 0);
            exit(1);
        }
    }

    assert(name, 1);
}

void assertStr(char *name, char *actual, char *expect)
{
    if (strcmp(actual, expect) != 0) {
    	assert(name, 0);
    	exit(1);
    }

    assert(name, 1);
}

void assertBool(char *name, int actual)
{
    if (actual) {
        assert(name, 0);
        exit(1);
    }

    assert(name, 1);
}
