
#include <stdio.h>
#include <stdlib.h>


struct node{
    // data
    int data;
    // metadata
    struct node * next;
    struct node * prev;
};

// doubly list
int main(void)
{
    struct node *HEAD = (struct node *)malloc(sizeof(struct node));

    HEAD->data = 10;
    HEAD->next = NULL;
    HEAD->prev = NULL;

    // insert at end
    struct node *new_data = (struct node *)malloc(sizeof(struct node));
    new_data->data = 20;
    HEAD->next = new_data;
    new_data->prev = HEAD;
    new_data->next = NULL;

    // insert at begining
    new_data = (struct node *)malloc(sizeof(struct node));
    new_data->data = 30;
    new_data->next = HEAD;
    new_data->prev = HEAD->prev;
    HEAD = new_data;

    // insert at begining
    new_data = (struct node *)malloc(sizeof(struct node));
    new_data->data = 55;
    new_data->next = HEAD;
    new_data->prev = HEAD->prev;
    HEAD = new_data;

    // insert after any (10)
    new_data = (struct node *)malloc(sizeof(struct node));
    new_data->data = 44;
    struct node* run = HEAD;

    while (run->data != 10)
    {
       run = run->next; 
    }

    new_data->next = run->next;
    new_data->prev = run;
    run->next = new_data;


    printf("HEAD : %d\n", HEAD->data); //55
    printf("HEAD->next : %d\n", HEAD->next->data); // 30
    printf("HEAD->next->next : %d\n", HEAD->next->next->data); // 10
    printf("HEAD->next->next->next : %d\n", HEAD->next->next->next->data); // 44
    printf("HEAD->next->next->next->next : %d\n", HEAD->next->next->next->next->data); // 20
    return 0;
}