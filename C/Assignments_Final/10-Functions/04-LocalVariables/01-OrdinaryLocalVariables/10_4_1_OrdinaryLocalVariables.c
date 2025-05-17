#include <stdio.h>

// ** GLOBAL SCOPE **
int main(void)
{
    // local scope of main() begins

    // variable declaration 
    // 'a' is a Local Variable. It is local main() only
    int a_vva = 5;

    // function prototype
    void change_count(void);

    // code
    printf("\n");
    printf("A = %d\n\n", a_vva);

    // local_count is initialised to '0'
    // local_count = local_count + 1 = 0 + 1 = 1
    change_count();

    // since local count is ordinary local variable of change_count(), is
    //.. will NOT retain its value from previous call change_count()
    // so local count is AGAIN initialised to 0
    // local_count = local_count + 1 = 0 + 1 = 1
    change_count();

    // since local count is ordinary local variable of change_count(), is
    //.. will NOT retain its value from previous call change_count()
    // so local count is AGAIN initialised to 0
    // local_count = local_count + 1 = 0 + 1 = 1
    change_count();

    return (0);

    // ** local scope of main ends **
}

// *** global scope ***

void change_count(void)
{
    // ** local scope of change count begins ***
    // variable declarations
    // 'local_count' is a local variable , it is local to change_count() only
    int local_count_vva = 0;

    //code
    local_count_vva = local_count_vva + 1;
    printf("Local count = %d\n", local_count_vva);

    // local scope of change_count() ends
}

// ** global scope ***