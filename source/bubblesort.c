#include <stdio.h>

#define N 8

void initbubblesort();
void sort();

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

void initbubblesort()
{
    int i;
    int A[] = {7, 15, 4, 14, 2, 13, 5, 23};
    printf("\n\nBubble Sort\n\n");

    sort(A, N);

    printf("SORTED: DESC\n");
    for (i = 0; i < N; i++) {
        printf("%d ", *(A + i));
    }
}

