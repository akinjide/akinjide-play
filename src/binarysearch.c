#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void runbinarysearch();
int recursive(int A[], int low, int high, int x);
int iterative(int A[], int n, int x);

void assertInt(char *name, int actual, int expect);

int recursive(int A[], int low, int high, int x)
{
    int mid;

    if (low > high)
    {
        return -1;
    }

    mid = low + (high - low) / 2;

    if (x == A[mid]) {
        return mid;
    } else if (x < A[mid]) {
        return recursive(A, low, mid - 1, x);
    } else {
        return recursive(A, mid + 1, high, x);
    }
}

int iterative(int A[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if (x == A[mid]) {
            return mid;
        } else if (x < A[mid])  {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1;
}

void runbinarysearch()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    assertInt("Binary Search: recursive approach should find `2`", recursive(A, 0, 10, 2), 1);
    assertInt("Binary Search: iterative approach should find `9`", iterative(A, 10, 9), 8);
}
