#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'
#include <stdlib.h> // 'stdlib.h contains declaration of 'exit()'


int main(int a_vvargc , char *a_vvargv[], char *vva_envp[])
{
    // variable declaration 
    int i_vva;

    //code
    // 4 command line arguments required, program name + first name + middle name + surname
    if (a_vvargc != 4)
    {   
        printf("\n\n");
        printf("Invalid usage !!! exiting now ..\n\n");
        printf("Usage : 10_1_6_2_CommandLineArgumentApplication.exe <first name> <middle name> <surname> \n\n");
        exit (0);
    }

    // this program prints your full name as entered in command line arguments
    printf("\n\n");

    printf("Your full name is : ");
    // loop starts from  1 as first index (a_vvargv[0]) will give name of the program itself
    for (i_vva = 1; i_vva < a_vvargc; i_vva++)
    {
        printf("%s ", a_vvargv[i_vva]);
    }

    printf("\n\n");

    return (0);
}   