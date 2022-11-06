// BFS Algorithm in C

#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

typedef struct queue {
    int items[SIZE];
    int front;
    int rear;
} Queue;

typedef struct node {
    int vertex;
    struct node *next;
} Node;

typedef struct graph {
    int numVertices;
    Node **adjLists;
    int *visited;
} Graph;

Queue *createQueue();
void enqueue(Queue *q, int);
int dequeue(Queue *q);
int isEmpty(Queue *q);
void printQueue(Queue *q);

Node *createNode(int v);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void bfs(Graph *graph, int startVertex, Queue *q);

int main()
{
    Queue *q = createQueue();

    Graph *graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 4);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    bfs(graph, 0, q);

    printf("\n");
    
    return 0;
}

// Create a queue
Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Adding elements into queue
void enqueue(Queue *q, int value)
{
    if (q->rear == SIZE - 1) printf("\nQueue is FULL!!");
    else 
    {
        if (q->front == -1) q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Removing items from queue
int dequeue(Queue *q)
{
    int item;
    if (isEmpty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            printf("Resetting queue\n");
            q->front = q->rear = -1;
        }
    }
    return item;
}

// Check if the queue is empty
int isEmpty(Queue *q)
{
    if (q->rear == -1) return -1;
    else return 0;
}

// Print the queue
void printQueue(Queue *q)
{
    int i = q->front;

    if (isEmpty(q))
    {
        printf("Queue is empty");
    }
    else
    {
        printf("\nQueue contains \n");
        for (i=q->front; i<q->rear+1; i++)
        {
            printf("%d ", q->items[i]);
        }
        printf("\n");
    }
}

// Creating a node
Node *createNode(int v)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Creating a graph
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
    // Add edge from src to dest
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// BFS algo
void bfs(Graph *graph, int startVertex, Queue *q)
{
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q))
    {
        printQueue(q);
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        Node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->visited[adjVertex] == 0)
            {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}