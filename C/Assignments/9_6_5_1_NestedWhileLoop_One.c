#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva , vva_j;

    //code
    printf("\n\n");

    i_vva = 1;

    while(i_vva <= 10)
    {
        printf("i = %d \n", i_vva);
        printf("-------------\n\n");

        vva_j = 1;
        while(vva_j <= 5)
        {
            printf("\t j = %d\n", vva_j);
            vva_j++;
        }

        i_vva++;
        printf("\n\n");
    }

    return (0);
}