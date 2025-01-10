#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva, j_vva;

    //code
    printf("\n\n");
    printf("Printing digits 10 to 1 and 100 to 10: \n\n");

    i_vva = 10;
    j_vva = 100;
    
    do
    {
        printf("\t %d \t %d \n", i_vva, j_vva);
        i_vva--;
        j_vva = j_vva - 10;
    }while (i_vva >=  1, j_vva >= 10);
    
    printf("\n\n");

    return (0);
}