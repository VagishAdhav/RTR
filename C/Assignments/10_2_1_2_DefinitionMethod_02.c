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
    int vva_a, vva_b, vva_sum;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A' : " );
    scanf("%d", &vva_a);

    printf("\n\n");
    printf("Enter Integer value for 'B' : ");
    scanf("%d", &vva_b);

    vva_sum = vva_a + vva_b;

    return (vva_sum);
}