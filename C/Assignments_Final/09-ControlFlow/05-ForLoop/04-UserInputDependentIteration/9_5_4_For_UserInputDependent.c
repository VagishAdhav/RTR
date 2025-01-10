#include <stdio.h>

int main(void)
{
    //variable declaration
    int i_num_vva, num_vva, i_vva;

    //code
    printf("\n\n");

    printf("Enter an integer value from which iteration must begin : ");
    scanf("%d", &i_num_vva);

    printf("How may digits you want to print from %d onwards ? : ", i_num_vva);
    scanf("%d", &num_vva);

    printf("Printing digits %d to %d : \n\n", i_num_vva, (i_num_vva + num_vva));

    for (i_vva = i_num_vva; i_vva < (i_num_vva + num_vva); i_vva++)
    {
        printf("\t %d\n", i_vva);
    }

    printf("\n\n");

}