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

void dfsRecursive(graph *graph, int vertex, int visited[])
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < graph->numVertices; i++)
    {
        if (graph->adjMatrix[vertex][i] == 1 && !visited[i])
        {
            dfsRecursive(graph, i, visited);
        }
    }
}

void dfs(graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    printf("DFS Traversal starting from vertex %d: ", startVertex);
    dfsRecursive(graph, startVertex, visited);
    printf("\n");
}

int main()
{
    int vertices = 6;
    graph *graph = createGraph(vertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    dfs(graph, 0);

    return 0;
}
