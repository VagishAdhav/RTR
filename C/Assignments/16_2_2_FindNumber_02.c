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
    // function prototype
    int va_Findnum_vvaber(int, int, va_list);

    // variable declaration
    int count = 0;
    int n;
    va_list num_vvabers_list;

    //code
    va_start(num_vvabers_list, num_vva);

    count = va_Findnum_vvaber(num_vva_to_be_found, num_vva, num_vvabers_list);
    
    if(count == 0)
        printf("number %d could not be found !!!\n\n", num_vva_to_be_found);
    else
        printf("number %d found %d times !!!\n\n", num_vva_to_be_found, count);

    va_end(num_vvabers_list);
}

int va_Findnum_vvaber(int num_vva_to_be_found, int num_vva, va_list list)
{
    // variable declaration
    int count_of_num_vva = 0;
    int n;

    //code
    while(num_vva)
    {
        n = va_arg(list, int);
        if (n == num_vva_to_be_found)
            count_of_num_vva++;
        num_vva--;
    }

    return count_of_num_vva;
}

