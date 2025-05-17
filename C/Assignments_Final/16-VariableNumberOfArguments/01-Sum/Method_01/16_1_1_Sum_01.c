#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    // function prototype 
    int CalculateSum(int, ...);

    // variable declarations
    int answer_vva;

    //code
    printf("\n\n");

    answer_vva = CalculateSum(5, 10, 20, 30, 40, 50);
    printf("Answer = %d\n\n", answer_vva);

    answer_vva = CalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    printf("Answer = %d\n\n", answer_vva);

    answer_vva = CalculateSum(0);
    printf("Answer = %d\n\n", answer_vva);

    return(0);
}

int CalculateSum(int num_vva, ...) // Variadic function
{
    // variable declaration
    int sum_total_vva = 0;
    int n_vva;

    va_list numbers_list_vva;

    //code
    va_start(numbers_list_vva, num_vva);
    
    while(num_vva)
    {
        n_vva = va_arg(numbers_list_vva, int);
        sum_total_vva = sum_total_vva + n_vva;
        num_vva--;
    }

    va_end(numbers_list_vva);
    return(sum_total_vva);
}