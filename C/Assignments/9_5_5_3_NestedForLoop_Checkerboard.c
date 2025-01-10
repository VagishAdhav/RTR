#include <stdio.h>

int main(void)
{
    //variable declaration 
    int i_vva, vva_j, c_vva;

    //code 
    printf("\n\n");

    for (i_vva = 0; i_vva < 64; i_vva++)
    {
        for (vva_j = 0; vva_j < 64; vva_j++)
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
        }
        printf("\n\n");
    }

    return (0);
}