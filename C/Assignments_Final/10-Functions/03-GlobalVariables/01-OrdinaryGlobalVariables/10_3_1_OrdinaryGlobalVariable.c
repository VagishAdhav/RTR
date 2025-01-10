#include <stdio.h>

// ** GLOBAL SCOPE *******

// If not initialised by us, global variables are initialised to their zero values
// (with respect to their data types i.e. : 0 0 for int, 0.0 for float, double etc.) by default
// But still, for good programming discipline, we shall explicitly initialise our global variable with zero

int global_count_vva = 0;

int main(void)
{
    // function prototypes
    void change_count_one(void);
    void change_count_two(void);
    void change_count_three(void);

    // code
    printf("\n");

    printf("main() : value of global_count = %d\n", global_count_vva);

    change_count_one();
    change_count_two();
    change_count_three();

    printf("\n");
    return (0);
}

// ** global scope ***

void change_count_one(void)
{
    // code
    global_count_vva = 100;
    printf("change_count_one() : value of global_count = %d\n", global_count_vva);
}


// ** global scope ***

void change_count_two(void)
{
    // code
    global_count_vva = global_count_vva + 1;
    printf("change_count_two() : value of global_count = %d\n", global_count_vva);
}

// ** global scope ***

void change_count_three(void)
{
    // code
    global_count_vva = global_count_vva + 10;
    printf("change_count_three() : value of global_count = %d\n", global_count_vva);
}
