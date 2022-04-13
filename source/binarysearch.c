#include <stdio.h>

void binarySearch();
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

void binarySearch()
{
    int k, x, y;
    int A[] = {2, 4, 5, 7, 13, 14, 15, 23};
    printf("\nBinary Search\n\n");
    printf("Enter a number: ");
    scanf("%d", &k);

    x = recursive(A, 0, 8, k);
    y = iterative(A, 8, k);

    printf("\nrecursive approach: %d", x);
    printf("\niterative approach: %d", y);
}
