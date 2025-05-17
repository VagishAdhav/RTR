#include <stdio.h>
#include <conio.h>

int main(void)
{
    // variable declaration
    int i_vva;
    char c_vvah;

    //code
    printf("\n\n");

    printf("Printing even num_vvabers from 1 to 100 for every user input. Existing the loop when user enters characters 'Q' or 'q' : \n\n");
    printf("Enter character 'Q' or 'q' to exit loop : \n\n");

    for (i_vva = 1; i_vva <= 100; i_vva++)
    {
        printf("\t%d\n", i_vva);
        c_vvah = getch();
        if (c_vvah == 'Q' || c_vvah == 'q')
        {
            break;
        }
    }

    printf("\n\n");
    printf("EXISTING LOOP...");
    printf("\n\n");

    return (0);
}