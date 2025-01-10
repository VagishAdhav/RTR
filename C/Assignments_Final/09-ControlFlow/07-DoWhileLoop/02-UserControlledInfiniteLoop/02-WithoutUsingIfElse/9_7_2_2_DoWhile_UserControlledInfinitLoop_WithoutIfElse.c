#include <stdio.h>

int main(void)
{
    // variable declaration
    char option_vva, ch_vva = '\0';

    //code
    printf("\n\n");

    printf("Once the infinite loop begins , enter 'Q' or 'q' to quit the infinite do while loop : \n\n");


    printf("\n\n");
    option_vva = getch();

    do
    {
        do
        {
            printf("\n");
            printf("In loop ....\n");
            ch_vva = getch();  // wait for character inout
        }while (ch_vva != 'Q' && ch_vva != 'q');

        printf("\n\n");
        printf("EXISTING USER CONTROLLED INFINITE LOOP...");
        printf("\n\n");
        printf("Do you want to begin user controlled infinite loop again?.. (Y/y - Yes, any other key - No) : ");
        option_vva = getch();
    } while ((option_vva == 'Y' || option_vva == 'y'));
   

    return (0);
}