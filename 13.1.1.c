// Nearest Neighbor Algorithm for TSP

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int first;
    unsigned int second;
    unsigned int weight;
} weighted_edge;

static unsigned int tour_contains(const weighted_edge *tour, unsigned int t, const weighted_edge *edge);
static unsigned int nearest_neighbor_edge(const weighted_edge *edges, unsigned int size, const weighted_edge *tour, unsigned int t, unsigned int v);
weighted_edge *nearest_neighbor_tsp(const weighted_edge *edges, unsigned int size, unsigned int order);
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

    tour = nearest_neighbor_tsp(edges, size, order);
    print_edges(tour, order);

    free(tour);
    free(edges);
    return 0;
}

// Check if the tour already contains an edge
static unsigned int tour_contains(const weighted_edge *tour, unsigned int t, const weighted_edge *edge)
{
    unsigned int contains = 0;
    unsigned int i = 0;
    
    for (i=0; i<t && !contains; i++)
    {
        contains = tour[i].first == edge->first && tour[i].second == edge->second;
    }
    return contains;
}

// Find an edge to v's nearest neighbor not in the tour already
static unsigned int nearest_neighbor_edge(const weighted_edge *edges, unsigned int size, const weighted_edge *tour, unsigned int t, unsigned int v)
{
    unsigned int min_distance = 0;
    unsigned int nearest_neighbor = 0;
    unsigned int i = 0;

    for (i=0; i<size; i++)
    {
        if ((edges[i].first == v || edges[i].second == v) && (min_distance == 0 || edges[i].weight < min_distance) && !tour_contains(tour, t, &edges[i]))
        {
            min_distance = edges[i].weight;
            nearest_neighbor = i;
        }
    }
    return nearest_neighbor;
}

weighted_edge *nearest_neighbor_tsp(const weighted_edge *edges, unsigned int size, unsigned int order)
{
    unsigned int t = 0, v = 0;
    weighted_edge *tour = malloc(order * sizeof(weighted_edge));
    if (tour == NULL) return NULL;
    for (t=0; t<order; t++)
    {
        unsigned int e = nearest_neighbor_edge(edges, size, tour, t, v);
        tour[t] = edges[e];
        v = edges[e].first == v ? edges[e].second : edges[e].first;
    }
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