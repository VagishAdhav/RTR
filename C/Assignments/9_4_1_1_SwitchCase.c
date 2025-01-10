#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_num_vva_month;

    //code 
    printf("Enter number of month (1 of 12) : ");
    scanf("%d", &vva_num_vva_month);
    printf("\n\n");

    switch (vva_num_vva_month)
    {
    case 1: // like 'if'
        printf("Month number %d is JANUARY !!!\n\n", vva_num_vva_month);
        break;

    case 2: // like 'else if'
        printf("Month number %d is FEBRUARY !!!\n\n", vva_num_vva_month);
        break;
    
    case 3: // like 'else if'
        printf("Month number %d is MARCH !!!\n\n", vva_num_vva_month);
        break;
    
    case 4: // like 'else if'
        printf("Month number %d is APRIL !!!\n\n", vva_num_vva_month);
        break;
    
    case 5: // like 'else if'
        printf("Month number %d is MAY !!!\n\n", vva_num_vva_month);
        break;
    
    case 6: // like 'else if'
        printf("Month number %d is JUNE !!!\n\n", vva_num_vva_month);
        break;
    
    case 7: // like 'else if'
        printf("Month number %d is JULY !!!\n\n", vva_num_vva_month);
        break;
    
    case 8: // like 'else if'
        printf("Month number %d is AUGUST !!!\n\n", vva_num_vva_month);
        break;
    
    case 9: // like 'else if'
        printf("Month number %d is SEPTEMBER !!!\n\n", vva_num_vva_month);
        break;
    
    case 10: // like 'else if'
        printf("Month number %d is OCTOBER !!!\n\n", vva_num_vva_month);
        break;
    
    case 11: // like 'else if'
        printf("Month number %d is NOVEMBER !!!\n\n", vva_num_vva_month);
        break;
    
    case 12: // like 'else if'
        printf("Month number %d is DECEMBER !!!\n\n", vva_num_vva_month);
        break;

    default: // like ending optional 'else'
        printf("Invalid month number %d is entered, please try again !!!\n\n", vva_num_vva_month);
    }

    printf("Switch case block complete !!! \n");

    return (0);
}