#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva, vva_j;
    char c_vvah_01, c_vvah_02;
    int a_vva, result_vva_int;
    float f_vva, result_vva_float;
    int i_vva_explicit;
    float f_vva_explicit;

    //code
    printf("\n\n");

    //interconversion abd implicit type-casting between 'char' and 'int' types ...
    i_vva = 70;
    c_vvah_01 = i_vva;
    printf("I = %d\n", i_vva);
    printf("Character 1 (after ch_01 = i) = %c\n\n", c_vvah_01);

    c_vvah_02 = 'Q';
    vva_j = c_vvah_02;
    printf("Character 2 = %c\n", c_vvah_02);
    printf("J (after j = ch_02) = %d\n\n",vva_j);

    // implicit conversion of 'int' to 'float'....
    a_vva = 5;
    f_vva = 7.8f;
    result_vva_float = a_vva + f_vva;
    printf("Integer a = %d and floating point number %f added gives floating point Sum = %f\n\n", a_vva, f_vva, result_vva_float);

    result_vva_int = f_vva + a_vva;
    printf("Integer a = %d and floating point number %f added gives integer sum = %d\n\n", a_vva, f_vva, result_vva_int);

    // explicit type casting using cast operator...
    f_vva_explicit = 30.121995f;
    i_vva_explicit = (int)f_vva_explicit;
    printf("Floating point number which will be type casted explicitly = %f \n", f_vva_explicit);
    printf("Resultant integer after explicit type casting of %f = %d\n\n", f_vva_explicit, i_vva_explicit);

    return (0);
    
}