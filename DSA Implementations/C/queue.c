#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;

} node_t;

typedef struct
{
    node_t *head;
    node_t *tail;
} queue;

void init_queue(queue *myqueue)
{
    myqueue->head = NULL;
    myqueue->tail = NULL;
}

bool enqueue(queue *myqueue, int value)
{
    node_t *newnode = malloc(sizeof(node_t));
    if (newnode == NULL)
    {
        return false;
    }
    newnode->value = value;
    newnode->next = NULL;
    if (myqueue->tail != NULL)
    {
        myqueue->tail->next = newnode;
    }
    myqueue->tail = newnode;
    if (myqueue->head == NULL)
    {
        myqueue->head = newnode;
    }
    return true;
}

int dequeue(queue *myqueue)
{
    if (myqueue->head == NULL)
    {
        return -1;
    }
    node_t *tmp = myqueue->head;
    int result = tmp->value;
    myqueue->head = myqueue->head->next;
    if (myqueue->head == NULL)
    {
        myqueue->tail = NULL;
    }
    free(tmp);
    return result;
}

int main()
{
    queue s1;

    init_queue(&s1);

    for (int i = 1; i <= 5; i++)
    {
        enqueue(&s1, i);
    }
    int t;
    while ((t = dequeue(&s1)) != -1)
    {
        printf("%d\n", t);
    }
    return 0;
}