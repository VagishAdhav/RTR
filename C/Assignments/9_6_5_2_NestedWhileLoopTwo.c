#include <stdio.h>

int main()
{
    // variable declaration

    int i_vva, vva_j, vva_k;

    //code
    printf("\n\n");

    i_vva = 1;

    while (i_vva <= 10)
    {
        printf("i = %d \n", i_vva);
        printf("---------------------\n\n");

        vva_j = 1;
        while (vva_j <= 5)
        {
            printf("\t j = %d\n", vva_j);
            printf("\t----------------------\n\n");

            vva_k = 1;
            while (vva_k <= 3)
            {
                printf("\t\tk = %d\n", vva_k);
                vva_k++;
            }
            printf("\n\n");
            vva_j++;            
        }
        printf("\n\n");
        i_vva++;  
    }

    return (0);
}