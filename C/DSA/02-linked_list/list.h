#pragma once

typedef enum 
{
    SUCCESS,
    NO_MEMORY,
    NODE_NOT_FOUND,
    INVALID_LIST
}result;

typedef struct vertex
{
    float x;
    float y;
    float z;
}vertex_t;

typedef struct node {
    vertex_t vertex;
    struct node *next;
    struct node *prev;
}node_t;

typedef node_t list_t;

//operations on my data structure

result create_list(list_t **);

result insert_beg(list_t *, vertex_t);
result insert_end(list_t *, vertex_t);
result insert_befor(list_t *, vertex_t);
result insert_after(list_t *, vertex_t);

result destroy_list(list_t **);
result delete_beg(list_t *);
result delete_end(list_t *);
result delete_node(list_t *, vertex_t);
result display_list(list_t *);

result search_node(list_t *, vertex_t);
result is_empty(list_t *);

result swap_nodes(list_t *, vertex_t , vertex_t );

