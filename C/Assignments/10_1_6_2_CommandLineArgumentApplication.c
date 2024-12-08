#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'
#include <stdlib.h> // 'stdlib.h contains declaration of 'exit()'


int main(int vva_argc , char *vva_argv[], char *vva_envp[])
{
    // variable declaration 
    int vva_i;

    //code
    // 4 command line arguments required, program name + first name + middle name + surname
    if (vva_argc != 4)
    {   
        printf("\n\n");
        printf("Invalid usage !!! exiting now ..\n\n");
        printf("Usage : 10_1_6_2_CommandLineArgumentApplication.exe <first name> <middle name> <surname> \n\n");
        exit (0);
    }

    // this program prints your full name as entered in command line arguments
    printf("\n\n");

    printf("Your full name is : ");
    // loop starts from  1 as first index (vva_argv[0]) will give name of the program itself
    for (vva_i = 1; vva_i < vva_argc; vva_i++)
    {
        printf("%s ", vva_argv[vva_i]);
    }

    printf("\n\n");

    return (0);
}   