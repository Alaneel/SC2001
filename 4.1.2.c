// Binary Search (Ordered Array)

#include <stdio.h>

int binarySearch(int E[], int first, int last, int k);

int main()
{
    int E[15] = {6, 13, 14, 25, 33, 43, 51, 53, 64, 72, 84, 93, 95, 96, 97};
    printf("binarySearch(): %d", binarySearch(E, 0, 14, 33));
    return 0;
}

int binarySearch(int E[], int first, int last, int k)
{
    if (last < first) return -1;
    else 
    {
        int mid = (first + last) / 2;
        if (k == E[mid]) return mid;
        else if (k < E[mid]) return binarySearch(E, first, mid-1, k);
        else return binarySearch(E, mid+1, last, k);
    }
}