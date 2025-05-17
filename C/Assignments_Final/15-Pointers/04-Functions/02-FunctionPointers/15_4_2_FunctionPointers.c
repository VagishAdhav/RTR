#include <stdio.h>

int main(void)
{
    // function declarations
    int AddIntegers_vva(int, int);
    int SubtractIntegers_vva(int, int);
    float AddFloats_vva(float, float);

    // variable declaration
    typedef int (*AddIntsFnPtr)(int, int);
    AddIntsFnPtr ptrAddTwoIntegers_vva = NULL;
    AddIntsFnPtr ptrFunc_vva = NULL;

    // variable declaration
    typedef float (*AddFloatsFnPtr)(float, float);
    AddFloatsFnPtr ptrAddTwoFloats_vva = NULL;

    int iAnswer_vva = 0;
    float fAnswer_vva = 0.0f;

    //code
    ptrAddTwoIntegers_vva = AddIntegers_vva;
    iAnswer_vva = ptrAddTwoIntegers_vva(9, 30);
    printf("\n\n");
    printf("Sum of Integers = %d\n\n", iAnswer_vva);
    
    ptrFunc_vva = SubtractIntegers_vva;
    iAnswer_vva = ptrFunc_vva(9, 30);
    printf("\n\n");
    printf("Subtraction of Integers = %d\n\n", iAnswer_vva);

    ptrAddTwoFloats_vva = AddFloats_vva;
    fAnswer_vva = ptrAddTwoFloats_vva(11.45f, 8.2f);
    printf("\n\n");
    printf("Sum of floatin point numbers = %f\n\n", fAnswer_vva);

    return (0);
}

int AddIntegers_vva(int a_vva, int b_vva)
{
    // variable declaration
    int c_vva;

    //code
    c_vva = a_vva + b_vva;
    return(c_vva);
}

int SubtractIntegers_vva(int a_vva, int b_vva)
{
    // variable declaration
    int c_vva;

    //code
    if (a_vva > b_vva)
        c_vva = a_vva - b_vva;
    else
        c_vva = b_vva - a_vva;

    return(c_vva);
}

float AddFloats_vva(float f_num1_vva, float f_num2_vva)
{
    // variable declaration
    float ans_vva;

    //code
    ans_vva = f_num1_vva + f_num2_vva;
    return (ans_vva);
}