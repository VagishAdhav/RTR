#include <stdio.h>
#include "list.h"


int main (void)
{
    list_t *my_list =  NULL;
    vertex_t my_data = {0.1f, 1.0f, 2.0f};

    if (create_list(&my_list) == SUCCESS)
    {
        int result;
        printf("List created \n");
        result = insert_beg(my_list, my_data);
        printf("Element added , result : %d\n", result);
        my_data.x = my_data.x + 1.0f;
        result = insert_beg(my_list, my_data);
        printf("Element added , result : %d\n", result);

        display_list(my_list);
    }
    return 0;
}