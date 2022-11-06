#include <stdio.h>
#define SIZE 6

void insertionSort(int slot[], int n);

int main()
{
    int slot[SIZE] = {45, 29, 06, 64, 12, 16};
    int k;

    printf("Before sorting:\n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    insertionSort(slot, SIZE);

    printf("After sorting: \n");
    for (k=0; k<SIZE; k++)
    {
        printf("%d: %d\n", k, slot[k]);
    }
    printf("\n");

    return 0;
}

void insertionSort(int slot[], int n)
{
    int tmp;

    // input slot is an array of n records
    // assume n > 1
    for (int i=1; i<n; i++)
    {
        for (int j=i; j>0; j--)
        {
            if (slot[j] < slot[j-1])
            {
                tmp = slot[j];
                slot[j] = slot[j-1];
                slot[j-1] = tmp;
            }
            else break;
        }
    }
}