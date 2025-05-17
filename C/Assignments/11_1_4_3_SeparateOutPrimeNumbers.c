#include <stdio.h>

#define num_vva_ELEMENTS 10

int main(void)
{
    // variable declaration
    int i_vvaArray[num_vva_ELEMENTS];
    int i_vva, vva_num_vva, vva_j, c_vvaount = 0;

    // code
    printf("\n\n");

    // *** ARRAY ELEMENTS INPUT ****
    printf("Enter integer elements for array : \n\n");
    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
    {
        scanf("%d", &vva_num_vva);

        // If 'num_vva' is negative ( < 0), then convert it to positive (multiply by -1)
        if (vva_num_vva < 0)
            vva_num_vva = -1*vva_num_vva;
        
        i_vvaArray[i_vva] = vva_num_vva;
    }

    // *** PRINTING ENTIRE ARRAY ***
    printf("\n\n");

    printf("Array elements are : \n\n");
    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
        printf("%d\n", i_vvaArray[i_vva]);

    // ** separating out even num_vvabers from array elements **
    printf("\n\n");
    printf("Prime num_vvabers amongst the array elements are : \n\n");
    for (i_vva = 0; i_vva < num_vva_ELEMENTS; i_vva++)
    {
        for (vva_j = 1; vva_j <= i_vvaArray[i_vva]; vva_j++)
        {
            if ((i_vvaArray[i_vva] % vva_j) == 0)
                c_vvaount++;
        }

        // if a number is prime, it is only divisible by 1 and itself.
        // hence if a number is prime, the value of count will be exactly 2
        // if the value of 'count' is greater than 2 , the number is divisible by 1, itself and some other number/s, hence not prime
        // the value of 'count' will be 1 only if 'i_vvaArray[]' is 1

        if (c_vvaount == 2)
        {
                printf("%d\n", i_vvaArray[i_vva]);
        }
        c_vvaount = 0; // reset for checking next number
    }

    return (0);
}