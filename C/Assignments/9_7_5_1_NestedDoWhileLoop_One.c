#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva , vva_j;

    //code
    printf("\n\n");

    i_vva = 1;

    do
    {
        printf("i = %d \n", i_vva);
        printf("-------------\n\n");

        vva_j = 1;
        do
        {
            printf("\t j = %d\n", vva_j);
            vva_j++;
        }while(vva_j <= 5);

        i_vva++;
        printf("\n\n");
    }while(i_vva <= 10);

    return (0);
}