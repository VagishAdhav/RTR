#include <stdio.h>

#define num_vva_ELEMENTS 10

int main(void)
{
    // variable declaration
    int i_vvaArray[num_vva_ELEMENTS];
    int i_vva, vva_num_vva, vva_sum = 0;

    //code
    printf("\n\n");
    printf("Enter integer elements for array : \n\n");

    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
    {
        scanf("%d", &vva_num_vva);
        i_vvaArray[i_vva] = vva_num_vva;
    }

    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
    {
        vva_sum = vva_sum + i_vvaArray[i_vva];
    }

    printf("\n\n");
    printf("Sum of all elements of array = %d\n\n", vva_sum);

    return (0);
}