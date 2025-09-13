// Implementation of A* Search Algorithm using adjacency list
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_VERTICES 100

// adjacency list node structure
typedef struct Node
{
    int vertex;
    int weight;
    struct Node *next;
} Node;

// graph structure
typedef struct Graph
{
    int numVertices;
    Node *adjLists[MAX_VERTICES];
    int isDirected;
} Graph;

// global arrays
int gCost[MAX_VERTICES];     // actual g(n) cost
int parent[MAX_VERTICES];    // parent tracker
int visited[MAX_VERTICES];   // visited set
int heuristic[MAX_VERTICES]; // h(n)

// function to create a graph
Graph *createGraph(int vertices, int isDirected)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->isDirected = isDirected;
    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;
    return graph;
}

// function to create a node
Node *createNode(int v, int w)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// function to add edge
void addEdge(Graph *graph, int src, int dest, int weight)
{
    Node *newNode = createNode(dest, weight);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    if (!graph->isDirected)
    {
        newNode = createNode(src, weight);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// function to print the graph
void printGraph(Graph *graph)
{
    printf("\nAdjacency List Representation:\n");
    for (int v = 0; v < graph->numVertices; v++)
    {
        printf("%d: ", v);
        Node *temp = graph->adjLists[v];
        while (temp)
        {
            printf(" %d(%d) ", temp->vertex, temp->weight);
            temp = temp->next;
        }
        printf("\n");
    }
}

// function to find the vertex with minimum f = g + h
int minDistance(int n)
{
    int min = INT_MAX, min_index = -1;
    for (int v = 0; v < n; v++)
    {
        if (!visited[v] && gCost[v] != INT_MAX)
        {
            int f = gCost[v] + heuristic[v];
            if (f < min)
            {
                min = f;
                min_index = v;
            }
        }
    }
    return min_index;
}

// function to recursively print path
void printPath(int goal)
{
    if (parent[goal] == -1)
    {
        printf("%d ", goal);
        return;
    }
    printPath(parent[goal]);
    printf("-> %d ", goal);
}

// function for A* search
void aStar(Graph *graph, int start, int goal)
{
    int n = graph->numVertices;

    for (int i = 0; i < n; i++)
    {
        gCost[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    gCost[start] = 0;

    while (1)
    {
        int u = minDistance(n);
        if (u == -1)
            break;
        visited[u] = 1;

        if (u == goal)
            break;

        Node *temp = graph->adjLists[u];
        while (temp != NULL)
        {
            int v = temp->vertex;
            int weight = temp->weight;
            if (!visited[v] && gCost[u] + weight < gCost[v])
            {
                gCost[v] = gCost[u] + weight;
                parent[v] = u;
            }
            temp = temp->next;
        }
    }

    if (gCost[goal] == INT_MAX)
    {
        printf("No path exists from %d to %d\n", start, goal);
    }
    else
    {
        printf("\nA* Path from %d to %d: ", start, goal);
        printPath(goal);
        printf("\nTotal Path Cost : %d\n", gCost[goal]);
    }
}

// main function
int main()
{
    int vertices, edges, graphType;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);
    printf("Choose graph type:\n1. Undirected\n2. Directed\nEnter choice: ");
    scanf("%d", &graphType);

    Graph *graph = createGraph(vertices, graphType == 2);

    printf("\nEnter the edges : \n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest, weight;
        printf("\nEdge %d\n", i + 1);
        printf("Enter source: ");
        scanf("%d", &src);
        printf("Enter destination: ");
        scanf("%d", &dest);
        printf("Enter weight: ");
        scanf("%d", &weight);
        addEdge(graph, src, dest, weight);
    }

    printf("\nEnter heuristic values for each vertex:\n");
    for (int i = 0; i < vertices; i++)
    {
        printf("h(%d): ", i);
        scanf("%d", &heuristic[i]);
    }

    printGraph(graph);

    int start, goal;
    printf("\nEnter starting node: ");
    scanf("%d", &start);
    printf("Enter goal node: ");
    scanf("%d", &goal);

    aStar(graph, start, goal);

    return 0;
}
