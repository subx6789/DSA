#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Graph
{
    int numVertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} graph;

typedef struct Queue
{
    int items[MAX_VERTICES];
    int front;
    int rear;
} queue;

queue *createQueue()
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(queue *q)
{
    return (q->rear == -1);
}

void enqueue(queue *q, int value)
{
    if (q->rear == MAX_VERTICES - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(queue *q)
{
    int item;
    if (isEmpty(q))
    {
        return -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
        return item;
    }
}

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

void bfs(graph *graph, int startVertex)
{
    int visited[MAX_VERTICES] = {0};
    queue *q = createQueue();

    visited[startVertex] = 1;
    enqueue(q, startVertex);

    printf("BFS Traversal starting from vertex %d: ", startVertex);

    while (!isEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->numVertices; i++)
        {
            if (graph->adjMatrix[currentVertex][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
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

    bfs(graph, 0);

    return 0;
}
