#include <stdio.h>
#include <conio.h>

int main(void)
{
    // variable declaration
    int vva_i, vva_j;

    //code
    printf("\n\n");

    for (vva_i = 1; vva_i <= 20; vva_i++)
    {
        for (vva_j = 1; vva_j <= 20; vva_j++)
        {
            if (vva_j > 1)
            {
                break;
            }
            else
            {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
    return (0);
}