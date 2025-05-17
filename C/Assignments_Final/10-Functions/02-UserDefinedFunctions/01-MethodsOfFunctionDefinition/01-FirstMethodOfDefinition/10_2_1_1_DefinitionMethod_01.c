#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// Entry-point function = > main()= > valid return type 'int' and 3 parameters (int argc, char *argv[], char *envp[])

int main(int argc, char *argv, char *envp[])
{
    // function prototype /declaration /signature
    void MyAddition(void);

    // code
    MyAddition(); // function call
    return (0);
}

// ******* User defined function : Method of definition 1 ******
// ******* No return value, no parameter

void MyAddition(void)  // function definition
{
    // variable declaration : local variables to MyAddition()
    int a_vva, b_vva, sum_vva;

    //code
    printf("\n\n");
    printf("Enter integer value for 'A' : " );
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter integer value for 'B' : " );
    scanf("%d", &b_vva);

    sum_vva = a_vva + b_vva;

    printf("\n\n");

    printf("Sum of %d and %d = %d \n\n", a_vva, b_vva, sum_vva);

}
