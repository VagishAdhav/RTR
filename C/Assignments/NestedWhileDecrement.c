#include <stdio.h>

int main(void)
{
    int outer_index = 5;

    while (outer_index > 0)
    {
        printf("-------Outer Index : %d -----------\n", outer_index--);
        int inner_index = 3;
        while (inner_index > 0)
        {
            printf("Inner Index : %d \n", inner_index--);
        }

    }

}