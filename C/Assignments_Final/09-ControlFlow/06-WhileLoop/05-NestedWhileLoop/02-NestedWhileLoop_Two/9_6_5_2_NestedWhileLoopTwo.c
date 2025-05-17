#include <stdio.h>

int main()
{
    // variable declaration

    int i_vva, j_vva, k_vva;

    //code
    printf("\n\n");

    i_vva = 1;

    while (i_vva <= 10)
    {
        printf("i = %d \n", i_vva);
        printf("---------------------\n\n");

        j_vva = 1;
        while (j_vva <= 5)
        {
            printf("\t j = %d\n", j_vva);
            printf("\t----------------------\n\n");

            k_vva = 1;
            while (k_vva <= 3)
            {
                printf("\t\tk = %d\n", k_vva);
                k_vva++;
            }
            printf("\n\n");
            j_vva++;            
        }
        printf("\n\n");
        i_vva++;  
    }

    return (0);
}