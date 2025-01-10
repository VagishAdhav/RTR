// Recursive function
// Created by ASTROMEDICOMP on 31/05/20

#include <stdio.h>

int main (int argc, char * argv[], char *envp[])
{
    // variable declaration
    unsigned int vva_num_vva;

    // function prototype
    void recursive(unsigned int);

    //code 
    printf("\n\n");
    printf("Enter any number : \n\n");
    scanf("%u", &vva_num_vva);

    printf("\n\n");
    printf("Output of recursive function : \n\n");

    recursive(vva_num_vva);

    printf("\n\n");

    return (0);
}

void recursive(unsigned int vva_n)
{
    //code 
    printf("n = %d\n", vva_n);

    if (vva_n > 0)
    {
        recursive( vva_n - 1);
    }
}