#include <stdio.h>

int main(void)
{
    //variable declarations
    int a_vva, b_vva;
    int vva_p, vva_q;
    char ch_result_01, ch_result_02;
    int i_result_01, i_result_02;

    //code 
    printf("\n\n");

    a_vva = 7;
    b_vva = 5;

    ch_result_01 = (a_vva > b_vva) ? 'A' : 'B';
    i_result_01 = (a_vva > b_vva) ? a_vva : b_vva;
    printf("Ternary operator answer 1 --- %c and %d \n\n", ch_result_01, i_result_01);

    vva_p = 30;
    vva_q = 30;
    ch_result_02 = (vva_p != vva_q) ? 'P' : 'Q';
    i_result_02 = (vva_p != vva_q) ? vva_p : vva_q;
    printf("Ternary operator answer 2 ---- %c and %d\n\n", ch_result_02, i_result_02);

    printf("\n\n");
    return (0);
}