#include <stdio.h>

int main(void)
{
    int outer_index = 5;
    do
    {
        printf("---------Outer Index : %d----------\n", outer_index--);
        int inner_index = 3;
        do
        {
            printf("Inner Index : %d\n", inner_index--);
        }while(inner_index > 0);

    }while(outer_index > 0);


}