#include <stdio.h> // contains declaration of 'printf()'
#include <ctype.h> // contains declaration of 'atoi()'
#include <stdlib.h> // contain declaration of exit()

int main(int argc, char *argv[], char *envp[])
{
    //variable declarations
    int i_vva;
    int vva_num_vva;
    int vva_sum = 0;

    //code 
    if (argc == 1)
    {
        printf("\n\n");
        printf("No num_vvabers given for addition !!! Exiting now ...\n\n");
        printf("Usage: 10_1_6_1_CommandLineArgumentApplication.exe <first number> <second number> \n\n");
        exit (0);
    }

    // ** This program adds all the command line arguments given in integer form and outputs the sum
    // 'atoi()' allows us to ignore non int argument
    printf("\n\n");
    printf("Sum of all integer command line arguments is: \n\n");
    // argument at index 0 is name of the executable so ignore it
    for ( i_vva = 1; i_vva < argc; i_vva++)
    {
        vva_num_vva = atoi(argv[i_vva]);
        vva_sum = vva_sum + vva_num_vva;
    }

    printf("Sum = %d \n\n", vva_sum);

    return (0);

}

