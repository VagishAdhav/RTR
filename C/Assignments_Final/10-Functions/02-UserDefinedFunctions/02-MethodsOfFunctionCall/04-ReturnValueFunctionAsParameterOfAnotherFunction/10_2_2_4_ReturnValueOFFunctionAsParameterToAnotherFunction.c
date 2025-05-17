#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // function prototype OR declarations
    int  MyAddition(int, int);
    
    // variable declaration
    int r_vva;
    int num_vva01, num_vva02;
    int num_vva03, num_vva04;

    //code
    num_vva01 = 10;
    num_vva02 = 20;
    num_vva03 = 30;
    num_vva04 = 40;

    r_vva = MyAddition(MyAddition(num_vva01, num_vva02), MyAddition(num_vva03, num_vva04));
    // return values of MyAddition is sent as parameter to another call to MyAddition()

    printf("\n\n");
    printf("%d + %d + %d + %d = %d\n", num_vva01, num_vva02, num_vva03, num_vva04, r_vva);

    return (0);    
}

// *** function definition of MyAddition() *********
int MyAddition(int a_vva, int b_vva)
{
    // variable declaration
    int sum_vva;

    sum_vva = a_vva + b_vva;
    return (sum_vva);
}