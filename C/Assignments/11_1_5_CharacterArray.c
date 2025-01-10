#include <stdio.h>

int main(void)
{
    // variable declaration
    char c_vvaArray_01[] = {'A', ' S', 'T', 'R', 'O', 'M', 'E', 'D', 'I', 'C', 'O', 'M', 'P', '\0'}; // Must give \0 at the end for proper string initialisation
    char c_vvaArray_02[] = {'W','E','L','C','O','M','E','S','\0'}; // Must give \0 at the end for proper string initialisation
    char c_vvaArray_03[] = {'Y', 'O', 'U', '\0'}; // Must give \0 at the end for proper string initialisation
    char c_vvaArray_04[] = "To"; // \0 is assumed size is 3, due to "" initialise.
    char c_vvaArray_05[] = "REAL TIME RENDERING BATCH OF 2024-25"; // \0 is assumed, size is given as 40

    char c_vvahArray_WithoutNullTerminator[] = {'H', 'e', 'l', 'l', 'o'};

    // code
    printf("\n\n");

    printf("Size of c_vvaArray_01 : %zu\n\n", sizeof(c_vvaArray_01));
    printf("Size of c_vvaArray_02 : %zu\n\n", sizeof(c_vvaArray_02));
    printf("Size of c_vvaArray_03 : %zu\n\n", sizeof(c_vvaArray_03));
    printf("Size of c_vvaArray_04 : %zu\n\n", sizeof(c_vvaArray_04));
    printf("Size of c_vvaArray_05 : %zu\n\n", sizeof(c_vvaArray_05));
    

    printf("\n\n");

    printf("The strings are : \n\n");
    printf("c_vvaArray_01 : %s\n\n", c_vvaArray_01);
    printf("c_vvaArray_02 : %s\n\n", c_vvaArray_02);
    printf("c_vvaArray_03 : %s\n\n", c_vvaArray_03);
    printf("c_vvaArray_04 : %s\n\n", c_vvaArray_04);
    printf("c_vvaArray_05 : %s\n\n", c_vvaArray_05);
    
    printf("\n\n");
    printf("Size of c_vvaArray_WithoutNullTerminator : %zu\n\n", sizeof(c_vvahArray_WithoutNullTerminator));
    printf("c_vvahArray_WithoutNullTerminator : %s\n\n", c_vvahArray_WithoutNullTerminator); // will display garbage value at the end of string due to absence of \0

    return (0);  

}