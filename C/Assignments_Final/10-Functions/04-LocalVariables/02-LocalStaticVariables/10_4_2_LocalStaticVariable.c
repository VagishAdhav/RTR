#include <stdio.h>

// *** Global scope ****

int main(void)
{
    // *** local scope of main() begins ***

    // variable declarations
    // 'a is a local variable, it is local to main() only

    int a_vva = 5;

    // function prototypes
    void change_count(void);

    //code
    printf("\n");
    printf("A = %d\n\n", a_vva);

    // local_count_vva is initialised to 0
    // local_count_vva = local_count_vva + 1 = 0 + 1 = 1
    change_count();

    // since vva_locaL_count is a local static variable change_count(), it will retain 
    // its value from previous call to change_count(). so local_count_vva is 1
    // local_count_vva = local_count_vva + 1 = 1 + 1 = 2
    change_count();

    // since vva_locaL_count is a local static variable change_count(), it will retain 
    // its value from previous call to change_count(). so local_count_vva is 2
    // local_count_vva = local_count_vva + 1 = 2 + 1 = 3
    change_count();


    return (0);

    // local scope of main ends
}

//global scope
void change_count(void)
{
    // local scope of change count begins

    // variable declarations
    // 'local_count_vva' is a local static variable, it is local to change_count() only
    // it will retain values between change_count()
    static int local_count_vva = 0;

    //code
    local_count_vva = local_count_vva + 1;
    printf("Local count = %d\n", local_count_vva);

    // ** local scope of change count ends****
}

// ********* global scope ***** 