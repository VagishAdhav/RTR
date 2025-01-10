#include <stdio.h>
#include <stdarg.h>

#define num_vva_TO_BE_FOUND 3
#define num_vva_ELEMENTS    10

int main(void)
{
    // function prototypes
    void Findnum_vvaber(int, int, ...);

    //code
    printf("\n\n");

    Findnum_vvaber(num_vva_TO_BE_FOUND, num_vva_ELEMENTS, 3, 5, 9, 2, 3, 6, 9, 3, 1, 3);

    return (0);
}

void Findnum_vvaber(int num_vva_to_be_found, int num_vva, ...) // variadic function
{
    // variable declaration
    int count = 0;
    int n;
    va_list num_vvabers_list;

    //code
    va_start(num_vvabers_list, num_vva);

    while(num_vva)
    {
        n = va_arg(num_vvabers_list, int);
        if (n == num_vva_to_be_found)
            count++;
        num_vva--;
    }

    if(count == 0)
        printf("number %d could not be found !!!\n\n", num_vva_to_be_found);
    else
        printf("number %d found %d times !!!\n\n", num_vva_to_be_found, count);

    va_end(num_vvabers_list);
}
