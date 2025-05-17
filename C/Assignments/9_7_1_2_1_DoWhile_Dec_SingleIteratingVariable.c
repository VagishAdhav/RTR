#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva;

    //code
    printf("\n\n");
    printf("Printing digits 10 to 1 : \n\n");

    i_vva = 10;
    
    do
    {
        printf("\t %d \n", i_vva);
        i_vva--;
    }while (i_vva >= 1);
    
    printf("\n\n");

    return (0);
}