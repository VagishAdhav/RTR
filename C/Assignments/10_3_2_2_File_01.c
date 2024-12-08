// ** GLOBAL SCOPE
// global_count is a global variable declared in source code file 10_3_2_2_ExternalGlobalVAriablesInMultipleFiles.c
// To access it in this file, it must first be re-declared as an external variable in the global scope of this file along with extern keyword and its data type
// Then, it can be used as ordinary global variable throughout this file as well


#include <stdio.h>


extern int vva_global_count;
void change_count_one(void)
{
    //code
    vva_global_count = vva_global_count + 1;
    printf("change_count_one() : Value of global_count in 10_3_2_2_File_01 = %d\n", vva_global_count);
}