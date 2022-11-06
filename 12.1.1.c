// Towers of Hanoi

#include <stdio.h>

void TowersOfHanoi(int n, int from_rod, int to_rod, int aux_rod);

int main()
{
    int n = 4;
    printf("Moves for a %d disk problem are:\n", n);
    TowersOfHanoi(n, 'A', 'B', 'C');
    return 0;
}

void TowersOfHanoi(int n, int from_rod, int to_rod, int aux_rod)
{
    // Move n disks from tower x to tower y
    // Use tower z for intermediate storage
    if (n == 1)
    {
        // Move the largest disk from tower x to tower y
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    // Move n-1 disks from tower x to tower z
    // Use tower y for intermediate storage
    TowersOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    // Move n-1 disks from tower z to tower y
    // Use tower x for intermediate storage
    TowersOfHanoi(n-1, aux_rod, to_rod, from_rod);
}