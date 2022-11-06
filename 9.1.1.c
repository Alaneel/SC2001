// Implementation of graph using Adjacency matrix 
// The directed graph version

#include <stdio.h>

int main()
{
    // n is the number of nodes and m is the number of edges
    int n, m;
    int a, b, i;
    int u, v;

    printf("Enter the number of nodes and edges: \n");
    scanf("%d %d", &n, &m);
    int adjMat[n][n];

    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)
        {
            adjMat[a][b] = 0;
        }
    }

    for (i=0; i<m; i++)
    {
        printf("Enter the source and destination of the edge: \n");
        scanf("%d %d", &u, &v);
        adjMat[u-1][v-1] = 1;
    }

    for (a=0; a<n; a++)
    {
        for (b=0; b<n; b++)
        {
            if (adjMat[a][b] == 1) printf("%d", adjMat[a][b]);
            else printf("%d", 0);
        }
        printf("\n");
    }

    return 0;
}