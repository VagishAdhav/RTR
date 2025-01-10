#include <stdio.h>

int main(void)
{
    // variable declaration
    char vva_option, c_vvah = '\0';

    //code
    printf("\n\n");

    printf("Once the infinite loop begins , enter 'Q' or 'q' to quit the infinite while loop : \n\n");

    printf("Enter 'Y or 'y' to initiate user controller infinite loop : ");
    printf("\n\n");
    vva_option = getch();

    if (vva_option == 'Y' || vva_option == 'y')
    {
        while (1)
        {
            printf("In loop ....\n");
            c_vvah = getch();
            if (c_vvah == 'Q' || c_vvah == 'q')
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