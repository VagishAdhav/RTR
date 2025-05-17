// ** GLOBAL SCOPE
// global_count is a global variable declared in source code file 10_3_2_2_ExternalGlobalVAriablesInMultipleFiles.c
// To access it in this file, it must first be re-declared as an external variable in the global scope of this file along with extern keyword and its data type
// Then, it can be used as ordinary global variable throughout this file as well
// Here re-declaring 'global_count_vva' using extern keyword within change_count_two()


#include <stdio.h>

void change_count_two(void)
{

    // variable declaration
    extern int global_count_vva;

    //code 
    global_count_vva = global_count_vva + 1;
    printf("change_count_two() : Value of global_count in 10_3_2_2_File_02 = %d\n", global_count_vva);
}