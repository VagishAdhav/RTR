#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva, vva_j, c_vva;

    //code
    printf("\n\n");

    i_vva = 0;
    while(i_vva < 64)
    {
        vva_j = 0;
        while (vva_j < 64)
        {
            c_vva = ((i_vva & 0x8) == 0) ^ ((vva_j & 0x8) == 0);

            if (c_vva == 0)
            {
                printf("  ");
            }
            if (c_vva == 1)
            {
                printf("* ");
            }
            vva_j++;
        }
        printf("\n\n");
        i_vva++;
    }

    return (0);
}