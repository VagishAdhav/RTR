#include <stdio.h>
#include <stdlib.h>

//defining structs
struct MyData
{
    int *ptr_i;
    int i;

    float *ptr_f;
    float f;

    double *ptr_d;
    double d;
};

int main(void)
{
    // variable declaration
    struct MyData *pData_vva = NULL;

    // code
    printf("\n\n");
    pData_vva = (struct MyData *)malloc(sizeof(struct MyData));
    if (pData_vva == NULL)
    {
        printf("FAILED ALLOCATE MEMORY TO struct MyData !!! EXITING NOW ... \n\n");
        exit (0);
    }
    else
    {
        printf("SUCCESSFULLY ALLOCATED MEMORY TO struct MyData !!!\n\n");
    }

    (*pData_vva).i = 9;
    (*pData_vva).ptr_i = &(*pData_vva).i;

    (*pData_vva).f = 11.45f;
    (*pData_vva).ptr_f = &(*pData_vva).f;

    (*pData_vva).d = 30.121995;
    (*pData_vva).ptr_d = &(*pData_vva).d;

    printf("\n\n");
    printf("i = %d\n", *((*pData_vva).ptr_i));
    printf("Address of 'i' = %p \n", (*pData_vva).ptr_i);

    printf("\n\n");
    printf("f = %f\n", *((*pData_vva).ptr_f));
    printf("Address of 'f' = %p \n", (*pData_vva).ptr_f);

    printf("\n\n");
    printf("d = %lf\n", *((*pData_vva).ptr_d));
    printf("Address of 'd' = %p \n", (*pData_vva).ptr_d);

    if (pData_vva)
    {
        free(pData_vva);
        pData_vva = NULL;
        printf("MEMORY ALLOCATED TO struct MyData HAS BEEN SUCCESSFULLY FREED !!!\n\n");
    }

    return (0);
}