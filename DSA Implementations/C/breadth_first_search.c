#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// adjacency list structure
typedef struct Node
{
    int vertex;        // vertex value
    struct Node *next; // pointer to the next node (stores next node address)
} Node;

// graph structure
typedef struct Graph
{
    int numVertices;              // number of vertices
    Node *adjLists[MAX_VERTICES]; // adjacency list of each vertex
} Graph;

// queue structure
typedef struct Queue
{
    int items[MAX_VERTICES]; // array to hold queue elements
    int front, rear;         // front and rear pointers
} Queue;

// function to create a graph with given vertices and it returns a graph structure
Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph)); // dynamically allocate memory for the graph
    graph->numVertices = vertices;        // set the number of vertices in the graph given by the user

    for (int i = 0; i < vertices; i++) // initialize adjacency lists to NULL
    {
        graph->adjLists[i] = NULL; // set each adjacency list head to NULL
    }

    return graph;
}

// helper function to add a single directed edge from src -> dest
void addSingleEdge(Graph *graph, int src, int dest)
{
    Node *newNode = (Node *)malloc(sizeof(Node)); // dynamically allocate the size of a new node
    newNode->vertex = dest;                       // store destination vertex
    newNode->next = graph->adjLists[src];         // link it to existing list
    graph->adjLists[src] = newNode;               // update adjacency list head
}

// function to add an edge which handles directed/undirected
void addEdge(Graph *graph, int src, int dest, int directed)
{
    addSingleEdge(graph, src, dest); // always add src -> dest
    if (!directed)                   // if undirected, also add dest -> src
    {
        addSingleEdge(graph, dest, src); // add dest -> src
    }
}

// function to print the adjacency list
void printGraph(Graph *graph)
{
    printf("\nAdjacency List Representation:\n");
    for (int v = 0; v < graph->numVertices; v++) // run a for loop for all vertices
    {
        Node *temp = graph->adjLists[v]; // get the head of the adjacency list
        printf("%d -> ", v);             // print the vertex
        while (temp)                     // traverse the adjacency list
        {
            printf("%d ", temp->vertex); // print the vertex
            temp = temp->next;           // move to the next node
        }
        printf("\n");
    }
    printf("\n");
}

// create an empty queue
Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue)); // dynamically allocate memory for the queue
    q->front = -1;                    // initialize the front pointer
    q->rear = -1;                     // initialize the rear pointer
    return q;
}

// function to check if the queue is empty
int isEmpty(Queue *q)
{
    return q->front == -1; // if front is -1 then the queue is empty
}

// function to enqueue (insert an element in the queue)
void enqueue(Queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1) // check if the queue is full
    {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) // if the queue is empty
        q->front = 0;   // set front to 0

    q->rear++;                 // increment rear
    q->items[q->rear] = value; // add the new element in the rear
}

// function to dequeue (remove an element from the queue)
int dequeue(Queue *q)
{
    if (isEmpty(q)) // check if the queue is empty
    {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front]; // get the front element
    q->front++;                    // increment front

    // reset queue when empty
    if (q->front > q->rear) // if front exceeds rear, the queue is empty
    {
        q->front = q->rear = -1; // reset front and rear
    }

    return item;
}

// function to free the allocated memory for the graph to avoid memory leaks
void freeGraph(Graph *graph)
{
    if (!graph) // if the graph is NULL
    {
        return;
    }

    for (int v = 0; v < graph->numVertices; v++) // free each adjacency list
    {
        Node *cur = graph->adjLists[v]; // get the head of the adjacency list
        while (cur)                     // traverse the adjacency list
        {
            Node *nxt = cur->next; // store the next node
            free(cur);             // free the current node
            cur = nxt;             // move to the current node
        }
    }
    free(graph); // free the graph structure
}

// function to free the allocated memory for the queue to avoid memory leaks
void freeQueue(Queue *q)
{
    free(q); // free the queue structure
}

// function to do the BFS Traversal
void BFS(Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0}; // keep track of visited nodes (0 = not visited, 1 = visited)
    Queue *frontier = createQueue(); // create a queue named frontier to hold the nodes to be explored

    visited[startVertex] = 1;       // mark the starting node as visited
    enqueue(frontier, startVertex); // enqueue the starting node

    printf("BFS Traversal starting from vertex %d:\n", startVertex);

    while (!isEmpty(frontier)) // while there are nodes to explore
    {
        int currentVertex = dequeue(frontier); // dequeue a node from the frontier
        printf("%d ", currentVertex);

        // visit all adjacent vertices
        Node *temp = graph->adjLists[currentVertex]; // get the head of the adjacency list
        while (temp)                                 // traverse the adjacency list
        {
            int adjVertex = temp->vertex; // get the adjacency vertex
            if (visited[adjVertex] == 0)  // if not visited
            {
                visited[adjVertex] = 1;       // mark as visited
                enqueue(frontier, adjVertex); // enqueue the adjacent vertex
            }
            temp = temp->next; // move to the next node in the adjacency list
        }
    }
    printf("\n");

    freeQueue(frontier); // free the allocated memory for the queue
}

// main function
int main()
{
    int vertices, edges, directed; // initialize the variables for number of vertices, edges and directed/undirected graph
    printf("Enter the number of vertices (Maximum 100): ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (0 = No, 1 = Yes): ");
    scanf("%d", &directed);

    Graph *graph = createGraph(vertices); // create a graph with the given number of vertices

    printf("Enter the edges (source destination) one by one:\n");
    for (int i = 0; i < edges; i++) // run a for loop for the number of edges
    {
        int s, d; // initialize the variables for source and destination
        scanf("%d %d", &s, &d);
        addEdge(graph, s, d, directed); // add the edge to the graph
    }

    int startVertex; // initialize the variable for starting vertex
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printGraph(graph); // print the adjacency list

    BFS(graph, startVertex); // perform BFS traversal

    freeGraph(graph); // free the allocated memory for the graph

    return 0;
}