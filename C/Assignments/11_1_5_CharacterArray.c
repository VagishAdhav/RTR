#include <stdio.h>

int main(void)
{
    // variable declaration
    char vva_cArray_01[] = {'A', ' S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'}; // Must give \0 at the end for proper string initialisation
    char vva_cArray_02[] = {'W','E','L','C','O','M','E','S','\0'}; // Must give \0 at the end for proper string initialisation
    char vva_cArray_03[] = {'Y', 'O', 'U', '\0'}; // Must give \0 at the end for proper string initialisation
    char vva_cArray_04[] = "To"; // \0 is assumed size is 3, due to "" initialise.
    char vva_cArray_05[] = "REAL TIME RENDERING BATCH OF 2024-25"; // \0 is assumed, size is given as 40

    char vva_chArray_WithoutNullTerminator[] = {'H', 'e', 'l', 'l', 'o'};

    // code
    printf("\n\n");

    printf("Size of vva_cArray_01 : %zu\n\n", sizeof(vva_cArray_01));
    printf("Size of vva_cArray_02 : %zu\n\n", sizeof(vva_cArray_02));
    printf("Size of vva_cArray_03 : %zu\n\n", sizeof(vva_cArray_03));
    printf("Size of vva_cArray_04 : %zu\n\n", sizeof(vva_cArray_04));
    printf("Size of vva_cArray_05 : %zu\n\n", sizeof(vva_cArray_05));
    

    printf("\n\n");

    printf("The strings are : \n\n");
    printf("vva_cArray_01 : %s\n\n", vva_cArray_01);
    printf("vva_cArray_02 : %s\n\n", vva_cArray_02);
    printf("vva_cArray_03 : %s\n\n", vva_cArray_03);
    printf("vva_cArray_04 : %s\n\n", vva_cArray_04);
    printf("vva_cArray_05 : %s\n\n", vva_cArray_05);
    
    printf("\n\n");
    printf("Size of vva_cArray_WithoutNullTerminator : %zu\n\n", sizeof(vva_chArray_WithoutNullTerminator));
    printf("vva_chArray_WithoutNullTerminator : %s\n\n", vva_chArray_WithoutNullTerminator); // will display garbage value at the end of string due to absence of \0

    return (0);  

}