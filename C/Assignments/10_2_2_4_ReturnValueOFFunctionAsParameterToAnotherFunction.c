#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // function prototype OR declarations
    int  MyAddition(int, int);
    
    // variable declaration
    int vva_r;
    int vva_num01, vva_num02;
    int vva_num03, vva_num04;

    //code
    vva_num01 = 10;
    vva_num02 = 20;
    vva_num03 = 30;
    vva_num04 = 40;

    vva_r = MyAddition(MyAddition(vva_num01, vva_num02), MyAddition(vva_num03, vva_num04));
    // return values of MyAddition is sent as parameter to another call to MyAddition()

    printf("\n\n");
    printf("%d + %d + %d + %d = %d\n", vva_num01, vva_num02, vva_num03, vva_num04, vva_r);

    return (0);    
}

// *** function definition of MyAddition() *********
int MyAddition(int vva_a, int vva_b)
{
    // variable declaration
    int vva_sum;

    vva_sum = vva_a + vva_b;
    return (vva_sum);
}