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
    int i_vva, j_vva;

    //code
    for (i_vva = 0; i_vva < 10; i_vva++)
    {
        vva_tables[i_vva].n.num_vva = (i_vva + 1);
    }


    for (i_vva = 0; i_vva < 10; i_vva++)
    {
        printf("\n\n");
        printf("Table of %d : \n\n", vva_tables[i_vva].n.num_vva);
        for (j_vva = 0; j_vva < 10; j_vva++)
        {
            vva_tables[i_vva].n.num_vva_table[j_vva] = vva_tables[i_vva].n.num_vva * (j_vva + 1);
            printf("%d x %d = %d\n",vva_tables[i_vva].n.num_vva, (j_vva + 1), vva_tables[i_vva].n.num_vva_table[j_vva]);
        }
    }

    return (0);
}
