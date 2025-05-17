#include <stdio.h>
#include <stdlib.h>

#define INT_SIZE (sizeof(int))
#define FLOAT_SIZE (sizeof(float))
#define DOUBLE_SIZE (sizeof(double))
#define CHAR_SIZE (sizeof(char))

int main(void)
{
    //variable declaration
    int *ptr_i_vvaArray = NULL;
    unsigned int i_vvantArrayLength = 0;

    float *ptr_f_vvaArray = NULL;
    unsigned int f_vvaloatArrayLength = 0;

    double *ptr_d_vvaArray = NULL;
    unsigned int d_vvaoubleArrayLength = 0;

    char *ptr_c_vvaArray = NULL;
    unsigned int c_vvaharArrayLength = 0;

    int i_vva;

    // code

    // *** INTEGER ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an integer array : ");
    scanf("%u", &i_vvantArrayLength);

    ptr_i_vvaArray = (int *)malloc(INT_SIZE * i_vvantArrayLength);
    if (ptr_i_vvaArray == NULL)
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
    printf("Enter the %d integer elements to fill up the integer array : \n\n", i_vvantArrayLength);
    for (i_vva = 0; i_vva < i_vvantArrayLength; i_vva++)
        scanf("%d", (ptr_i_vvaArray + i_vva));

   // *** FLOAT ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an float array : ");
    scanf("%u", &f_vvaloatArrayLength);

    ptr_f_vvaArray = (float *)malloc(FLOAT_SIZE * f_vvaloatArrayLength);
    if (ptr_f_vvaArray == NULL)
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
    printf("Enter the %d float elements to fill up the float array : \n\n", f_vvaloatArrayLength);
    for (i_vva = 0; i_vva < f_vvaloatArrayLength; i_vva++)
        scanf("%f", (ptr_f_vvaArray + i_vva));

    // *** DOUBLE ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an double array : ");
    scanf("%u", &d_vvaoubleArrayLength);

    ptr_d_vvaArray = (double *)malloc(DOUBLE_SIZE * d_vvaoubleArrayLength);
    if (ptr_d_vvaArray == NULL)
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
    printf("Enter the %d double elements to fill up the double array : \n\n", d_vvaoubleArrayLength);
    for (i_vva = 0; i_vva < d_vvaoubleArrayLength; i_vva++)
        scanf("%lf", (ptr_d_vvaArray + i_vva));

    
     // *** CHARACTER ARRAY ****
    printf("\n\n");
    printf("Enter the number of elements you want in an character array : ");
    scanf("%u", &c_vvaharArrayLength);

    ptr_c_vvaArray = (char *)malloc(CHAR_SIZE * c_vvaharArrayLength);
    if (ptr_c_vvaArray == NULL)
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
    printf("Enter the %d character elements to fill up the char array : \n\n", c_vvaharArrayLength);
    for (i_vva = 0; i_vva < c_vvaharArrayLength; i_vva++)
    {
        *(ptr_c_vvaArray + i_vva) = getch();
        printf("%c\n",  *(ptr_c_vvaArray + i_vva));
    }

    // **** DISPLAY OF ARRAYS ****==

    // *** INTEGER ARRAY ****
    printf("\n\n");
    printf("The integer array enterred by you and considering of %d element is as follows : \n\n", i_vvantArrayLength);
    for (i_vva = 0; i_vva < i_vvantArrayLength; i_vva++)
        printf("%d \t at address : %p\n", *(ptr_i_vvaArray + i_vva), (ptr_i_vvaArray + i_vva));


    // *** FLOAT ARRAY ****
    printf("\n\n");
    printf("The float array enterred by you and considering of %d element is as follows : \n\n", f_vvaloatArrayLength);
    for (i_vva = 0; i_vva < f_vvaloatArrayLength; i_vva++)
        printf("%f \t at address : %p\n", *(ptr_f_vvaArray + i_vva), (ptr_f_vvaArray + i_vva));
   
    // *** DOUBLE ARRAY ****
    printf("\n\n");
    printf("The double array enterred by you and considering of %d element is as follows : \n\n", d_vvaoubleArrayLength);
    for (i_vva = 0; i_vva < d_vvaoubleArrayLength; i_vva++)
        printf("%lf \t at address : %p\n", *(ptr_d_vvaArray + i_vva), (ptr_d_vvaArray + i_vva));

    // *** CHAR ARRAY ****
    printf("\n\n");
    printf("The character array enterred by you and considering of %d element is as follows : \n\n", d_vvaoubleArrayLength);
    for (i_vva = 0; i_vva < c_vvaharArrayLength; i_vva++)
        printf("%c \t at address : %p\n", *(ptr_c_vvaArray + i_vva), (ptr_c_vvaArray + i_vva));


    // *** Freeing memory occupied by arrays (in reverse order of allocation)
    if (ptr_c_vvaArray)
    {
        free(ptr_c_vvaArray);
        ptr_c_vvaArray = NULL;
        printf("\n\n");
        printf("Memory occupied by character array has been successfully freed!!!\n\n ");
    }

    if (ptr_d_vvaArray)
    {
        free(ptr_d_vvaArray);
        ptr_d_vvaArray = NULL;
        printf("\n\n");
        printf("Memory occupied by double array has been successfully freed!!!\n\n ");
    }


    if (ptr_f_vvaArray)
    {
        free(ptr_f_vvaArray);
        ptr_f_vvaArray = NULL;
        printf("\n\n");
        printf("Memory occupied by float array has been successfully freed!!!\n\n ");
    }


    if (ptr_i_vvaArray)
    {
        free(ptr_i_vvaArray);
        ptr_i_vvaArray = NULL;
        printf("\n\n");
        printf("Memory occupied by integer array has been successfully freed!!!\n\n ");
    }

    return (0);
}