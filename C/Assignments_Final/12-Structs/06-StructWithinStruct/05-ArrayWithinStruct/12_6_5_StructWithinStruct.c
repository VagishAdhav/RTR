#include <stdio.h>

struct Mynum_vvaber
{
    int num_vva;
    int num_vva_table[10];
};

struct num_vvaTables
{
    struct Mynum_vvaber a;
    struct Mynum_vvaber b;
    struct Mynum_vvaber c;
};

int main(void)
{
    // variable declaration
    struct num_vvaTables vva_tables;
    int i_vva;

    //code
    vva_tables.a.num_vva = 2;
    for (i_vva = 0; i_vva < 10; i_vva++)
        vva_tables.a.num_vva_table[i_vva] = vva_tables.a.num_vva * (i_vva + 1);
    printf("\n\n");
    printf("Table of %d : \n\n", vva_tables.a.num_vva);
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("%d x %d = %d\n",vva_tables.a.num_vva, (i_vva + 1), vva_tables.a.num_vva_table[i_vva]);

    vva_tables.b.num_vva = 3;
    for (i_vva = 0; i_vva < 10; i_vva++)
        vva_tables.b.num_vva_table[i_vva] = vva_tables.b.num_vva * (i_vva + 1);
    printf("\n\n");
    printf("Table of %d : \n\n", vva_tables.b.num_vva);
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("%d x %d = %d\n",vva_tables.b.num_vva, (i_vva + 1), vva_tables.b.num_vva_table[i_vva]);
    
    vva_tables.c.num_vva = 4;
    for (i_vva = 0; i_vva < 10; i_vva++)
        vva_tables.c.num_vva_table[i_vva] = vva_tables.c.num_vva * (i_vva + 1);
    printf("\n\n");
    printf("Table of %d : \n\n", vva_tables.c.num_vva);
    for (i_vva = 0; i_vva < 10; i_vva++)
        printf("%d x %d = %d\n",vva_tables.c.num_vva, (i_vva + 1), vva_tables.c.num_vva_table[i_vva]);
    

    return (0);
}
