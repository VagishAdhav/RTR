#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva, j_vva;

    //code
    printf("\n\n");

    printf("Printing digits 1 to 10 and 10 to 100 : \n\n");

    for (i_vva = 1, j_vva = 10; i_vva <= 10, j_vva <= 100; i_vva++, j_vva = j_vva + 10)
    {
        printf("\t %d \t %d\n", i_vva, j_vva);
    }

    printf("\n\n");

    return (0);
}