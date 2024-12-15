#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declaration
    int vva_iArray[NUM_ELEMENTS];
    int vva_i, vva_num;

    //code 
    printf("\n\n");

    //** Array elements input ****
    printf("Enter integer elements for array : \n\n");

    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
    {
        scanf("%d", &vva_num);
        vva_iArray[vva_i] = vva_num;
    }

    // separating out even numbers from array elements
    printf("\n\n");
    printf("Even numbers among the array elements are : \n\n");
    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
    {
        if ((vva_iArray[vva_i] % 2) == 0)
            printf("%d\n", vva_iArray[vva_i]);
    }

    // separating out odd numbers from array elements
    printf("\n\n");
    printf("Odd numbers among the array elements are : \n\n");
    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
    {
        if ((vva_iArray[vva_i] % 2) != 0)
            printf("%d\n", vva_iArray[vva_i]);
    }

    return (0);
}