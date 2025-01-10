#include <stdio.h>

#define NUM_ELEMENTS 10

int main(void)
{
    // variable declaration
    int iArray_vva[NUM_ELEMENTS];
    int i_vva, num_vva, j_vva, count_vva = 0;

    // code
    printf("\n\n");

    // *** ARRAY ELEMENTS INPUT ****
    printf("Enter integer elements for array : \n\n");
    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
    {
        scanf("%d", &num_vva);

        // If 'num_vva' is negative ( < 0), then convert it to positive (multiply by -1)
        if (num_vva < 0)
            num_vva = -1*num_vva;
        
        iArray_vva[i_vva] = num_vva;
    }

    // *** PRINTING ENTIRE ARRAY ***
    printf("\n\n");

    printf("Array elements are : \n\n");
    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
        printf("%d\n", iArray_vva[i_vva]);

    // ** separating out even numbers from array elements **
    printf("\n\n");
    printf("Prime numbers amongst the array elements are : \n\n");
    for (i_vva = 0; i_vva < NUM_ELEMENTS; i_vva++)
    {
        for (j_vva = 1; j_vva <= iArray_vva[i_vva]; j_vva++)
        {
            if ((iArray_vva[i_vva] % j_vva) == 0)
                count_vva++;
        }

        // if a number is prime, it is only divisible by 1 and itself.
        // hence if a number is prime, the value of count will be exactly 2
        // if the value of 'count' is greater than 2 , the number is divisible by 1, itself and some other number/s, hence not prime
        // the value of 'count' will be 1 only if 'iArray_vva[]' is 1

        if (count_vva == 2)
        {
                printf("%d\n", iArray_vva[i_vva]);
        }
        count_vva = 0; // reset for checking next number
    }

    return (0);
}