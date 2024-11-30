#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_i , vva_j;

    //code
    printf("\n\n");

    vva_i = 1;

    while(vva_i <= 10)
    {
        printf("i = %d \n", vva_i);
        printf("-------------\n\n");

        vva_j = 1;
        while(vva_j <= 5)
        {
            printf("\t j = %d\n", vva_j);
            vva_j++;
        }

        vva_i++;
        printf("\n\n");
    }

    return (0);
}