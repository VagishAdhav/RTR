#include <stdio.h>

int main(void)
{
    //variable declarations
    int vva_num;

    //code
    printf("\n\n");

    printf("Enter value for 'num' : ");
    scanf("%d", &vva_num);

    // if else if ladder begins from here..
    if (vva_num < 0)
        printf("Num = %d is less than 0 (NEGATIVE) !!! \n\n", vva_num);
    else if ((vva_num > 000) && (vva_num <= 100))
        printf("Num = %d is between 000 and 100 !!! \n\n", vva_num);
    else if ((vva_num > 100) && (vva_num <= 200))
        printf("Num = %d is between 100 and 200 !!! \n\n", vva_num);
    else if ((vva_num > 200) && (vva_num <= 300))
        printf("Num = %d is between 200 and 300 !!! \n\n", vva_num);
    else if ((vva_num > 300) && (vva_num <= 400))
        printf("Num = %d is between 300 and 400 !!! \n\n", vva_num);
    else if ((vva_num > 400) && (vva_num <= 500))
        printf("Num = %d is between 400 and 500 !!! \n\n", vva_num);
    else if (vva_num > 500)
        printf("Num = %d is greater than 500 !!! \n\n", vva_num);
    else // this is the terminating 'else' of this if-else if-else ladder.
        printf("Invalid value entered !!!\n\n");

    return (0);    
}