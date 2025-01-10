#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva , j_vva;

    //code
    printf("\n\n");

    i_vva = 1;

    do
    {
        printf("i = %d \n", i_vva);
        printf("-------------\n\n");

        j_vva = 1;
        do
        {
            printf("\t j = %d\n", j_vva);
            j_vva++;
        }while(j_vva <= 5);

        i_vva++;
        printf("\n\n");
    }while(i_vva <= 10);

    return (0);
}