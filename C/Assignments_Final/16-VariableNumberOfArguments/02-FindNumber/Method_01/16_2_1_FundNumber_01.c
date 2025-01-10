#include <stdio.h>
#include <stdarg.h>

#define num_vva_TO_BE_FOUND 3
#define NUM_ELEMENTS    10

int main(void)
{
    // function prototypes
    void Findnum_vvaber(int, int, ...);

    //code
    printf("\n\n");

    Findnum_vvaber(num_vva_TO_BE_FOUND, NUM_ELEMENTS, 3, 5, 9, 2, 3, 6, 9, 3, 1, 3);

    return (0);
}

void Findnum_vvaber(int num_vva_to_be_found, int num_vva, ...) // variadic function
{
    // variable declaration
    int count_vva = 0;
    int n_vva;
    va_list numbers_list_vva;

    //code
    va_start(numbers_list_vva, num_vva);

    while(num_vva)
    {
        n_vva = va_arg(numbers_list_vva, int);
        if (n_vva == num_vva_to_be_found)
            count_vva++;
        num_vva--;
    }

    if(count_vva == 0)
        printf("number %d could not be found !!!\n\n", num_vva_to_be_found);
    else
        printf("number %d found %d times !!!\n\n", num_vva_to_be_found, count_vva);

    va_end(numbers_list_vva);
}
