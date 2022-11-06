#include <stdio.h>

int main()
{
    int j = 1, n, factorial = 1;

    printf("Enter the value for j: \n");
    scanf("%d", &n);

    while (j <= n)
    {
        factorial *= j;
        j++;
    }

    printf("factorial(%d): %d\n", n, factorial);

    return 0;
}