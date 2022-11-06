// Maze Navigating

#include <stdio.h>
#include <stdbool.h>
#define SIZE 10

void printSolution(int sol[SIZE][SIZE]);
bool isSafe(int maze[SIZE][SIZE], int x, int y);
bool solveMaze(int maze[SIZE][SIZE]);
bool findPath(int maze[SIZE][SIZE], int x, int y, int sol[SIZE][SIZE]);

int main()
{
    int maze[SIZE][SIZE] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    solveMaze(maze);

    return 0;
}

// A utility function to print solution matrix sol[SIZE][SIZE]
void printSolution(int sol[SIZE][SIZE])
{
    int i = 0, j = 0;

    for (i=0; i<SIZE; i++)
    {
        for (j=0; j<SIZE; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

// A utility function to check if x, y is valid index for SIZE * SIZE maze
bool isSafe(int maze[SIZE][SIZE], int x, int y)
{
    // if (x, y outside maze) return false
    if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 1)
        return true;
    return false;
}

// This function solves the maze problem using backtracking
// It mainly uses findPath() to solve the problem
// It returns false if no path is possible, otherwise return true and prints the path in the form of 1s
// Please note that there may be more than one solutions, this function prints one of the feasible solutions
bool solveMaze(int maze[SIZE][SIZE])
{
    int sol[SIZE][SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    if (findPath(maze, 0, 0, sol) == false)
    {
        printf("Solutions does not exist\n");
        return false;
    }
    printSolution(sol);
    return true;
}

// A recursive utility function to solve Maze problem
bool findPath(int maze[SIZE][SIZE], int x, int y, int sol[SIZE][SIZE])
{
    // if (x, y is goal) return true
    if (x == SIZE - 1 && y == SIZE - 1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }

    // check if maze[x][y] is valid
    if (isSafe(maze, x, y) == true)
    {
        // check if the current block is already part of the solution path
        if (sol[x][y] == 1)
            return false;
        // mark x, y as part of the solution path
        sol[x][y] = 1;
        // move forward in x direction
        if (findPath(maze, x+1, y, sol) == true)
            return true;
        // if moving in x direction does not give solution
        // then move down in y direction
        if (findPath(maze, x, y+1, sol) == true)
            return true;
        // if none of the above movements work then BACKTRACK: unmark x, y as part of the solution path
        sol[x][y] = 0;
        return false;
    }
    return false;
}