#include <stdio.h>

int main(void)
{
    //variable declaration
    int a;

    //code
    printf("\n\n");

    a = 5;
    if (a) // non zero positive value
    {
        printf("if-block 1 : 'A' exists and has value = %d !!!\n\n", a);
    }

    a = -5;
    if (a) // non zero negative value
    {
        printf("if-block 2 : 'A' exists and has value = %d !!!\n\n", a);
    }

    a = 0;
    if (a) // zero value
    {
        printf("if-block 3 : 'A' exists and has value = %d !!!\n\n",a);
    }

    printf("All three if-statements are done !!! \n\n");

    return (0);
}