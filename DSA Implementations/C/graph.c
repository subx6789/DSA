#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} graph;

graph *createGraph(int vertices)
{
    graph *graph = malloc(sizeof(graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            graph->adjMatrix[i][j] = 0;
        }
    }

    return graph;
}

void addEdge(graph *graph, int src, int dest)
{
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void printGraph(graph *graph)
{
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void printEdges(graph *graph)
{
    printf("\nGraph Representation (Edges):\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("Vertex %d is connected to: ", i);
        int hasEdges = 0;
        for (int j = 0; j < graph->numVertices; j++)
        {
            if (graph->adjMatrix[i][j] == 1)
            {
                printf("%d ", j);
                hasEdges = 1;
            }
        }
        if (!hasEdges)
        {
            printf("None");
        }
        printf("\n");
    }
}

int main()
{
    int vertices = 5;
    graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    printEdges(graph);

    return 0;
}
