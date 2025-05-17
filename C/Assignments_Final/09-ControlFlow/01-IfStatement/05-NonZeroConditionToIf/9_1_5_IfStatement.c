#include <stdio.h>

int main(void)
{
    //variable declaration
    int a_vva;

    //code
    printf("\n\n");

    a_vva = 5;
    if (a_vva) // non zero positive value
    {
        printf("if-block 1 : 'A' exists and has value = %d !!!\n\n", a_vva);
    }

    a_vva = -5;
    if (a_vva) // non zero negative value
    {
        printf("if-block 2 : 'A' exists and has value = %d !!!\n\n", a_vva);
    }

    a_vva = 0;
    if (a_vva) // zero value
    {
        printf("if-block 3 : 'A' exists and has value = %d !!!\n\n",a_vva);
    }

    printf("All three if-statements are done !!! \n\n");

    return (0);
}