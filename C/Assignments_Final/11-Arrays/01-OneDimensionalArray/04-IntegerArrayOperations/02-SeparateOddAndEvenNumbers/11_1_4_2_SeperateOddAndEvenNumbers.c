#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declaration
    int iArray_vva[NUM_ELEMENTS];
    int i_vva, num_vva;

    //code 
    printf("\n\n");

    //** Array elements input ****
    printf("Enter integer elements for array : \n\n");

    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
    {
        scanf("%d", &num_vva);
        iArray_vva[i_vva] = num_vva;
    }

    // separating out even numbers from array elements
    printf("\n\n");
    printf("Even numbers among the array elements are : \n\n");
    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
    {
        if ((iArray_vva[i_vva] % 2) == 0)
            printf("%d\n", iArray_vva[i_vva]);
    }

    // separating out odd numbers from array elements
    printf("\n\n");
    printf("Odd numbers among the array elements are : \n\n");
    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
    {
        if ((iArray_vva[i_vva] % 2) != 0)
            printf("%d\n", iArray_vva[i_vva]);
    }

    return (0);
}