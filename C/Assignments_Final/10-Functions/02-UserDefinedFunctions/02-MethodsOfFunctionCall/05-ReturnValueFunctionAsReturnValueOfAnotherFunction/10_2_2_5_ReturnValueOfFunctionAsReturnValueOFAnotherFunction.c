#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // function prototypes OR declarations
    int MyAddition(int, int);

    // variable declarations
    int num_vva01, num_vva02;

    //code
    num_vva01 = 10;
    num_vva02 = 20;

    printf("\n\n");
    printf("%d + %d = %d\n", num_vva01, num_vva02, MyAddition(num_vva01, num_vva02));
    printf("\n\n");

    return (0);
}

// **** Function definition os MyAddition() ******
int MyAddition(int a_vva, int b_vva) // function definition
{
    // function prototype
    int Add(int, int);

    //code 
    return(Add(a_vva, b_vva)); // return value of Add() is used as return value of function MyAddition()
}

int Add(int x_vva, int vva_y)
{
    //code

    return (x_vva + vva_y);
}
