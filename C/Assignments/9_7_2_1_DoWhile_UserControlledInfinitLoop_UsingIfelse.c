#include <stdio.h>

int main(void)
{
    // variable declaration
    char vva_option, vva_ch = '\0';

    //code
    printf("\n\n");

    printf("Once the infinite loop begins , enter 'Q' or 'q' to quit the infinite do while loop : \n\n");

    printf("Enter 'Y or 'y' to initiate user controller infinite loop : ");
    printf("\n\n");
    vva_option = getch();

    if (vva_option == 'Y' || vva_option == 'y')
    {
        do
        {
            printf("In loop ....\n");
            vva_ch = getch();
            if (vva_ch == 'Q' || vva_ch == 'q')
                break; // user controlled exit from infinite loop
        }while (1); // infinit eloop

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