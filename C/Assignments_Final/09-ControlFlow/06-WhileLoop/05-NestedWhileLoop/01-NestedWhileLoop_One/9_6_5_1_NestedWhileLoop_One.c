#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva , j_vva;

    //code
    printf("\n\n");

    i_vva = 1;

    while(i_vva <= 10)
    {
        printf("i = %d \n", i_vva);
        printf("-------------\n\n");

        j_vva = 1;
        while(j_vva <= 5)
        {
            printf("\t j = %d\n", j_vva);
            j_vva++;
        }

        i_vva++;
        printf("\n\n");
    }

    return (0);
}