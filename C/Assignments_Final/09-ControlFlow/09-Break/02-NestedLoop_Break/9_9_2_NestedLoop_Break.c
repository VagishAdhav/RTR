#include <stdio.h>
#include <conio.h>

int main(void)
{
    // variable declaration
    int i_vva, j_vva;

    //code
    printf("\n\n");

    for (i_vva = 1; i_vva <= 20; i_vva++)
    {
        for (j_vva = 1; j_vva <= 20; j_vva++)
        {
            if (j_vva > 1)
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