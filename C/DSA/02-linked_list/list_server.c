#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

static result alloc_node(node_t **node, vertex_t vertex)
{
    *node = (node_t *)malloc(sizeof(node_t));
    if (*node == NULL)
    {
        return NO_MEMORY;
    }
    (*node)->vertex = vertex;
    return SUCCESS;
}

result create_list(list_t **list)
{
    vertex_t dummy = {0, 0, 0};
    if (alloc_node(list, dummy) == SUCCESS)
    {
        (*list)->next = *list;
        (*list)->prev = *list;
        return SUCCESS;
    }

    return NO_MEMORY;
}

result insert_beg(list_t *list, vertex_t vertex)
{
    node_t *temp_node = NULL;
    if (alloc_node(&temp_node, vertex) == SUCCESS)
    {
        temp_node->next = list->next;
        temp_node->prev = list->next->prev;
        list->next = temp_node;
        return SUCCESS;
    }

    return NO_MEMORY;

}

result insert_end(list_t *list, vertex_t vertex)
{
    node_t *temp_node = NULL;
    if (alloc_node(&temp_node, vertex) == SUCCESS)
    {
        temp_node->next = list;
        temp_node->prev = list->prev;
        list->prev = temp_node;
        return SUCCESS;
    }
    return NO_MEMORY;
}


// result insert_befor(list_t *, vertex_t);
// result insert_after(list_t *, vertex_t);

// result destroy_list(list_t **);
// result delete_beg(list_t *);
// result delete_end(list_t *);
// result delete_node(list_t *, vertex_t);
result display_list(list_t *list)
{
    list_t *run = list;
    int entry_number = 0;
    if (list == NULL)
    {
        return INVALID_LIST;
    }
    while (run->next != list)
    {
        run = run->next;
        entry_number++;
        printf("Entry : %d, X : %f , Y : %f, Z : %f\n", entry_number, run->vertex.x, run->vertex.y, run->vertex.z);
    }
    return SUCCESS;
}
