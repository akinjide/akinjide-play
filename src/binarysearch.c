#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initbinarySearch();
int recursive(int A[], int low, int high, int x);
int iterative(int A[], int n, int x);

int recursive(int A[], int low, int high, int x)
{
    int mid;
    if (low > high) return -1;

    mid = low + (high - low) / 2;

    if (x == A[mid]) return mid;
    else if (x < A[mid]) return recursive(A, low, mid - 1, x);
    else return recursive(A, mid + 1, high, x);
}

int iterative(int A[], int n, int x)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (x == A[mid]) return mid;
        else if (x < A[mid]) high = mid - 1;
        else low = mid + 1;
    }

    return -1;
}

void initbinarySearch()
{
    int k, x, y;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("\nBinary Search\n\n");
    srand(time(0));
    k = rand() % 10 + 1;
    printf("Searching for number -- %d", k);

    x = recursive(A, 0, 10, k);
    y = iterative(A, 10, k);

    printf("\nrecursive approach index: %d", x);
    printf("\niterative approach index: %d", y);
}
