#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry point function => main() => valid return type (int) and 3 parameters (int argc, char *argv[], char *envp[])
int main(int argc, char *argv[], char *envp[])
{
    // function prototype /declaration /signature
    int MyAddition(void);

    // variable declaration : local variable to main()
    int result;

    // code 
    result = MyAddition(); // function call

    printf("\n\n");
    printf("Sum = %d\n\n", result);
    return (0);
}

//************** User defined function : Method of definition 2********
// *********** Valid (int) return value , no parameters **************

int MyAddition(void) // function definition
{
    // variable declaration : local variables to MyAddition()
    int a_vva, b_vva, vva_sum;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A' : " );
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter Integer value for 'B' : ");
    scanf("%d", &b_vva);

    vva_sum = a_vva + b_vva;

    return (vva_sum);
}