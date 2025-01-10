#include <stdio.h>

int main(void)
{
    //variable declaration 
    int i_vva, j_vva, c_vva;

    //code 
    printf("\n\n");

    for (i_vva = 0; i_vva < 64; i_vva++)
    {
        for (j_vva = 0; j_vva < 64; j_vva++)
        {
            c_vva = ((i_vva & 0x8) == 0) ^ ((j_vva & 0x8) == 0);

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