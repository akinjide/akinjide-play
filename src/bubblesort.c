#include <stdio.h>

#define N 8

void runbubblesort();
void sort();

void assertIntN(char *name, int *actual, int *expect, int size);

void sort(int *numbers, int n) {
    int i, j, temp;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (*(numbers + j) < *(numbers + j + 1)) {
                temp = *(numbers + j);
                *(numbers + j) = *(numbers + j + 1);
                *(numbers + j + 1) = temp;
            }
        }
    }
}

void runbubblesort()
{
    int A[] = {7, 15, 4, 14, 2, 13, 5, 23};
    int desc[] = {23, 15, 14, 13, 7, 5, 4, 2};

    sort(A, N);
    assertIntN("Bubble Sort: should sort descending order", A, desc, N);
}

