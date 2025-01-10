#include <stdio.h> // contains declaration of 'printf()'
#include <ctype.h> // contains declaration of 'atoi()'
#include <stdlib.h> // contain declaration of exit()

int main(int argc, char *argv[], char *envp[])
{
    //variable declarations
    int i_vva;
    int num_vva;
    int sum_vva = 0;

    //code 
    if (argc == 1)
    {
        printf("\n\n");
        printf("No numbers given for addition !!! Exiting now ...\n\n");
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
        num_vva = atoi(argv[i_vva]);
        sum_vva = sum_vva + num_vva;
    }

    printf("Sum = %d \n\n", sum_vva);

    return (0);

}

