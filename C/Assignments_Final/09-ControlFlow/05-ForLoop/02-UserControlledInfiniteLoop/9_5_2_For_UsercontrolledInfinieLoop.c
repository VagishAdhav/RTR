#include <stdio.h>

int main(void)
{
    //variable declaration
    char option_vva, ch_vva = '\0';

    //code 
    printf("\n\n");
    printf("Once the infinite loop begins, enter 'Q' or 'q' to quit the infinite for loop : \n\n");
    printf("Enter 'Y' or 'y' to initiate user controlled infinite loop : ");
    printf("\n\n");
    option_vva = getch();
    if (option_vva == 'Y' || option_vva == 'y')
    {
        for (;;) //Infinite loop
        {
            printf("In loop ...\n");
            ch_vva = getch();
            if (ch_vva == 'Q' || ch_vva == 'q')
                break; // User 
        }
    }

    printf("\n\n");
    printf("EXITING USER CONTROLLER INFINITE LOOP...");
    printf("\n\n");

    return (0);


}