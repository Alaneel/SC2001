// Sequential search (Unordered Array)

#include <stdio.h>
#define SIZE 1000

int seqSearch(int E[], int n, int k);

int main()
{
    int E[SIZE], n, i, key;
    printf("Enther the size of your array: \n");
    scanf("%d", &n);

    printf("Enther the numbers: \n");
    for (i=0; i<n; i++)
    {
        scanf("%d", &E[i]);
    }

    printf("Enter the number to be found: \n");
    scanf("%d", &key);

    printf("seqSearch(): %d\n", seqSearch(E, n, key));

    return 0;
}

int seqSearch(int E[], int n, int k)
{
    int index;

    for (index=0; index<n; index++)
        if (k == E[index]) return index;

    return -1;
}