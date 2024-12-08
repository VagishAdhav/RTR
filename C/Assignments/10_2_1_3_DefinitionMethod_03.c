#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry point function => main() => valid return type (int) and 3 parameters (int argc, char *argv[], char *envp[])
int main(int argc, char *argv[], char *envp[])
{
    // function prototype /declaration /signature
    void MyAddition(int, int);

    // variable declaration : local variable to main()
    int vva_a, vva_b;

    // code
    printf("\n\n");
    printf("Enter integer value for 'A' : " );
    scanf("%d", &vva_a);

    printf("\n\n");
    printf("Enter Integer value for 'B' : ");
    scanf("%d", &vva_b);


    // code 
    MyAddition(vva_a, vva_b); // function call

    return (0);
}

//************** User defined function : Method of definition 2********
// *********** Valid (int) return value , no parameters **************

void MyAddition(int vva_a, int vva_b) // function definition
{
    // variable declaration : local variables to MyAddition()
    int vva_sum;

    // code
    vva_sum = vva_a + vva_b;

    
    printf("\n\n");
    printf("Sum of %d and %d = %d\n\n", vva_a, vva_b, vva_sum);
}