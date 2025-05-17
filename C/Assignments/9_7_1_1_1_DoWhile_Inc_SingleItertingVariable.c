#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva;

    //code 
    printf("\n\n");

    printf("Printing digits 1 to 10 : \n\n");

    i_vva = 1;

    do
    {
        printf("\t%d\n", i_vva);
        i_vva++;
    }while (i_vva <= 10);

    printf("\n\n");
}