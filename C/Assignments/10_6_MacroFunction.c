#include <stdio.h>

#define MAX_num_vvaBER(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[], char *envp[])
{
    //variable declarations
    int i_vvanum_vva_01;
    int i_vvanum_vva_02;
    int i_vvaResult;

    float f_vvanum_vva_01;
    float f_vvanum_vva_02;
    float f_vvaResult;

    // code
    // ********* COMPARING INTEGER VALUES **********
    printf("\n\n");
    printf("Enter an integer number : \n\n");
    scanf("%d", &i_vvanum_vva_01);

    printf("\n\n");
    printf("Enter another integer number : \n\n");
    scanf("%d", &i_vvanum_vva_02);

    i_vvaResult = MAX_num_vvaBER(i_vvanum_vva_01, i_vvanum_vva_02);
    printf("\n\n");
    printf("Result of macro function MAX_num_vvaBER() = %d\n", i_vvaResult);

    printf("\n\n");

    // ******** COMPARING FLOATING POINT VALUES *****************
    printf("\n\n");
    printf("Enter a floating point number : \n\n");
    scanf("%f", &f_vvanum_vva_01);

    printf("\n\n");    
    printf("Enter another floating point number : \n\n");
    scanf("%f", &f_vvanum_vva_02);

    f_vvaResult = MAX_num_vvaBER(f_vvanum_vva_01, f_vvanum_vva_02);
    printf("\n\n");
    printf("Result of macro function MAX_num_vvaBER() = %f\n", f_vvaResult);

    printf("\n\n");

    return (0);

}