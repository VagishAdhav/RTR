#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// entry point function => main() => valid return type (int) and 2 parameters (int argc , char *argv[])

int main(int argc, char *argv[])
{
    // variable declaration 
    int i_vva;

    //code
    printf("\n\n");
    printf("Hello World !!!\n\n");  // library function
    printf("number of command line arguments = %d \n\n", argc);

    printf("Command line arguments passed to thi sprogram are : \n\n");
    for (i_vva = 0; i_vva < argc; i_vva++)
    {
        printf("Command line argument number %d = %s\n", (i_vva + 1), argv[i_vva]);
    }

    printf("\n\n");

    return (0);
}
