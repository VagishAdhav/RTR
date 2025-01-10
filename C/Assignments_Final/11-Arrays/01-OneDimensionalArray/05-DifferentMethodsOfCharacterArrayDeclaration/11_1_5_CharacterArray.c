#include <stdio.h>

int main(void)
{
    // variable declaration
    char cArray_vva_01[] = {'A', ' S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'}; // Must give \0 at the end for proper string initialisation
    char cArray_vva_02[] = {'W','E','L','C','O','M','E','S','\0'}; // Must give \0 at the end for proper string initialisation
    char cArray_vva_03[] = {'Y', 'O', 'U', '\0'}; // Must give \0 at the end for proper string initialisation
    char cArray_vva_04[] = "To"; // \0 is assumed size is 3, due to "" initialise.
    char cArray_vva_05[] = "REAL TIME RENDERING BATCH OF 2024-25"; // \0 is assumed, size is given as 40

    char chArray_WithoutNullTerminator[] = {'H', 'e', 'l', 'l', 'o'};

    // code
    printf("\n\n");

    printf("Size of cArray_vva_01 : %zu\n\n", sizeof(cArray_vva_01));
    printf("Size of cArray_vva_02 : %zu\n\n", sizeof(cArray_vva_02));
    printf("Size of cArray_vva_03 : %zu\n\n", sizeof(cArray_vva_03));
    printf("Size of cArray_vva_04 : %zu\n\n", sizeof(cArray_vva_04));
    printf("Size of cArray_vva_05 : %zu\n\n", sizeof(cArray_vva_05));
    

    printf("\n\n");

    printf("The strings are : \n\n");
    printf("cArray_vva_01 : %s\n\n", cArray_vva_01);
    printf("cArray_vva_02 : %s\n\n", cArray_vva_02);
    printf("cArray_vva_03 : %s\n\n", cArray_vva_03);
    printf("cArray_vva_04 : %s\n\n", cArray_vva_04);
    printf("cArray_vva_05 : %s\n\n", cArray_vva_05);
    
    printf("\n\n");
    printf("Size of chArray_WithoutNullTerminator : %zu\n\n", sizeof(chArray_WithoutNullTerminator));
    printf("chArray_WithoutNullTerminator : %s\n\n", chArray_WithoutNullTerminator); // will display garbage value at the end of string due to absence of \0

    return (0);  

}