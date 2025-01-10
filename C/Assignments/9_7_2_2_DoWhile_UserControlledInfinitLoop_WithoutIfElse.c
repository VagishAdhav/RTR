#include <stdio.h>

int main(void)
{
    // variable declaration
    char vva_option, c_vvah = '\0';

    //code
    printf("\n\n");

    printf("Once the infinite loop begins , enter 'Q' or 'q' to quit the infinite do while loop : \n\n");


    printf("\n\n");
    vva_option = getch();

    do
    {
        do
        {
            printf("\n");
            printf("In loop ....\n");
            c_vvah = getch();  // wait for character inout
        }while (c_vvah != 'Q' && c_vvah != 'q');

        printf("\n\n");
        printf("EXISTING USER CONTROLLED INFINITE LOOP...");
        printf("\n\n");
        printf("Do you want to begin user controlled infinite loop again?.. (Y/y - Yes, any other key - No) : ");
        vva_option = getch();
    } while ((vva_option == 'Y' || vva_option == 'y'));
   

    return (0);
}