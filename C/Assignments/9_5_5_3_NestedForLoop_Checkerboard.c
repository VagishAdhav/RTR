#include <stdio.h>

int main(void)
{
    //variable declaration 
    int vva_i, vva_j, vva_c;

    //code 
    printf("\n\n");

    for (vva_i = 0; vva_i < 64; vva_i++)
    {
        for (vva_j = 0; vva_j < 64; vva_j++)
        {
            vva_c = ((vva_i & 0x8) == 0) ^ ((vva_j & 0x8) == 0);

            if (vva_c == 0)
            {
                printf("  ");
            }
            if (vva_c == 1)
            {
                printf("* ");
            }
        }
        printf("\n\n");
    }

    return (0);
}