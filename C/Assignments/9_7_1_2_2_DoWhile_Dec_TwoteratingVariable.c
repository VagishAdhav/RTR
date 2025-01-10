#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva, vva_j;

    //code
    printf("\n\n");
    printf("Printing digits 10 to 1 and 100 to 10: \n\n");

    i_vva = 10;
    vva_j = 100;
    
    do
    {
        printf("\t %d \t %d \n", i_vva, vva_j);
        i_vva--;
        vva_j = vva_j - 10;
    }while (i_vva >=  1, vva_j >= 10);
    
    printf("\n\n");

    return (0);
}