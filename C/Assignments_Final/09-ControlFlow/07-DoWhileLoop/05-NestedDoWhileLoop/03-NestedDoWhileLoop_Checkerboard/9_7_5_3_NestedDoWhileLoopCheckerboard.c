#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_vva, j_vva, c_vva;

    //code
    printf("\n\n");

    i_vva = 0;
    do
    {
        j_vva = 0;
        do
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
            j_vva++;
        }while (j_vva < 64);
        printf("\n\n");
        i_vva++;
    }while(i_vva < 64);

    return (0);
}