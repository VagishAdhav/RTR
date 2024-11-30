#include <stdio.h>

int main(void)
{
    //variable declarations
    int vva_a, vva_b;
    int vva_p, vva_q;
    char ch_result_01, ch_result_02;
    int i_result_01, i_result_02;

    //code 
    printf("\n\n");

    vva_a = 7;
    vva_b = 5;

    ch_result_01 = (vva_a > vva_b) ? 'A' : 'B';
    i_result_01 = (vva_a > vva_b) ? vva_a : vva_b;
    printf("Ternary operator answer 1 --- %c and %d \n\n", ch_result_01, i_result_01);

    vva_p = 30;
    vva_q = 30;
    ch_result_02 = (vva_p != vva_q) ? 'P' : 'Q';
    i_result_02 = (vva_p != vva_q) ? vva_p : vva_q;
    printf("Ternary operator answer 2 ---- %c and %d\n\n", ch_result_02, i_result_02);

    printf("\n\n");
    return (0);
}