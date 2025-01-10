#include <stdio.h>

int main(void)
{
    //variable declaration
    char vva_option, c_vvah = '\0';

    //code 
    printf("\n\n");
    printf("Once the infinite loop begins, enter 'Q' or 'q' to quit the infinite for loop : \n\n");
    printf("Enter 'Y' or 'y' to initiate user controlled infinite loop : ");
    printf("\n\n");
    vva_option = getch();
    if (vva_option == 'Y' || vva_option == 'y')
    {
        for (;;) //Infinite loop
        {
            printf("In loop ...\n");
            c_vvah = getch();
            if (c_vvah == 'Q' || c_vvah == 'q')
                break; // User 
        }
    }

    printf("\n\n");
    printf("EXITING USER CONTROLLER INFINITE LOOP...");
    printf("\n\n");

    return (0);


}