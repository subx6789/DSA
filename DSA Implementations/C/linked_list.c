#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int value;
    struct Node *next;
};

typedef struct Node node_t;

void printlist(node_t *head)
{
    node_t *temp = head;

    while (temp != NULL)
    {
        printf("%d - ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

node_t *create_new_node(int value)
{
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;
}

node_t *insert_at_head(node_t **head, node_t *node_to_insert)
{
    node_to_insert->next = *head;
    *head = node_to_insert;
    return node_to_insert;
}

void insert_after_node(node_t *node_to_insert_after, node_t *newnode)
{
    newnode->next = node_to_insert_after->next;
    node_to_insert_after->next = newnode;
}

void remove_node(node_t **head, node_t *node_to_remove)
{
    if (*head == node_to_remove)
    {
        *head = node_to_remove->next;
        return;
    }
    else
    {
        node_t *temp = *head;
        while (temp != NULL && temp->next != node_to_remove)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            return;
        }
        temp->next = node_to_remove->next;
        node_to_remove->next = NULL;
    }
    return;
}

node_t *find_node(node_t *head, int value)
{
    node_t *tmp = head;
    while (tmp != NULL)
    {
        int tmp_value = tmp->value;
        if (tmp_value == value)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main()
{
    node_t *head = NULL;
    node_t *tmp;

    for (int i = 1; i <= 25; i++)
    {
        tmp = create_new_node(i);
        head = insert_at_head(&head, tmp);
    }

    printf("List after inserting 25 nodes:\n");
    printlist(head);

    tmp = find_node(head, 13);
    printf("Found node with value: %d\n", tmp->value);

    printf("List after inserting node with value 75 after node with value 13:\n", tmp->value);
    insert_after_node(tmp, create_new_node(75));
    printlist(head);

    printf("List after removing node with value 75:\n");
    remove_node(&head, tmp->next);
    printlist(head);

    return 0;
}