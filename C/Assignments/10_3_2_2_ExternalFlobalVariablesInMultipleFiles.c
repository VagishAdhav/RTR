#include <stdio.h>

// ** GLOBAL SCOPE ***

int vva_global_count = 0;

int main(void)
{
    // function prototypes
    void change_count(void);
    void change_count_one(void); // function defined in file 10_3_2_2_File_01.c
    void change_count_two(void); // function defined in file 10_3_2_2_File_02.c

    // code
    printf("\n");
    change_count();
    change_count_one(); // function defined in file 10_3_2_2_File_01.c
    change_count_two(); // function defined in file 10_3_2_2_File_02.c
    return (0);
}

void change_count(void)
{
    //code
    vva_global_count = vva_global_count + 1;
    printf("Global count = %d\n", vva_global_count);
}

