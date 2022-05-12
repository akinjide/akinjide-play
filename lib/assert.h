extern void assert(char *name, int state);
extern void assertInt(char *name, int actual, int expect);
extern void assertIntN(char *name, int *actual, int *expect, int size);
extern void assertStr(char *name, char *actual, char *expect);
extern void assertBool(char *name, int actual);
