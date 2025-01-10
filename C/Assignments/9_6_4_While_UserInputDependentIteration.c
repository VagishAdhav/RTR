#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vva_num_vva, vva_num_vva, i_vva;

    //code
    printf("\n\n");

    printf("Enter an integer value from which iteration must begin : ");
    scanf("%d", &i_vva_num_vva);

    printf("How many digits do you want to print from %d onwards ? :", i_vva_num_vva);
    scanf("%d", &vva_num_vva);


    printf("Printing digits %d to %d : \n\n", i_vva_num_vva, (i_vva_num_vva + vva_num_vva));


    i_vva = i_vva_num_vva;

    while (i_vva <= (i_vva_num_vva + vva_num_vva))
    {
        printf("\t %d\n", i_vva);
        i_vva++;
    }

    printf("\n\n");

    return (0);
}