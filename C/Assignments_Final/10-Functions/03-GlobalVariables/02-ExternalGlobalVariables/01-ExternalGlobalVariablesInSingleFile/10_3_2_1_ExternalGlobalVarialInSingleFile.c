#include <stdio.h>

// ** Global scope ***

int main(void)
{
    // function prototype
    void change_count(void);

    //variable declarations
    extern int global_count_vva;

    //code
    printf("\n");
    printf("Value of global_count before change_count() = %d\n", global_count_vva);
    change_count();
    printf("Value of global_count after change_count() = %d\n", global_count_vva);
    printf("\n");
    return (0);
}

// GLOBAL SCOPE

// global_count_vva is a global variable
// since it is declared before change_count() it can be used as any ordinary global variable in change_count()
// since it is declared after main(). it must be re-declared in/before  main() as an external global variable using 'extern' keyword
// once it is done, it can be used as ordinary global variable in main() as well.
int global_count_vva = 0;

void change_count(void)
{
    //code 
    global_count_vva = 5;
    printf("Value of global_count_vva in change_count() = %d\n", global_count_vva);
}