#include <stdio.h>

// ** Global scope ***

int main(void)
{
    // function prototype
    void change_count(void);

    //variable declarations
    extern int vva_global_count;

    //code
    printf("\n");
    printf("Value of global_count before change_count() = %d\n", vva_global_count);
    change_count();
    printf("Value of global_count after change_count() = %d\n", vva_global_count);
    printf("\n");
    return (0);
}

// GLOBAL SCOPE

// vva_global_count is a global variable
// since it is declared before change_count() it can be used as any ordinary global variable in change_count()
// since it is declared after main(). it must be re-declared in/before  main() as an external global variable using 'extern' keyword
// once it is done, it can be used as ordinary global variable in main() as well.
int vva_global_count = 0;

void change_count(void)
{
    //code 
    vva_global_count = 5;
    printf("Value of vva_global_count in change_count() = %d\n", vva_global_count);
}