#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // function prototypes OR declarations
    int MyAddition(int, int);

    // variable declarations
    int vva_r;
    int vva_num_vva01, vva_num_vva02;

    //code
    vva_num_vva01 = 10;
    vva_num_vva02 = 20;

    printf("\n\n");
    printf("%d + %d = %d\n", vva_num_vva01, vva_num_vva02, MyAddition(vva_num_vva01, vva_num_vva02));
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
