#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // function prototypes OR declarations
    int MyAddition(int, int);

    // variable declarations
    int vva_r;
    int vva_num01, vva_num02;

    //code
    vva_num01 = 10;
    vva_num02 = 20;

    printf("\n\n");
    printf("%d + %d = %d\n", vva_num01, vva_num02, MyAddition(vva_num01, vva_num02));
    printf("\n\n");

    return (0);
}

// **** Function definition os MyAddition() ******
int MyAddition(int vva_a, int vva_b) // function definition
{
    // function prototype
    int Add(int, int);

    //code 
    return(Add(vva_a, vva_b)); // return value of Add() is used as return value of function MyAddition()
}

int Add(int vva_x, int vva_y)
{
    //code

    return (vva_x + vva_y);
}
