#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry point function => main() => valid return type (int) and 3 parameters (int argc, char *argv[], char *envp[])
int main(int argc, char *argv[], char *envp[])
{
    // function prototype /declaration /signature
    int MyAddition(int, int);

    // variable declaration : local variable to main()
    int a_vva, b_vva, result_vva;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A' : " );
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter Integer value for 'B' : ");
    scanf("%d", &b_vva);


    // code 
    result_vva = MyAddition(a_vva, b_vva); // function call

    printf("\n\n");
    printf("Sum of %d and %d = %d\n\n", a_vva, b_vva, result_vva);

    return (0);
}

//************** User defined function : Method of definition 2********
// *********** Valid (int) return value , no parameters **************

int MyAddition(int a_vva, int b_vva) // function definition
{
    // variable declaration : local variables to MyAddition()
    int vva_sum;

    // code
    vva_sum = a_vva + b_vva;
    return (vva_sum);
}