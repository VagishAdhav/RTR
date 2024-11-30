#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_i , vva_j;

    //code
    printf("\n\n");

    vva_i = 1;

    do
    {
        printf("i = %d \n", vva_i);
        printf("-------------\n\n");

        vva_j = 1;
        do
        {
            printf("\t j = %d\n", vva_j);
            vva_j++;
        }while(vva_j <= 5);

        vva_i++;
        printf("\n\n");
    }while(vva_i <= 10);

    return (0);
}