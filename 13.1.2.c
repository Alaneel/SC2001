// Cheapest-Link Algorithm for TSP

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int first;
    unsigned int second;
    unsigned int weight;
} weighted_edge;

static int compare_weighted_edges(const weighted_edge *edge1, const weighted_edge *edge2);
static unsigned int cyclic_recursive(const weighted_edge *edges, unsigned int n, unsigned int *visited, unsigned int order, unsigned int vertex, unsigned int predecessor);
unsigned int cyclic(const weighted_edge *edges, unsigned int n, unsigned int order);
weighted_edge *cheapest_link_tsp(weighted_edge *edges, unsigned int size, unsigned int order);
void weighted_edge_connect(weighted_edge *edges, unsigned int first, unsigned int second, unsigned int weight, unsigned int *pos);
void print_edges(const weighted_edge *edges, unsigned int n);

int main()
{
    unsigned int i = 0;
    const unsigned int size = 15; // Edges
    const unsigned int order = 6; // Vertices
    weighted_edge *edges = malloc(size * sizeof(weighted_edge));
    weighted_edge *tour;

    weighted_edge_connect(edges, 0, 1, 25, &i);
    weighted_edge_connect(edges, 0, 2, 19, &i);
    weighted_edge_connect(edges, 0, 3, 19, &i);
    weighted_edge_connect(edges, 0, 4, 16, &i);
    weighted_edge_connect(edges, 0, 5, 28, &i);
    weighted_edge_connect(edges, 1, 2, 24, &i);
    weighted_edge_connect(edges, 1, 3, 30, &i);
    weighted_edge_connect(edges, 1, 4, 27, &i);
    weighted_edge_connect(edges, 1, 5, 17, &i);
    weighted_edge_connect(edges, 2, 3, 18, &i);
    weighted_edge_connect(edges, 2, 4, 20, &i);
    weighted_edge_connect(edges, 2, 5, 23, &i);
    weighted_edge_connect(edges, 3, 4, 19, &i);
    weighted_edge_connect(edges, 3, 5, 32, &i);
    weighted_edge_connect(edges, 4, 5, 41, &i);

    tour = cheapest_link_tsp(edges, size, order);
    print_edges(tour, order);

    free(tour);
    free(edges);
    return 0;
}

static int compare_weighted_edges(const weighted_edge *edge1, const weighted_edge *edge2)
{
    return edge1->weight - edge2->weight;
}

static unsigned int cyclic_recursive(const weighted_edge *edges, unsigned int n, unsigned int *visited, unsigned int order, unsigned int vertex, unsigned int predecessor)
{
    unsigned int i = 0;
    unsigned int cycle_found = 0;
    visited[vertex] = 1;

    for (i=0; i<n && !cycle_found; i++)
    {
        if (edges[i].first == vertex || edges[i].second == vertex)
        {
            // Adjacent
            const unsigned int neighbor = edges[i].first == vertex ? edges[i].second : edges[i].first;
            if (visited[neighbor] == 0)
            {
                // Not yet visited
                cycle_found = cyclic_recursive(edges, n, visited, order, neighbor, vertex);
            }
            else if (neighbor != predecessor)
            {
                // Found a cycle
                cycle_found = 1;
            }
        }
    }
    return cycle_found;
}

unsigned int cyclic(const weighted_edge *edges, unsigned int n, unsigned int order)
{
    unsigned int *visited = calloc(order, sizeof(unsigned int));
    unsigned int cycle_found = 0;

    if (visited == NULL) return 0;
    cycle_found = cyclic_recursive(edges, n, visited, order, 0, 0);
    free(visited);
    return cycle_found;
}

weighted_edge *cheapest_link_tsp(weighted_edge *edges, unsigned int size, unsigned int order)
{
    unsigned int t = 0, e = 0;
    weighted_edge *tour = malloc(order * sizeof(weighted_edge));
    unsigned int *degrees = calloc(order, sizeof(unsigned int));
    if (tour == NULL || degrees == NULL)
    {
        free(tour);
        free(degrees);
        return NULL;
    }
    // Sort the edges by weight
    qsort(edges, size, sizeof(weighted_edge), (int(*)(const void *, const void *))compare_weighted_edges);
    // Main algorithm
    for (t=0; t<order; t++)
    {
        unsigned int added = 0;
        while (!added && e < size)
        {
            if (degrees[edges[e].first] < 2 && degrees[edges[e].second] < 2)
            {
                tour[t] = edges[e];
                if (t == order - 1 || !cyclic(tour, t+1, order)) // It's the last edge or it does not close the circuit
                {
                    added = 1;
                    degrees[edges[e].first]++;
                    degrees[edges[e].second]++;
                }
            }
            e++;
        }
        if (!added)
        {
            // Edges were not correct
            free(tour);
            free(degrees);
            return NULL;
        }
    }
    free(degrees);
    return tour;
}

// Connect two edges
void weighted_edge_connect(weighted_edge *edges, unsigned int first, unsigned int second, unsigned int weight, unsigned int *pos)
{
    edges[*pos].first = first;
    edges[*pos].second = second;
    edges[*pos].weight = weight;
    (*pos)++;
}

void print_edges(const weighted_edge *edges, unsigned int n)
{
    unsigned int e = 0;

    for (e=0; e<n; e++)
    {
        printf("(%u %u %u) ", edges[e].first, edges[e].second, edges[e].weight);
    }
    putchar('\n');
}