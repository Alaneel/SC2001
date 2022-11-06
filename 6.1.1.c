// Merge Sort

#include <stdio.h>
#define SIZE 8

int compare(int m, int n);
void merge(int slot[], int n, int m);
void mergeSort(int slot[], int n, int m);

int main()
{
    int slot[SIZE] = {90, 25, 10, 71, 94, 22, 59, 74};
    int k;

    printf("Before sorting:\n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    mergeSort(slot, 0, SIZE);

    printf("After sorting: \n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    return 0;
}

int compare(int m, int n)
{
    if (m == n) return 0;
    else if (m > n) return 1;
    else return -1;
}

void merge(int slot[], int n, int m)
{
    int mid = (m + n) / 2;
    int a = n, b = mid + 1, i, cmp, tmp;

    if (m - n <= 0) return;
    while (a <= mid && b <= m)
    {
        cmp = compare(slot[a], slot[b]);
        if (cmp > 0) // slot[a] > slot[b]
        {
            tmp = slot[b++];
            for (i=++mid; i>a; i--) slot[i] = slot[i-1];
            slot[a++] = tmp;
        }
        else if (cmp < 0) a++; // slot[a] < slot[b]
        else // slot[a] = slot[b]
        {
            if (a == mid && b == m) break;
            tmp = slot[b++];
            a++;
            for (i=++mid; i>a; i--) slot[i] = slot[i-1];
            slot[a++] = tmp;
        }
    }
}

void mergeSort(int slot[], int n, int m)
{
    int mid = (n + m) / 2;
    if ((m - n) <= 0) return;
    else if (m - n > 1)
    {
        mergeSort(slot, n, mid);
        mergeSort(slot, mid+1, m);
    }
    merge(slot, n, m);    
}