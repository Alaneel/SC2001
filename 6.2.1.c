// Quick Sort

#include <stdio.h>
#define SIZE 10

void swap(int slot[], int a, int b);
int partition(int slot[], int low, int high);
void quickSort(int slot[], int n, int m);

int main()
{
    int slot[SIZE] = {77, 15, 96, 89, 42, 80, 35, 04, 93, 06};
    int k;

    printf("Before sorting:\n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    quickSort(slot, 0, SIZE);

    printf("After sorting: \n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    return 0;
}

void swap(int slot[], int a, int b)
{
    int tmp = 0;
    tmp = slot[a];
    slot[a] = slot[b];
    slot[b] = tmp;
}

int partition(int slot[], int low, int high)
{
    int i = 0, last_small = 0, pivot = 0;
    int mid = (low + high) / 2;

    swap(slot, low, mid);
    pivot = slot[low];
    last_small = low; 

    for (i=low+1; i<=high; i++)
        if (slot[i] < pivot)
            swap(slot, ++last_small, i);
    swap(slot, low, last_small);
    return last_small;
}

void quickSort(int slot[], int n, int m)
{
    int pivot_pos = 0;

    if (n >= m) return;
    pivot_pos = partition(slot, n, m);
    quickSort(slot, n, pivot_pos - 1);
    quickSort(slot, pivot_pos + 1, m);

}