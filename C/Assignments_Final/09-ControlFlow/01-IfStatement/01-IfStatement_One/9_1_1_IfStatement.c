#include <stdio.h>

int main(void)
{
    //variable declaration
    int a_vva, b_vva, p_vva;

    //code 
    a_vva = 9;
    b_vva= 30;
    p_vva= 30;

    printf("\n\n");

    if (a_vva < b_vva)
    {
        printf("A is less than B !!!\n\n");
    }

    if (b_vva != p_vva)
    {
        printf("B is not equal to P !!! \n\n");
    }

    printf("Both comparisons have been done !!! \n\n");

    return (0);
}