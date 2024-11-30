#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_i, vva_j, vva_c;

    //code
    printf("\n\n");

    vva_i = 0;
    do
    {
        vva_j = 0;
        do
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
            vva_j++;
        }while (vva_j < 64);
        printf("\n\n");
        vva_i++;
    }while(vva_i < 64);

    return (0);
}