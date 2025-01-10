#include <stdio.h>

#define num_vva_ELEMENTS 10

int main(void)
{
    // variable declaration
    int i_vvaArray[num_vva_ELEMENTS];
    int i_vva, vva_num_vva;

    //code 
    printf("\n\n");

    //** Array elements input ****
    printf("Enter integer elements for array : \n\n");

    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
    {
        scanf("%d", &vva_num_vva);
        i_vvaArray[i_vva] = vva_num_vva;
    }

    // separating out even num_vvabers from array elements
    printf("\n\n");
    printf("Even num_vvabers among the array elements are : \n\n");
    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
    {
        if ((i_vvaArray[i_vva] % 2) == 0)
            printf("%d\n", i_vvaArray[i_vva]);
    }

    // separating out odd num_vvabers from array elements
    printf("\n\n");
    printf("Odd num_vvabers among the array elements are : \n\n");
    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
    {
        if ((i_vvaArray[i_vva] % 2) != 0)
            printf("%d\n", i_vvaArray[i_vva]);
    }

    return (0);
}