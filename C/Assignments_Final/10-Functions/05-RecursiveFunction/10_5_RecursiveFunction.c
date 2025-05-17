// Recursive function
// Created by ASTROMEDICOMP on 31/05/20

#include <stdio.h>

int main (int argc, char * argv[], char *envp[])
{
    // variable declaration
    unsigned int num_vva;

    // function prototype
    void recursive(unsigned int);

    //code 
    printf("\n\n");
    printf("Enter any number : \n\n");
    scanf("%u", &num_vva);

    printf("\n\n");
    printf("Output of recursive function : \n\n");

    recursive(num_vva);

    printf("\n\n");

    return (0);
}

void recursive(unsigned int n_vva)
{
    //code 
    printf("n = %d\n", n_vva);

    if (n_vva > 0)
    {
        recursive( n_vva - 1);
    }
}