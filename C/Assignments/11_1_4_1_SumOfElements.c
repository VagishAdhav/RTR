#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declaration
    int vva_iArray[NUM_ELEMENTS];
    int vva_i, vva_num, vva_sum = 0;

    //code
    printf("\n\n");
    printf("Enter integer elements for array : \n\n");

    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
    {
        scanf("%d", &vva_num);
        vva_iArray[vva_i] = vva_num;
    }

    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
    {
        vva_sum = vva_sum + vva_iArray[vva_i];
    }

    printf("\n\n");
    printf("Sum of all elements of array = %d\n\n", vva_sum);

    return (0);
}