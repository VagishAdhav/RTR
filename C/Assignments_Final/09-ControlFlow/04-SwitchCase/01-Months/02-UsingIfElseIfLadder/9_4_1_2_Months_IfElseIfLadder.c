#include <stdio.h>

int main (void)
{
    // variable declaration 
    int num_month_vva;

    //code 
    printf("Enter number of month (1 of 12) : ");
    scanf("%d", &num_month_vva);
    printf("\n\n");

    if (num_month_vva == 1) // like 'case 1'
        printf("Month number %d is JANUARY !!!\n\n", num_month_vva);

    else if (num_month_vva == 2)  // like 'case  2''
        printf("Month number %d is FEBRUARY !!!\n\n", num_month_vva);
    
    else if (num_month_vva == 3)  // like 'case  3''
        printf("Month number %d is MARCH !!!\n\n", num_month_vva);
    
    else if (num_month_vva == 4)  // like 'case 4''
        printf("Month number %d is APRIL !!!\n\n", num_month_vva);

    else if (num_month_vva == 5)  // like 'case  5''
        printf("Month number %d is MAY !!!\n\n", num_month_vva);
    
    else if (num_month_vva == 6)  // like 'case  6''
        printf("Month number %d is JUNE !!!\n\n", num_month_vva);

    else if (num_month_vva == 7)  // like 'case 7''
        printf("Month number %d is JULY !!!\n\n", num_month_vva);
    
    else if (num_month_vva == 8)  // like 'case  8''
        printf("Month number %d is AUGUST !!!\n\n", num_month_vva);
    
    else if (num_month_vva == 9)  // like 'case  9''
        printf("Month number %d is SEPTEMBER !!!\n\n", num_month_vva);
    
    else if (num_month_vva == 10)  // like 'case 10''
        printf("Month number %d is OCTOBER !!!\n\n", num_month_vva);

    else if (num_month_vva == 11)  // like 'case 11''
        printf("Month number %d is NOVEMBER !!!\n\n", num_month_vva);
    
    else if (num_month_vva == 12)  // like 'case 12''
        printf("Month number %d is DECEMBER !!!\n\n", num_month_vva);

    // 'else' in the if-else if -else ladder
    else
        printf("Invalid month number %d is entered, please try again !!!\n\n", num_month_vva);

    printf("If - Else If - Else ladder complete !!! \n");

    return (0);
}