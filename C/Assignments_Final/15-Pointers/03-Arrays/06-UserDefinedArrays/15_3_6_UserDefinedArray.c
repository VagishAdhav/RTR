#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE (sizeof(int))
#define FLOAT_SIZE (sizeof(float))
#define DOUBLE_SIZE (sizeof(double))
#define CHAR_SIZE (sizeof(char))

int main(void)
{
    //variable declaration
    int *ptr_iArray_vva = NULL;
    unsigned int iArrayLength_vva = 0;

    float *ptr_fArray_vva = NULL;
    unsigned int floatArrayLength_vva = 0;

    double *ptr_dArray_vva = NULL;
    unsigned int doubleArrayLength_vva = 0;

    char *ptr_cArray_vva = NULL;
    unsigned int charArrayLength_vva = 0;

    int i_vva;

    // code

    // *** INTEGER ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an integer array : ");
    scanf("%u", &iArrayLength_vva);

    ptr_iArray_vva = (int *)malloc(INT_SIZE * iArrayLength_vva);
    if (ptr_iArray_vva == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for integer array failed !! Exiting now ..\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for integer array succeeded !!!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d integer elements to fill up the integer array : \n\n", iArrayLength_vva);
    for (i_vva = 0; i_vva < iArrayLength_vva; i_vva++)
        scanf("%d", (ptr_iArray_vva + i_vva));

   // *** FLOAT ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an float array : ");
    scanf("%u", &floatArrayLength_vva);

    ptr_fArray_vva = (float *)malloc(FLOAT_SIZE * floatArrayLength_vva);
    if (ptr_fArray_vva == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for float array failed !! Exiting now ..\n\n");
        exit(0);
    }
    else
    { 
        printf("\n\n");
        printf("Memory allocation for float array succeeded !!!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d float elements to fill up the float array : \n\n", floatArrayLength_vva);
    for (i_vva = 0; i_vva < floatArrayLength_vva; i_vva++)
        scanf("%f", (ptr_fArray_vva + i_vva));

    // *** DOUBLE ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an double array : ");
    scanf("%u", &doubleArrayLength_vva);

    ptr_dArray_vva = (double *)malloc(DOUBLE_SIZE * doubleArrayLength_vva);
    if (ptr_dArray_vva == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for double array failed !! Exiting now ..\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for double array succeeded !!!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d double elements to fill up the double array : \n\n", doubleArrayLength_vva);
    for (i_vva = 0; i_vva < doubleArrayLength_vva; i_vva++)
        scanf("%lf", (ptr_dArray_vva + i_vva));

    
     // *** CHARACTER ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an character array : ");
    scanf("%u", &charArrayLength_vva);

    ptr_cArray_vva = (char *)malloc(CHAR_SIZE * charArrayLength_vva);
    if (ptr_cArray_vva == NULL)
    {
        printf("\n\n");
        printf("Memory allocation for char array failed !! Exiting now ..\n\n");
        exit(0);
    }
    else
    {
        printf("\n\n");
        printf("Memory allocation for char array succeeded !!!\n\n");
    }

    printf("\n\n");
    printf("Enter the %d character elements to fill up the char array : \n\n", charArrayLength_vva);
    for (i_vva = 0; i_vva < charArrayLength_vva; i_vva++)
    {
        *(ptr_cArray_vva + i_vva) = getch();
        printf("%c\n",  *(ptr_cArray_vva + i_vva));
    }

    // **** DISPLAY OF ARRAYS ****==

    // *** INTEGER ARRAY ****
    printf("\n\n");
    printf("The integer array enterred by you and considering of %d element is as follows : \n\n", iArrayLength_vva);
    for (i_vva = 0; i_vva < iArrayLength_vva; i_vva++)
        printf("%d \t at address : %p\n", *(ptr_iArray_vva + i_vva), (ptr_iArray_vva + i_vva));


    // *** FLOAT ARRAY ****
    printf("\n\n");
    printf("The float array enterred by you and considering of %d element is as follows : \n\n", floatArrayLength_vva);
    for (i_vva = 0; i_vva < floatArrayLength_vva; i_vva++)
        printf("%f \t at address : %p\n", *(ptr_fArray_vva + i_vva), (ptr_fArray_vva + i_vva));
   
    // *** DOUBLE ARRAY ****
    printf("\n\n");
    printf("The double array enterred by you and considering of %d element is as follows : \n\n", doubleArrayLength_vva);
    for (i_vva = 0; i_vva < doubleArrayLength_vva; i_vva++)
        printf("%lf \t at address : %p\n", *(ptr_dArray_vva + i_vva), (ptr_dArray_vva + i_vva));

    // *** CHAR ARRAY ****
    printf("\n\n");
    printf("The character array enterred by you and considering of %d element is as follows : \n\n", doubleArrayLength_vva);
    for (i_vva = 0; i_vva < charArrayLength_vva; i_vva++)
        printf("%c \t at address : %p\n", *(ptr_cArray_vva + i_vva), (ptr_cArray_vva + i_vva));


    // *** Freeing memory occupied by arrays (in reverse order of allocation)
    if (ptr_cArray_vva)
    {
        free(ptr_cArray_vva);
        ptr_cArray_vva = NULL;
        printf("\n\n");
        printf("Memory occupied by character array has been successfully freed!!!\n\n ");
    }

    if (ptr_dArray_vva)
    {
        free(ptr_dArray_vva);
        ptr_dArray_vva = NULL;
        printf("\n\n");
        printf("Memory occupied by double array has been successfully freed!!!\n\n ");
    }


    if (ptr_fArray_vva)
    {
        free(ptr_fArray_vva);
        ptr_fArray_vva = NULL;
        printf("\n\n");
        printf("Memory occupied by float array has been successfully freed!!!\n\n ");
    }


    if (ptr_iArray_vva)
    {
        free(ptr_iArray_vva);
        ptr_iArray_vva = NULL;
        printf("\n\n");
        printf("Memory occupied by integer array has been successfully freed!!!\n\n ");
    }

    return (0);
}