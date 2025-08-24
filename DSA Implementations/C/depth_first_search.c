#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// adjacency list structure
typedef struct Node
{
    int vertex;        // vertex value
    int weight;        // weight of the edge
    struct Node *next; // pointer to the next node (stores next node address)
} Node;

// graph structure
typedef struct Graph
{
    int numVertices;              // number of vertices
    int weighted;                 // flag to check if the graph is weighted
    Node *adjLists[MAX_VERTICES]; // adjacency list of each vertex
} Graph;

// stack structure
typedef struct Stack
{
    int items[MAX_VERTICES]; // array to hold stack elements
    int top;                 // top pointer
} Stack;

// function to create a graph with given vertices and it returns a graph structure
Graph *createGraph(int vertices, int weighted)
{
    Graph *graph = malloc(sizeof(Graph)); // dynamically allocate memory for the graph
    graph->numVertices = vertices;        // set the number of vertices in the graph given by the user
    graph->weighted = weighted;           // set weighted flag

    for (int i = 0; i < vertices; i++) // initialize adjacency lists to NULL
    {
        graph->adjLists[i] = NULL; // set each adjacency list head to NULL
    }
    return graph;
}

// function to add a single directed edge from src -> dest
void addSingleEdge(Graph *graph, int src, int dest, int weight)
{
    Node *newNode = malloc(sizeof(Node));           // dynamically allocate the size of a new node
    newNode->vertex = dest;                         // store destination vertex
    newNode->weight = graph->weighted ? weight : 1; // if weighted use given weight else use 1
    newNode->next = graph->adjLists[src];           // link it to existing list
    graph->adjLists[src] = newNode;                 // update adjacency list head
}

// function to add an edge which handles directed/undirected
void addEdge(Graph *graph, int src, int dest, int directed, int weight)
{
    addSingleEdge(graph, src, dest, weight); // always add src -> dest
    if (!directed)                           // if undirected
    {
        addSingleEdge(graph, dest, src, weight); // add dest -> src
    }
}

// function to print the adjacency list
void printGraph(Graph *graph)
{
    printf("Adjacency List Representation: \n");
    for (int v = 0; v < graph->numVertices; v++) // run a for loop for all vertices
    {
        Node *temp = graph->adjLists[v]; // get the head of the adjacency list
        printf("%d : ", v);
        while (temp) // traverse the adjacency list
        {
            if (graph->weighted) // if the graph is weighted
            {
                printf("%d(%d) ", temp->vertex, temp->weight);
            }
            else
            {
                printf("%d ", temp->vertex);
            }
            temp = temp->next; // move to the next node in the adjacency list
        }
        printf("\n");
    }
    printf("\n");
}

// function to create a stack
Stack *createStack()
{
    Stack *s = malloc(sizeof(Stack)); // dynamically allocate memory for the stack
    s->top = -1;                      // initialize top to -1
    return s;
}

// function to check if the stack is empty
int isEmpty(Stack *s)
{
    return s->top == -1; // return 1 if the stack is empty else return 0
}

// function to add an element to the stack
void push(Stack *s, int value)
{
    if (s->top == MAX_VERTICES - 1) // check if the stack is full
    {
        printf("Stack is full!\n");
        return;
    }
    s->items[++s->top] = value; // increment top and add the new element
}

// function to remove an element from the stack and return it
int pop(Stack *s)
{
    if (isEmpty(s)) // check if the stack is empty
    {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[s->top--]; // return the top element and decrement top
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
        Node *current = graph->adjLists[v]; // get the head of the adjacency list
        while (current)                     // traverse the adjacency list
        {
            Node *next = current->next; // store the next node
            free(current);              // free the current node
            current = next;             // move to the current node
        }
    }
    free(graph); // free the graph structure
}

// function to free the allocated memory for the stack to avoid memory leaks
void freeStack(Stack *s)
{
    free(s);
}

// function to do the DFS Traversal
void DFS(Graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0}; // keep track of visited nodes 0 is not visited and 1 is visited
    Stack *frontier = createStack(); // create a stack to hold the nodes to be explored

    push(frontier, startVertex); // push the starting node onto the stack

    printf("DFS Traversal starting from the vertex %d:\n", startVertex);

    while (!isEmpty(frontier)) // while there are nodes to explore
    {
        int current = pop(frontier); // pop a node from the stack

        if (!visited[current]) // if not visited
        {
            visited[current] = 1; // mark as visited
            printf("%d ", current);

            Node *temp = graph->adjLists[current]; // get the head of the adjacency list of the current node
            while (temp != NULL)                   // traverse the adjacency list
            {
                int u = temp->vertex; // get the adjacency vertex
                if (!visited[u])      // if not visited
                {
                    push(frontier, u); // push the adjacent vertex onto the stack
                }
                temp = temp->next; // move to the next node in the adjacency list
            }
        }
    }
    printf("\n");
    freeStack(frontier); // free the allocated memory for the stack
}

int main()
{
    int vertices, edges, directed, weighted; // initialize the variables for number of vertices, edges, directed/undirected graph and weighted/unweighted graph
    printf("Enter the number of vertices (Maximum 100): ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Is the graph directed? (0 = No, 1 = Yes): ");
    scanf("%d", &directed);

    printf("Is the graph weighted? (0 = No, 1 = Yes): ");
    scanf("%d", &weighted);

    Graph *graph = createGraph(vertices, weighted); // create a graph with the given number of vertices and weighted flag

    printf("Enter the edges one by one:- \n");

    if (weighted)
    {
        printf("Format: <source> <destination> <weight>\n");
    }
    else
    {
        printf("Format: <source> <destination>\n");
    }

    for (int i = 0; i < edges; i++) // run a for loop for the number of edges
    {
        int s, d, w = 1; // initialize the variables for source and destination and weight
        if (weighted)
        {
            printf("Edge %d: ", i + 1);
            scanf("%d %d %d", &s, &d, &w);
        }
        else
        {
            printf("Edge %d: ", i + 1);
            scanf("%d %d", &s, &d);
        }

        addEdge(graph, s, d, directed, w); // add the edge to the graph
    }

    int startVertex; // initialize the variable for starting vertex
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    printGraph(graph); // print the adjacency list

    DFS(graph, startVertex); // perform DFS traversal

    freeGraph(graph); // free the allocated memory for the graph

    return 0;
}
