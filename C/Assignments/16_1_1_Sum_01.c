#include <stdio.h>
#include <stdarg.h>

int main(void)
{
    // function prototype 
    int CalculateSum(int, ...);

    // variable declarations
    int answer;

    //code
    printf("\n\n");

    answer = CalculateSum(5, 10, 20, 30, 40, 50);
    printf("Answer = %d\n\n", answer);

    answer = CalculateSum(10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
    printf("Answer = %d\n\n", answer);

    answer = CalculateSum(0);
    printf("Answer = %d\n\n", answer);

    return(0);
}

int CalculateSum(int num_vva, ...) // Variadic function
{
    // variable declaration
    int sum_total = 0;
    int n;

    va_list num_vvabers_list;

    //code
    va_start(num_vvabers_list, num_vva);
    
    while(num_vva)
    {
        n = va_arg(num_vvabers_list, int);
        sum_total = sum_total + n;
        num_vva--;
    }

    va_end(num_vvabers_list);
    return(sum_total);
}