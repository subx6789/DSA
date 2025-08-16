#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

typedef struct Node
{
    int value;
    struct Node *next;

} node_t;

typedef node_t *stack;

bool push(stack *mystack, int value)
{
    node_t *newnode = malloc(sizeof(node_t));
    if (newnode == NULL)
    {
        return false;
    }
    newnode->value = value;
    newnode->next = *mystack;
    *mystack = newnode;
    return true;
}

int pop(stack *mystack)
{
    if (*mystack == NULL)
    {
        return -1;
    }
    int result = (*mystack)->value;
    node_t *tmp = *mystack;
    *mystack = (*mystack)->next;
    free(tmp);
    return result;
}

int main()
{
    stack s1 = NULL;
    for (int i = 1; i <= 5; i++)
    {
        push(&s1, i);
    }
    int t;
    while ((t = pop(&s1)) != -1)
    {
        printf("%d\n", t);
    }
    return 0;
}