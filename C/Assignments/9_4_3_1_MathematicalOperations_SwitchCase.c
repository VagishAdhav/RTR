#include <stdio.h> // for printf()
#include <conio.h> // for getch()

int main(void)
{
    // variable declaration
    int a_vva, b_vva;
    int result_vva;

    char vva_option, vva_option_division;

    // code
    printf("\n\n");

    printf("Enter value for A : ");
    scanf("%d", &a_vva);

    printf("Enter value for B : ");
    scanf("%d", &b_vva);

    printf("Enter option in character : \n\n");
    printf("'A' or 'a' for Addition : \n");
    printf("'S' or 's' for Subtraction : \n");
    printf("'M' or 'm' for Multiplication : \n");
    printf("'D' or 'd' for Division : \n");

    printf(" Enter option : ");
    vva_option = getch();

    printf("\n\n");

    switch(vva_option)
    {
        // fall through condition for 'A' and 'a'
        case 'A':
        case 'a':
            result_vva = a_vva + b_vva;
            printf("Addition of A = %d and B = %d gives result %d !!! \n\n", a_vva, b_vva, result_vva);
            break;
        
        // fall through condition for 'S' and 's'
        case 'S':
        case 's':
            if (a_vva >= b_vva)
            {
                result_vva = a_vva - b_vva;
                printf("Subscription of B = %d from A = %d gives result %d !!!\n\n", b_vva, a_vva, result_vva);
            }
            else
            {
                result_vva = b_vva - a_vva;
                printf("Subscription of A = %d from B = %d gives result %d !!!\n\n", a_vva, b_vva, result_vva);
            }
            break;

        // fall through condition for 'M' and 'm'
        case 'M':
        case 'm':
            result_vva = a_vva * b_vva;
            printf("Multiplication of A = %d and B = %d gives result %d !!! \n\n", a_vva, b_vva, result_vva);
            break;

        // fall through condition for 'D' and 'd
        case 'D':
        case 'd':
            printf("Enter option in character : \n\n");
            printf("'Q' or 'q' or '/' for quotient_vva upon division : \n");
            printf("'R' or 'r' '%%' for remainder_vva upon division : \n");

            printf("Enter option : ");

            vva_option_division = getch();

            switch (vva_option_division)
            {
                // fall through condition for 'Q' and 'q' and '/'
                case 'Q':
                case 'q':
                case '/':
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
                    break; // break case of 'Q' and 'q' and '/'

                // fall through condition for 'R' and 'r' and '%'
                case 'R':
                case 'r':
                case '%':
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
                    break; // break case of 'R' and 'r' and '%'
                
                default:
                    printf("Invalid character %c entered for division !!! please try again ...\n\n", vva_option_division);
                    break;
            } // ending of switch option d_vvaivision 

            break; // break for 'D' or 'd'
        
        default: // default case for switch(vva_option)
            printf("Invalid character %c entered !!! please try again ..\n\n", vva_option);
            break;
            
    } // ending curly brace for switch(vva_option)

    printf("Switch case block complete !!!\n");

    return (0);
}
