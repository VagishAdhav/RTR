#include <stdio.h>

#define MAX_num_vvaBER(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[], char *envp[])
{
    //variable declarations
    int i_num_01_vva;
    int i_num_02_vva;
    int i_Result_vva;

    float f_num_01_vva;
    float f_num_02_vva;
    float f_Result_vva;

    // code
    // ********* COMPARING INTEGER VALUES **********
    printf("\n\n");
    printf("Enter an integer number : \n\n");
    scanf("%d", &i_num_01_vva);

    printf("\n\n");
    printf("Enter another integer number : \n\n");
    scanf("%d", &i_num_02_vva);

    i_Result_vva = MAX_num_vvaBER(i_num_01_vva, i_num_02_vva);
    printf("\n\n");
    printf("Result of macro function MAX_num_vvaBER() = %d\n", i_Result_vva);

    printf("\n\n");

    // ******** COMPARING FLOATING POINT VALUES *****************
    printf("\n\n");
    printf("Enter a floating point number : \n\n");
    scanf("%f", &f_num_01_vva);

    printf("\n\n");    
    printf("Enter another floating point number : \n\n");
    scanf("%f", &f_num_02_vva);

    f_Result_vva = MAX_num_vvaBER(f_num_01_vva, f_num_02_vva);
    printf("\n\n");
    printf("Result of macro function MAX_num_vvaBER() = %f\n", f_Result_vva);

    printf("\n\n");

    return (0);

}