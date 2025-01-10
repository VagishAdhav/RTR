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
    // function prototype
    int va_CalculateSum(int, va_list);

    // variable declaration
    int sum_total = 0;
    int n;

    va_list num_vvabers_list;

    //code
    va_start(num_vvabers_list, num_vva);

    sum_total = va_CalculateSum(num_vva, num_vvabers_list);

    va_end(num_vvabers_list);
    return(sum_total);
}


int va_CalculateSum(int num_vva, va_list list)
{
    // variable declaration
    int sum_total = 0;
    int n;

   //code
    while(num_vva)
    {
        n = va_arg(list, int);
        sum_total = sum_total + n;
        num_vva--;
    }

    return(sum_total);
}
