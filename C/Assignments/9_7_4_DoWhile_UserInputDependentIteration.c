#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_i_num, vva_num, vva_i;

    //code
    printf("\n\n");

    printf("Enter an integer value from which iteration must begin : ");
    scanf("%d", &vva_i_num);

    printf("How many digits do you want to print from %d onwards ? :", vva_i_num);
    scanf("%d", &vva_num);


    printf("Printing digits %d to %d : \n\n", vva_i_num, (vva_i_num + vva_num));


    vva_i = vva_i_num;

    do
    {
        printf("\t %d\n", vva_i);
        vva_i++;
    }while (vva_i <= (vva_i_num + vva_num));

    printf("\n\n");

    return (0);
}