#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i;

    //code
    printf("\n\n");
    printf("Printing digits 10 to 1 : \n\n");

    vva_i = 10;
    
    do
    {
        printf("\t %d \n", vva_i);
        vva_i--;
    }while (vva_i >= 1);
    
    printf("\n\n");

    return (0);
}