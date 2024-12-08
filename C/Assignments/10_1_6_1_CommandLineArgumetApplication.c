#include <stdio.h> // contains declaration of 'printf()'
#include <ctype.h> // contains declaration of 'atoi()'
#include <stdlib.h> // contain declaration of exit()

int main(int argc, char *argv[], char *envp[])
{
    //variable declarations
    int vva_i;
    int vva_num;
    int vva_sum = 0;

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
    for ( vva_i = 1; vva_i < argc; vva_i++)
    {
        vva_num = atoi(argv[vva_i]);
        vva_sum = vva_sum + vva_num;
    }

    printf("Sum = %d \n\n", vva_sum);

    return (0);

}

