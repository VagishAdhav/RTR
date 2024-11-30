#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i, vva_j;
    char vva_ch_01, vva_ch_02;
    int vva_a, vva_result_int;
    float vva_f, vva_result_float;
    int vva_i_explicit;
    float vva_f_explicit;

    //code
    printf("\n\n");

    //interconversion abd implicit type-casting between 'char' and 'int' types ...
    vva_i = 70;
    vva_ch_01 = vva_i;
    printf("I = %d\n", vva_i);
    printf("Character 1 (after ch_01 = i) = %c\n\n", vva_ch_01);

    vva_ch_02 = 'Q';
    vva_j = vva_ch_02;
    printf("Character 2 = %c\n", vva_ch_02);
    printf("J (after j = ch_02) = %d\n\n",vva_j);

    // implicit conversion of 'int' to 'float'....
    vva_a = 5;
    vva_f = 7.8f;
    vva_result_float = vva_a + vva_f;
    printf("Integer a = %d and floating point number %f added gives floating point Sum = %f\n\n", vva_a, vva_f, vva_result_float);

    vva_result_int = vva_f + vva_a;
    printf("Integer a = %d and floating point number %f added gives integer sum = %d\n\n", vva_a, vva_f, vva_result_int);

    // explicit type casting using cast operator...
    vva_f_explicit = 30.121995f;
    vva_i_explicit = (int)vva_f_explicit;
    printf("Floating point number which will be type casted explicitly = %f \n", vva_f_explicit);
    printf("Resultant integer after explicit type casting of %f = %d\n\n", vva_f_explicit, vva_i_explicit);

    return (0);
    
}