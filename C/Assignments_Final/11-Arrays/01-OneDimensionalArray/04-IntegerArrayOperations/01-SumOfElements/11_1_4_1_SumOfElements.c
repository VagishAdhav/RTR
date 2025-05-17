#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declaration
    int iArray_vva[NUM_ELEMENTS];
    int i_vva, num_vva, sum_vva = 0;

    //code
    printf("\n\n");
    printf("Enter integer elements for array : \n\n");

    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
    {
        scanf("%d", &num_vva);
        iArray_vva[i_vva] = num_vva;
    }

    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
    {
        sum_vva = sum_vva + iArray_vva[i_vva];
    }

    printf("\n\n");
    printf("Sum of all elements of array = %d\n\n", sum_vva);

    return (0);
}