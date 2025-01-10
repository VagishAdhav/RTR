#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_num_vva, num_vva, i_vva;

    //code
    printf("\n\n");

    printf("Enter an integer value from which iteration must begin : ");
    scanf("%d", &i_num_vva);

    printf("How many digits do you want to print from %d onwards ? :", i_num_vva);
    scanf("%d", &num_vva);


    printf("Printing digits %d to %d : \n\n", i_num_vva, (i_num_vva + num_vva));


    i_vva = i_num_vva;

    do
    {
        printf("\t %d\n", i_vva);
        i_vva++;
    }while (i_vva <= (i_num_vva + num_vva));

    printf("\n\n");

    return (0);
}