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

    // vva_local_count is initialised to 0
    // vva_local_count = vva_local_count + 1 = 0 + 1 = 1
    change_count();

    // since vva_locaL_count is a local static variable change_count(), it will retain 
    // its value from previous call to change_count(). so vva_local_count is 1
    // vva_local_count = vva_local_count + 1 = 1 + 1 = 2
    change_count();

    // since vva_locaL_count is a local static variable change_count(), it will retain 
    // its value from previous call to change_count(). so vva_local_count is 2
    // vva_local_count = vva_local_count + 1 = 2 + 1 = 3
    change_count();


    return (0);

    // local scope of main ends
}

//global scope
void change_count(void)
{
    // local scope of change count begins

    // variable declarations
    // 'vva_local_count' is a local static variable, it is local to change_count() only
    // it will retain values between change_count()
    static int vva_local_count = 0;

    //code
    vva_local_count = vva_local_count + 1;
    printf("Local count = %d\n", vva_local_count);

    // ** local scope of change count ends****
}

// ********* global scope ***** 