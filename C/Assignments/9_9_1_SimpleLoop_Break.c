#include <stdio.h>
#include <conio.h>

int main(void)
{
    // variable declaration
    int vva_i;
    char vva_ch;

    //code
    printf("\n\n");

    printf("Printing even numbers from 1 to 100 for every user input. Existing the loop when user enters characters 'Q' or 'q' : \n\n");
    printf("Enter character 'Q' or 'q' to exit loop : \n\n");

    for (vva_i = 1; vva_i <= 100; vva_i++)
    {
        printf("\t%d\n", vva_i);
        vva_ch = getch();
        if (vva_ch == 'Q' || vva_ch == 'q')
        {
            break;
        }
    }

    printf("\n\n");
    printf("EXISTING LOOP...");
    printf("\n\n");

    return (0);
}