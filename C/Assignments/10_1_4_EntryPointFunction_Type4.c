#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// entry point function => main() => valid return type (int) and 2 parameters (int argc , char *argv[])

int main(int argc, char *argv[])
{
    // variable declaration 
    int vva_i;

    //code
    printf("\n\n");
    printf("Hello World !!!\n\n");  // library function
    printf("Number of command line arguments = %d \n\n", argc);

    printf("Command line arguments passed to thi sprogram are : \n\n");
    for (vva_i = 0; vva_i < argc; vva_i++)
    {
        printf("Command line argument number %d = %s\n", (vva_i + 1), argv[vva_i]);
    }

    printf("\n\n");

    return (0);
}
