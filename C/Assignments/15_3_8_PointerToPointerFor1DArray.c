#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    void MyAlloc(int **ptr, unsigned int num_vvaberOfElements);

    // variable declarations
    int *piArray = NULL;
    unsigned int num_vva_elements;
    int i;

    //code
    printf("\n\n");
    printf("How many elements you want in integer array ?\n\n");
    scanf("%u", &num_vva_elements);

    printf("\n\n");
    MyAlloc(&piArray, num_vva_elements);

    printf("Enter %u elements to fill up your integer array : \n\n", num_vva_elements);
    for (i = 0; i < num_vva_elements; i++)
    {
        scanf("%d", &piArray[i]);
    }

    printf("The %u elements entered by you in the integer array : \n\n", num_vva_elements);
    for (i = 0; i < num_vva_elements; i++)
    {
        printf("%u\n", piArray[i]);
    }

    printf("\n\n");
    if (piArray)
    {
        free(piArray);
        piArray = NULL;
        printf("Memory allocated has now been successfully freed !!!\n\n");
    }

    return (0);
}

void MyAlloc(int **ptr, unsigned int num_vvaberOfElements)
{
    //code
    *ptr = (int *)malloc(num_vvaberOfElements * sizeof(int));
    if (*ptr == NULL)
    {
        printf("Could not allocate memory !!! Exiting now...\n\n");
        exit(0);
    }
}
