#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

// adjacency list node structure
typedef struct Node
{
    int vertex;        // vertex number
    int weight;        // edge weight
    struct Node *next; // pointer to next node
} Node;

// graph structure
typedef struct Graph
{
    int numVertices;              // number of vertices
    Node *adjLists[MAX_VERTICES]; // adjacency list
    int isDirected;               // flag for directed and undirected 0 = undirected, 1 = directed
} Graph;

// global arrays for Dijkstra
int dist[MAX_VERTICES];    // distance from source to each vertex
int parent[MAX_VERTICES];  // parent of each vertex in the path
int visited[MAX_VERTICES]; // visited flag for each vertex

// function to create a graph
Graph *createGraph(int vertices, int isDirected)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph)); // dynamically allocate memory for graph
    graph->numVertices = vertices;                 // set the number of vertices
    graph->isDirected = isDirected;                // set graph type
    for (int i = 0; i < vertices; i++)
    { // initialize adjacency list to NULL
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// function to create a node
Node *createNode(int v, int w)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // dynamically allocate memory for new node
    newNode->vertex = v;                          // set vertex number
    newNode->weight = w;                          // set edge weight
    newNode->next = NULL;                         // initialize next pointer to NULL
    return newNode;
}

// function to add edge (directed or undirected depending on graph type)
void addEdge(Graph *graph, int src, int dest, int weight)
{
    // add edge from src to dest
    Node *newNode = createNode(dest, weight); // create new node
    newNode->next = graph->adjLists[src];     // point new node to current head
    graph->adjLists[src] = newNode;           // update head to new node

    // if graph is undirected, also add reverse edge
    if (!graph->isDirected)
    {
        newNode = createNode(src, weight);     // create new node for reverse edge
        newNode->next = graph->adjLists[dest]; // point new node to current head
        graph->adjLists[dest] = newNode;       // update head to new node
    }
}

// function to print adjacency list representation
void printGraph(Graph *graph)
{
    printf("\nAdjacency List Representation:\n");
    for (int v = 0; v < graph->numVertices; v++)
    { // iterate through all vertices
        printf("%d: ", v);
        Node *temp = graph->adjLists[v]; // get the adjacency list of vertex v
        while (temp)
        { // iterate through the adjacency list
            printf(" %d(%d) ", temp->vertex, temp->weight);
            temp = temp->next; // move to the next node
        }
        printf("\n");
    }
}

// function to find the vertex with minimum distance
int minDistance(int n)
{
    int min = INT_MAX, min_index = -1; // initialize min and min_index
    for (int v = 0; v < n; v++)
    { // iterate through all vertices
        if (!visited[v] && dist[v] <= min)
        {                  // if the vertex is not visited and has smaller distance
            min = dist[v]; // update min
            min_index = v; // update min_index
        }
    }
    return min_index;
}

// function to print the path recursively
void printPath(int goal)
{
    if (parent[goal] == -1)
    {                        // check if it is the start node
        printf("%d ", goal); // print the start node
        return;
    }
    printPath(parent[goal]); // recursively print the parent node
    printf("-> %d ", goal);
}

// function of dijkstra’s algorithm (Uniform Cost Search)
void dijkstra(Graph *graph, int start, int goal)
{
    int n = graph->numVertices; // number of vertices

    for (int i = 0; i < n; i++)
    {                      // initialize all distances to infinity and visited to false
        dist[i] = INT_MAX; // set initial distance to infinity
        visited[i] = 0;    // mark all vertices as unvisited
        parent[i] = -1;    // initialize parent array
    }

    dist[start] = 0; // distance from source to itself is 0

    for (int count = 0; count < n - 1; count++)
    {                           // iterate through all vertices
        int u = minDistance(n); // get vertex with minimum distance
        if (u == -1)
            break;      // no reachable nodes left
        visited[u] = 1; // mark the picked vertex as visited

        Node *temp = graph->adjLists[u]; // get the adjacency list of the picked vertex
        while (temp != NULL)
        {                              // iterate through all adjacent vertices
            int v = temp->vertex;      // get the vertex number
            int weight = temp->weight; // get the edge weight
            if (!visited[v] && dist[u] + weight < dist[v])
            {                               // if the vertex is not visited and the new distance is smaller than the current distance
                dist[v] = dist[u] + weight; // update distance
                parent[v] = u;              // update parent
            }
            temp = temp->next; // move to the next adjacent vertex
        }
    }

    if (dist[goal] == INT_MAX)
    {                                                          // if the goal is unreachable
        printf("No path exists from %d to %d\n", start, goal); // print no path message
    }
    else
    {
        printf("\nShortest Path from %d to %d: ", start, goal); // print shortest path message
        printPath(goal);                                        // print the path
        printf("\nTotal Path Cost: %d\n", dist[goal]);          // print total path cost
    }
}

// main function
int main()
{
    int vertices, edges, graphType; // number of vertices, edges and graph type
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

    printGraph(graph);

    int start, goal;
    printf("\nEnter starting node: ");
    scanf("%d", &start);
    printf("Enter goal node: ");
    scanf("%d", &goal);

    dijkstra(graph, start, goal);

    return 0;
}