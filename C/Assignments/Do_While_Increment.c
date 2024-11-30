#include <stdio.h>

int main(void)
{
    int vva_index = 1;
    do
    {
        printf("%d \t", vva_index++);
    }while(vva_index <= 10);

    return (0);
}