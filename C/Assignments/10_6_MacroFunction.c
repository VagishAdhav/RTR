#include <stdio.h>

#define MAX_NUMBER(a, b) ((a) > (b) ? (a) : (b))

int main(int argc, char *argv[], char *envp[])
{
    //variable declarations
    int vva_iNum_01;
    int vva_iNum_02;
    int vva_iResult;

    float vva_fNum_01;
    float vva_fNum_02;
    float vva_fResult;

    // code
    // ********* COMPARING INTEGER VALUES **********
    printf("\n\n");
    printf("Enter an integer number : \n\n");
    scanf("%d", &vva_iNum_01);

    printf("\n\n");
    printf("Enter another integer number : \n\n");
    scanf("%d", &vva_iNum_02);

    vva_iResult = MAX_NUMBER(vva_iNum_01, vva_iNum_02);
    printf("\n\n");
    printf("Result of macro function MAX_NUMBER() = %d\n", vva_iResult);

    printf("\n\n");

    // ******** COMPARING FLOATING POINT VALUES *****************
    printf("\n\n");
    printf("Enter a floating point number : \n\n");
    scanf("%f", &vva_fNum_01);

    printf("\n\n");    
    printf("Enter another floating point number : \n\n");
    scanf("%f", &vva_fNum_02);

    vva_fResult = MAX_NUMBER(vva_fNum_01, vva_fNum_02);
    printf("\n\n");
    printf("Result of macro function MAX_NUMBER() = %f\n", vva_fResult);

    printf("\n\n");

    return (0);

}