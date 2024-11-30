#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_i;

    //code 
    printf("\n\n");

    printf("Printing digits 1 to 10 : \n\n");

    vva_i = 1;

    do
    {
        printf("\t%d\n", vva_i);
        vva_i++;
    }while (vva_i <= 10);

    printf("\n\n");
}