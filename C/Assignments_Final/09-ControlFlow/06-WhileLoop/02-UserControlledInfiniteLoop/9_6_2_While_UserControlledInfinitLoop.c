#include <stdio.h>

int main(void)
{
    // variable declaration
    char option_vva, ch_vva = '\0';

    //code
    printf("\n\n");

    printf("Once the infinite loop begins , enter 'Q' or 'q' to quit the infinite while loop : \n\n");

    printf("Enter 'Y or 'y' to initiate user controller infinite loop : ");
    printf("\n\n");
    option_vva = getch();

    if (option_vva == 'Y' || option_vva == 'y')
    {
        while (1)
        {
            printf("In loop ....\n");
            ch_vva = getch();
            if (ch_vva == 'Q' || ch_vva == 'q')
                break; // user controlled exit from infinite loop
        }

        printf("\n\n");
        printf("EXISTING USER CONTROLLED INFINITE LOOP...");
        printf("\n\n");
    }
    else 
    {
        printf("You must press 'Y' or 'y' to initiate the user controlled infinite loop ... please try again.. \n\n");
    }

    return (0);
}