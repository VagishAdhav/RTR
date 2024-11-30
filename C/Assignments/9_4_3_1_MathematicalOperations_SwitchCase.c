#include <stdio.h> // for printf()
#include <conio.h> // for getch()

int main(void)
{
    // variable declaration
    int vva_a, vva_b;
    int vva_result;

    char vva_option, vva_option_division;

    // code
    printf("\n\n");

    printf("Enter value for A : ");
    scanf("%d", &vva_a);

    printf("Enter value for B : ");
    scanf("%d", &vva_b);

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
            vva_result = vva_a + vva_b;
            printf("Addition of A = %d and B = %d gives result %d !!! \n\n", vva_a, vva_b, vva_result);
            break;
        
        // fall through condition for 'S' and 's'
        case 'S':
        case 's':
            if (vva_a >= vva_b)
            {
                vva_result = vva_a - vva_b;
                printf("Subscription of B = %d from A = %d gives result %d !!!\n\n", vva_b, vva_a, vva_result);
            }
            else
            {
                vva_result = vva_b - vva_a;
                printf("Subscription of A = %d from B = %d gives result %d !!!\n\n", vva_a, vva_b, vva_result);
            }
            break;

        // fall through condition for 'M' and 'm'
        case 'M':
        case 'm':
            vva_result = vva_a * vva_b;
            printf("Multiplication of A = %d and B = %d gives result %d !!! \n\n", vva_a, vva_b, vva_result);
            break;

        // fall through condition for 'D' and 'd
        case 'D':
        case 'd':
            printf("Enter option in character : \n\n");
            printf("'Q' or 'q' or '/' for quotient upon division : \n");
            printf("'R' or 'r' '%%' for remainder upon division : \n");

            printf("Enter option : ");

            vva_option_division = getch();

            switch (vva_option_division)
            {
                // fall through condition for 'Q' and 'q' and '/'
                case 'Q':
                case 'q':
                case '/':
                    if (vva_a >= vva_b)
                    {
                        vva_result = vva_a / vva_b;
                        printf("Division of A = %d by B = %d gives quotient = %d !!! \n\n", vva_a, vva_b, vva_result);
                    }
                    else
                    {
                        vva_result = vva_b / vva_a;
                        printf("Division of B = %d by A = %d gives quotient = %d !!! \n\n", vva_b, vva_a, vva_result);
                    }
                    break; // break case of 'Q' and 'q' and '/'

                // fall through condition for 'R' and 'r' and '%'
                case 'R':
                case 'r':
                case '%':
                    if (vva_a >= vva_b)
                    {
                        vva_result = vva_a % vva_b;
                        printf("Division of A = %d by B = %d gives remainder = %d !!!\n\n", vva_a, vva_b, vva_result);
                    }
                    else
                    {
                        vva_result = vva_b % vva_a;
                        printf("Division of B = %d by A = %d gives remainder = %d !!! \n\n", vva_b, vva_a, vva_result);
                    }
                    break; // break case of 'R' and 'r' and '%'
                
                default:
                    printf("Invalid character %c entered for division !!! please try again ...\n\n", vva_option_division);
                    break;
            } // ending of switch option vva_division 

            break; // break for 'D' or 'd'
        
        default: // default case for switch(vva_option)
            printf("Invalid character %c entered !!! please try again ..\n\n", vva_option);
            break;
            
    } // ending curly brace for switch(vva_option)

    printf("Switch case block complete !!!\n");

    return (0);
}
