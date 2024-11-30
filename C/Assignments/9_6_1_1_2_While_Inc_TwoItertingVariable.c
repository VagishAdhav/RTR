#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i, vva_j;

    //code 
    printf("\n\n");

    printf("Printing digits 1 to 10 and 10 to 100: \n\n");

    vva_i = 1;
    vva_j = 10;

    while (vva_i <= 10, vva_j <= 100)
    {
        printf("\t %d \t %d\n", vva_i, vva_j);
        vva_i++;
        vva_j = vva_j + 10;
    }

    printf("\n\n");


    return (0);
}