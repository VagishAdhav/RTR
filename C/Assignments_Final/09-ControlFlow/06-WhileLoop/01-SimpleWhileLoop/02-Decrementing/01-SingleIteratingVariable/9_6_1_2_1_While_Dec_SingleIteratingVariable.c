#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva;

    //code
    printf("\n\n");
    printf("Printing digits 10 to 1 : \n\n");

    i_vva = 10;
    while (i_vva >=  1)
    {
        printf("\t %d \n", i_vva);
        i_vva--;
    }
    
    printf("\n\n");

    return (0);
}