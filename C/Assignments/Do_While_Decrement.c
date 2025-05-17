#include <stdio.h>

int main(void)
{
    int i = 10;
    do
    {
        printf("%d \t", i--);
    }while(i > 0);

    return (0);
}