#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva, vva_j;

    //code
    printf("\n\n");

    printf("Printing digits 1 to 10 and 10 to 100 : \n\n");

    for (i_vva = 1, vva_j = 10; i_vva <= 10, vva_j <= 100; i_vva++, vva_j = vva_j + 10)
    {
        printf("\t %d \t %d\n", i_vva, vva_j);
    }

    printf("\n\n");

    return (0);
}