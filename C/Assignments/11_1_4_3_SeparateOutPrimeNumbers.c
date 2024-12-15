#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declaration
    int vva_iArray[NUM_ELEMENTS];
    int vva_i, vva_num, vva_j, vva_count = 0;

    // code
    printf("\n\n");

    // *** ARRAY ELEMENTS INPUT ****
    printf("Enter integer elements for array : \n\n");
    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
    {
        scanf("%d", &vva_num);

        // If 'num' is negative ( < 0), then convert it to positive (multiply by -1)
        if (vva_num < 0)
            vva_num = -1*vva_num;
        
        vva_iArray[vva_i] = vva_num;
    }

    // *** PRINTING ENTIRE ARRAY ***
    printf("\n\n");

    printf("Array elements are : \n\n");
    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
        printf("%d\n", vva_iArray[vva_i]);

    // ** separating out even numbers from array elements **
    printf("\n\n");
    printf("Prime numbers amongst the array elements are : \n\n");
    for (vva_i = 0; vva_i < NUM_ELEMENTS; vva_i++)
    {
        for (vva_j = 1; vva_j <= vva_iArray[vva_i]; vva_j++)
        {
            if ((vva_iArray[vva_i] % vva_j) == 0)
                vva_count++;
        }

        // if a number is prime, it is only divisible by 1 and itself.
        // hence if a number is prime, the value of count will be exactly 2
        // if the value of 'count' is greater than 2 , the number is divisible by 1, itself and some other number/s, hence not prime
        // the value of 'count' will be 1 only if 'vva_iArray[]' is 1

        if (vva_count == 2)
        {
                printf("%d\n", vva_iArray[vva_i]);
        }
        vva_count = 0; // reset for checking next number
    }

    return (0);
}