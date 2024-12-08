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
    int vva_result_subtraction;
    int vva_a_multiplication, vva_b_multiplication;
    int vva_a_division, vva_b_division, vva_result_division;

    //code

    // ** Addition **
    MyAddition(); // function call

    // ** Subtraction **
    vva_result_subtraction  = MySubtraction(); // function call

    printf("\n\n");
    printf("Subtraction yields result = %d\n", vva_result_subtraction);

    // **** Multiplication ****
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for multiplication : ");
    scanf("%d", &vva_a_multiplication);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for multiplication : ");
    scanf("%d", &vva_b_multiplication);

    MyMultiplication(vva_a_multiplication, vva_b_multiplication); // function call

    // ** Division ** 
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for division : ");
    scanf("%d", &vva_a_division);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for division : ");
    scanf("%d", &vva_b_division);

    vva_result_division = MyDivision(vva_a_division, vva_b_division); // function call
    printf("\n\n");

    printf("Division of %d and %d gives = %d (quotient)\n", vva_a_division, vva_b_division, vva_result_division);
    printf("\n\n");

    return (0);

}

// ***** Function definition of MyAddition() **********
void MyAddition(void) // function definition
{
    // variable declaration : local variable to MyAddition()
    int vva_a, vva_b, vva_sum;

    // code
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for addition : ");
    scanf("%d", &vva_a);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for addition : ");
    scanf("%d", &vva_b);

    vva_sum = vva_a + vva_b;

    printf("\n\n");
    printf("Sum of %d and %d = %d\n\n", vva_a, vva_b, vva_sum);
}

// ******* Function definition of MySubtraction() ****
int MySubtraction(void) // function definition
{
    // variable declaration
    int vva_a, vva_b, vva_subtraction;

    // code
    printf("\n\n");
    printf("Enter integer value of first operand 'A' for subtraction : ");
    scanf("%d", &vva_a);

    printf("\n\n");
    printf("Enter integer value of second operand 'B' for subtraction : ");
    scanf("%d", &vva_b);

    vva_subtraction = vva_a - vva_b;

    return(vva_subtraction);
}

// **** Function definition of  MyMultiplication() ******
void MyMultiplication(int vva_a, int vva_b)
{
    // variable declaration : local variables to MyMultiplication()
    int vva_multiplication;

    //code
    vva_multiplication = vva_a * vva_b;

    printf("\n\n");
    printf("Multiplication of %d and  %d = %d\n\n", vva_a, vva_b, vva_multiplication);
}

// *** Function definition of MyDivision() *****
int MyDivision(int vva_a, int vva_b) // function definition
{
    // variable declaration : local variables to MyDivision()
    int vva_division_quotient;

    //code

    if (vva_a > vva_b)
    {
        vva_division_quotient =  vva_a / vva_b;
    }
    else
    {
        vva_division_quotient = vva_b / vva_a;
    }

    return (vva_division_quotient);
}