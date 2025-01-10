#include <stdio.h>

int main(int argc, char *argv[], char *envp[])
{
    // function prototype OR declarations
    int  MyAddition(int, int);
    
    // variable declaration
    int vva_r;
    int vva_num_vva01, vva_num_vva02;
    int vva_num_vva03, vva_num_vva04;

    //code
    vva_num_vva01 = 10;
    vva_num_vva02 = 20;
    vva_num_vva03 = 30;
    vva_num_vva04 = 40;

    vva_r = MyAddition(MyAddition(vva_num_vva01, vva_num_vva02), MyAddition(vva_num_vva03, vva_num_vva04));
    // return values of MyAddition is sent as parameter to another call to MyAddition()

    printf("\n\n");
    printf("%d + %d + %d + %d = %d\n", vva_num_vva01, vva_num_vva02, vva_num_vva03, vva_num_vva04, vva_r);

    return (0);    
}

// *** function definition of MyAddition() *********
int MyAddition(int a_vva, int b_vva)
{
    // variable declaration
    int vva_sum;

    vva_sum = a_vva + b_vva;
    return (vva_sum);
}