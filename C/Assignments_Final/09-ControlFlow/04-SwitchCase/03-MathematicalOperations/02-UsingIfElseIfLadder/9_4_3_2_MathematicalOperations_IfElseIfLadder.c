#include <stdio.h> // for printf()
#include <conio.h> // for printf()

int main(void)
{
    // variable declaration 
    int a_vva, b_vva;
    int result_vva;

    char option_vva, option_division_vva;

    // code
    printf("\n\n");

    printf("Enter value for 'A' : ");
    scanf("%d", &a_vva);

    printf("Enter value for 'B' : ");
    scanf("%d", &b_vva);

    
    printf("Enter option in character : \n\n");
    printf("'A' or 'a' for Addition : \n");
    printf("'S' or 's' for Subtraction : \n");
    printf("'M' or 'm' for Multiplication : \n");
    printf("'D' or 'd' for Division : \n");

    printf(" Enter option : ");
    option_vva = getch();

    printf("\n\n");

    if (option_vva == 'A' || option_vva == 'a')
    {
        result_vva = a_vva  + b_vva;
        printf("Addition of A = %d and B = %d gives result %d !!!\n\n", a_vva, b_vva, result_vva);
    }
    else if (option_vva == 'S' || option_vva == 's')
    {
        if (a_vva >= b_vva)
        {
            result_vva = a_vva - b_vva;
            printf("Subtraction of B = %d from A = %d gives result %d !!!\n\n", b_vva, a_vva, result_vva);
        }
        else
        {
            result_vva = b_vva - a_vva;
            printf("Subtraction of A = %d from B = %d gives result %d !!!\n\n", a_vva, b_vva, result_vva);
        }
    }
    else if (option_vva == 'M' || option_vva == 'm')
    {
        result_vva = a_vva * b_vva;
        printf("Multiplication of A = %d and B = %d gives result %d !!!\n\n", a_vva, b_vva, result_vva);
    }
    else if (option_vva == 'D' || option_vva == 'd')
    {
        printf("Enter option in character : \n\n");
        printf("'Q' or 'q' or '/' for quotient_vva upon division : \n");
        printf("'R' or 'r' '%%' for remainder_vva upon division : \n");

        printf("Enter option : ");

        option_division_vva = getch();
        printf("\n\n");

        if (option_division_vva == 'Q' || option_division_vva == 'q' || option_division_vva == '/')
        {
            if (a_vva >= b_vva)
            {
                result_vva = a_vva / b_vva;
                printf("Division of A = %d by B = %d gives quotient_vva = %d !!! \n\n", a_vva, b_vva, result_vva);
            }
            else
            {
                result_vva = b_vva / a_vva;
                printf("Division of B = %d by A = %d gives quotient_vva = %d !!! \n\n", b_vva, a_vva, result_vva);
            }
        }
        else if (option_division_vva == 'R' || option_division_vva == 'r' || option_division_vva == '%')
        {
            if (a_vva >= b_vva)
            {
                result_vva = a_vva % b_vva;
                printf("Division of A = %d by B = %d gives remainder_vva = %d !!!\n\n", a_vva, b_vva, result_vva);
            }
            else
            {
                result_vva = b_vva % a_vva;
                printf("Division of B = %d by A = %d gives remainder_vva = %d !!! \n\n", b_vva, a_vva, result_vva);
            }
        }
        else
        {
            printf("Invalid character %c entered !!! please try again ..\n\n", option_vva);
        }
    }
    printf("if - else if - else ladder complete!!!\n");

    return (0);
}