#include <stdio.h>

int main(void)
{
    //variable declarations
    int a_vva, b_vva;
    int p_vva, q_vva;
    char ch_result_01_vva, ch_result_02_vva;
    int i_result_01_vva, i_result_02_vva;

    //code 
    printf("\n\n");

    a_vva = 7;
    b_vva = 5;

    ch_result_01_vva = (a_vva > b_vva) ? 'A' : 'B';
    i_result_01_vva = (a_vva > b_vva) ? a_vva : b_vva;
    printf("Ternary operator answer 1 --- %c and %d \n\n", ch_result_01_vva, i_result_01_vva);

    p_vva = 30;
    q_vva = 30;
    ch_result_02_vva = (p_vva != q_vva) ? 'P' : 'Q';
    i_result_02_vva = (p_vva != q_vva) ? p_vva : q_vva;
    printf("Ternary operator answer 2 ---- %c and %d\n\n", ch_result_02_vva, i_result_02_vva);

    printf("\n\n");
    return (0);
}