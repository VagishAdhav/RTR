#include <stdio.h>
#include <conio.h>

int main(void)
{
    // variable declaration
    int i_vva, vva_j;

    //code
    printf("\n\n");

    for (i_vva = 1; i_vva <= 20; i_vva++)
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