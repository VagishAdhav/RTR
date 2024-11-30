#include <stdio.h> // for printf()
#include <conio.h> // for printf()

int main(void)
{
    // variable declaration 
    int vva_a, vva_b;
    int vva_result;

    char vva_option, vva_option_division;

    // code
    printf("\n\n");

    printf("Enter value for 'A' : ");
    scanf("%d", &vva_a);

    printf("Enter value for 'B' : ");
    scanf("%d", &vva_b);

    
    printf("Enter option in character : \n\n");
    printf("'A' or 'a' for Addition : \n");
    printf("'S' or 's' for Subtraction : \n");
    printf("'M' or 'm' for Multiplication : \n");
    printf("'D' or 'd' for Division : \n");

    printf(" Enter option : ");
    vva_option = getch();

    printf("\n\n");

    if (vva_option == 'A' || vva_option == 'a')
    {
        vva_result = vva_a  + vva_b;
        printf("Addition of A = %d and B = %d gives result %d !!!\n\n", vva_a, vva_b, vva_result);
    }
    else if (vva_option == 'S' || vva_option == 's')
    {
        if (vva_a >= vva_b)
        {
            vva_result = vva_a - vva_b;
            printf("Subtraction of B = %d from A = %d gives result %d !!!\n\n", vva_b, vva_a, vva_result);
        }
        else
        {
            vva_result = vva_b - vva_a;
            printf("Subtraction of A = %d from B = %d gives result %d !!!\n\n", vva_a, vva_b, vva_result);
        }
    }
    else if (vva_option == 'M' || vva_option == 'm')
    {
        vva_result = vva_a * vva_b;
        printf("Multiplication of A = %d and B = %d gives result %d !!!\n\n", vva_a, vva_b, vva_result);
    }
    else if (vva_option == 'D' || vva_option == 'd')
    {
        printf("Enter option in character : \n\n");
        printf("'Q' or 'q' or '/' for quotient upon division : \n");
        printf("'R' or 'r' '%%' for remainder upon division : \n");

        printf("Enter option : ");

        vva_option_division = getch();
        printf("\n\n");

        if (vva_option_division == 'Q' || vva_option_division == 'q' || vva_option_division == '/')
        {
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
        }
        else if (vva_option_division == 'R' || vva_option_division == 'r' || vva_option_division == '%')
        {
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
        }
        else
        {
            printf("Invalid character %c entered !!! please try again ..\n\n", vva_option);
        }
    }
    printf("if - else if - else ladder complete!!!\n");

    return (0);
}