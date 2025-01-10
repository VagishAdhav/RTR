#include <stdio.h> // contains declaration of 'printf()'

//***** User defined functions : method of calling function 1 ***************
// ********* calling all function in main() directly******

// Entry point function => main() +> va;id return type (int) and 3 parameters (int argc, char *argv[], char * envp[])

int main(int argc, char *argv[], char * envp[])
{
    // function prototype OR declarations
    void MyAddition(void);
    int MySubtraction(void);
    void MyMultiplication(int, int);
    int MyDivision(int, int);

    // variable declarations
    int result_subtraction_vva;
    int a_multiplication_vva, b_multiplication_vva;
    int a_division_vva, b_division_vva, result_division_vva;

    //code

    // ** Addition **
    MyAddition(); // function call

    // ** Subtraction **
    result_subtraction_vva  = MySubtraction(); // function call

    printf("\n\n");
    printf("Subtraction yields result = %d\n", result_subtraction_vva);

    // **** Multiplication ****
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for multiplication : ");
    scanf("%d", &a_multiplication_vva);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for multiplication : ");
    scanf("%d", &b_multiplication_vva);

    MyMultiplication(a_multiplication_vva, b_multiplication_vva); // function call

    // ** Division ** 
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for division : ");
    scanf("%d", &a_division_vva);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for division : ");
    scanf("%d", &b_division_vva);

    result_division_vva = MyDivision(a_division_vva, b_division_vva); // function call
    printf("\n\n");

    printf("Division of %d and %d gives = %d (quotient_vva)\n", a_division_vva, b_division_vva, result_division_vva);
    printf("\n\n");

    return (0);

}

// ***** Function definition of MyAddition() **********
void MyAddition(void) // function definition
{
    // variable declaration : local variable to MyAddition()
    int a_vva, b_vva, sum_vva;

    // code
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for addition : ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for addition : ");
    scanf("%d", &b_vva);

    sum_vva = a_vva + b_vva;

    printf("\n\n");
    printf("Sum of %d and %d = %d\n\n", a_vva, b_vva, sum_vva);
}

// ******* Function definition of MySubtraction() ****
int MySubtraction(void) // function definition
{
    // variable declaration
    int a_vva, b_vva, vva_subtraction;

    // code
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for subtraction : ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for subtraction : ");
    scanf("%d", &b_vva);

    vva_subtraction = a_vva - b_vva;

    return(vva_subtraction);
}

// **** Function definition of  MyMultiplication() ******
void MyMultiplication(int a_vva, int b_vva)
{
    // variable declaration : local variables to MyMultiplication()
    int vva_multiplication;

    //code
    vva_multiplication = a_vva * b_vva;

    printf("\n\n");
    printf("Multiplication of %d and  %d = %d\n\n", a_vva, b_vva, vva_multiplication);
}

// *** Function definition of MyDivision() *****
int MyDivision(int a_vva, int b_vva) // function definition
{
    // variable declaration : local variables to MyDivision()
    int d_vvaivision_quotient_vva;

    //code

    if (a_vva > b_vva)
    {
        d_vvaivision_quotient_vva =  a_vva / b_vva;
    }
    else
    {
        d_vvaivision_quotient_vva = b_vva / a_vva;
    }

    return (d_vvaivision_quotient_vva);
}