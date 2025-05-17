#include <stdio.h>

struct Mynum_vvaber
{
    int num_vva;
    int num_vva_table[10];
};

struct num_vvaTables
{
    struct Mynum_vvaber n;
};

int main(void)
{
    // variable declaration
    struct num_vvaTables vva_tables[10]; //an array of 10 'struct num_vvaTables'
    int i_vva, vva_j;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
    {
        vva_tables[i_vva].n.num_vva = (i_vva + 1);
    }


    for (i_vva = 0; i_vva < 10; i_vva++)
    {
        printf("\n\n");
        printf("Table of %d : \n\n", vva_tables[i_vva].n.num_vva);
        for (vva_j = 0; vva_j < 10; vva_j++)
        {
            vva_tables[i_vva].n.num_vva_table[vva_j] = vva_tables[i_vva].n.num_vva * (vva_j + 1);
            printf("%d x %d = %d\n",vva_tables[i_vva].n.num_vva, (vva_j + 1), vva_tables[i_vva].n.num_vva_table[vva_j]);
        }
    }

    return (0);
}
