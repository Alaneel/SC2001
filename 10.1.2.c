// DFS Algorithm in C

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int vertex;
    struct node *next;
} Node;

typedef struct graph {
    int numVertices;
    int *visited;
    Node **adjLists;
    // We need int ** to store a two dimensional array
    // Similarly, we need struct node ** to store an array
} Graph;

Node *createNode(int v);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void printGraph(Graph *graph);
void DFS(Graph *graph, int vertex);

int main()
{
    Graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);

    printGraph(graph);

    DFS(graph, 2);

    printf("\n");

    return 0;
}

// Create a node
Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->adjLists = malloc(vertices * sizeof(Node));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i=0; i<vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add Edge
void addEdge(Graph *graph, int src, int dest)
{
    // Add Edge from src to dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(Graph *graph)
{
    int v;
    for (v=0; v<graph->numVertices; v++)
    {
        Node *temp = graph->adjLists[v];
        printf("\nAdjacency list of vertex %d\n", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// DFS algo
void DFS(Graph *graph, int vertex)
{
    Node *adjList = graph->adjLists[vertex];
    Node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("\nVisited %d \n", vertex);

    while (temp != NULL)
    {
        int connectVertex = temp->vertex;

        if (graph->visited[connectVertex] == 0)
        {
            DFS(graph, connectVertex);
        }
        temp = temp->next;
    }
}