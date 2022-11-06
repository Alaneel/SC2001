// m Coloring Problem

#include <stdio.h>
#include <stdbool.h>
#define V 4 // Number of vertices in the graph

void printSolution(int color[]);
bool isSafe(bool graph[V][V], int color[]);
bool graphColoring(bool graph[V][V], int m, int i, int color[V]);

int main()
{
    /* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */

    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    int m = 3; // Number of colors
    int i = 0;

    // Initialize all color values as 0
    // This initialization needs correct functioning of isSafe()
    int color[V];

    for (i=0; i<V; i++) color[i] = 0;

    if (!graphColoring(graph, m, 0, color)) printf("Solution does not exist");

    return 0;
}

// A utility function to print solution
void printSolution(int color[])
{
    int i = 0;

    printf("Solution exists: following are the assigned colors \n");
    for (i=0; i<V; i++) printf(" %d ", color[i]);
    printf("\n");
}

// Check if the colored graph if safe or not
bool isSafe(bool graph[V][V], int color[])
{
    int i = 0, j = 0;

    // Check for every edge
    for (i=0; i<V; i++)
        for (j=0; j<V; j++)
            if (graph[i][j] && color[j] == color[i])
                return false;
    return true;
}

// This function solves the m Coloring problem using recursion
// It returns false if the m colors cannot be assigned, otherwise, return true and prints assignments of colors to all vertices
// Please note that there may be more than one solutions, this function prints one of the feasible solutions
bool graphColoring(bool graph[V][V], int m, int i, int color[V])
{
    int j = 0;

    // if current index reached end
    if (i == V)
    {
        // If coloring is safe
        if (isSafe(graph, color))
        {
            // Print the solution
            printSolution(color);
            return true;
        }
        return false;
    }

    // Assign each color from 1 to m
    for (j=1; j<=m; j++)
    {
        color[i] = j;

        // Recur of the rest vertices
        if (graphColoring(graph, m, i+1, color))
            return true;
        
        color[i] = 0;
    }

    return false;
}