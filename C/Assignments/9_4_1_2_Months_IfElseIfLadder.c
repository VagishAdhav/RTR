#include <stdio.h>

int main (void)
{
    // variable declaration 
    int vva_num_month;

    //code 
    printf("Enter number of month (1 of 12) : ");
    scanf("%d", &vva_num_month);
    printf("\n\n");

    if (vva_num_month == 1) // like 'case 1'
        printf("Month number %d is JANUARY !!!\n\n", vva_num_month);

    else if (vva_num_month == 2)  // like 'case  2''
        printf("Month number %d is FEBRUARY !!!\n\n", vva_num_month);
    
    else if (vva_num_month == 3)  // like 'case  3''
        printf("Month number %d is MARCH !!!\n\n", vva_num_month);
    
    else if (vva_num_month == 4)  // like 'case 4''
        printf("Month number %d is APRIL !!!\n\n", vva_num_month);

    else if (vva_num_month == 5)  // like 'case  5''
        printf("Month number %d is MAY !!!\n\n", vva_num_month);
    
    else if (vva_num_month == 6)  // like 'case  6''
        printf("Month number %d is JUNE !!!\n\n", vva_num_month);

    else if (vva_num_month == 7)  // like 'case 7''
        printf("Month number %d is JULY !!!\n\n", vva_num_month);
    
    else if (vva_num_month == 8)  // like 'case  8''
        printf("Month number %d is AUGUST !!!\n\n", vva_num_month);
    
    else if (vva_num_month == 9)  // like 'case  9''
        printf("Month number %d is SEPTEMBER !!!\n\n", vva_num_month);
    
    else if (vva_num_month == 10)  // like 'case 10''
        printf("Month number %d is OCTOBER !!!\n\n", vva_num_month);

    else if (vva_num_month == 11)  // like 'case 11''
        printf("Month number %d is NOVEMBER !!!\n\n", vva_num_month);
    
    else if (vva_num_month == 12)  // like 'case 12''
        printf("Month number %d is DECEMBER !!!\n\n", vva_num_month);

    // 'else' in the if-else if -else ladder
    else
        printf("Invalid month number %d is entered, please try again !!!\n\n", vva_num_month);

    printf("If - Else If - Else ladder complete !!! \n");

    return (0);
}