#include <stdio.h>

int main(void)
{
    int arr[4]  = {1, 2, 34, 5};
    char *c = "Hello";
    
    int *ptr = arr;
    int *dptr = &ptr;
    int *aptr = &arr;   // (&arr == arr)
// 



    char *cptr = (char *)arr;
    // printf("sizeof(ptr) : %zd\n", sizeof(ptr));
    // printf("sizeof(cptr) : %zd\n", sizeof(cptr));
    // printf("sizeof(cptr) : %zd\n", sizeof(cptr));
    // printf("ptr : %p \n", ptr);
    // printf("&a[0] : %p \n", &arr[0]);
    // printf("a : %p \n", arr);
    // printf("*(ptr + 2) : %d\n", *(ptr + 2));
    // printf("ptr : %p \n", ptr);

    // ptr++; // ptr = ptr + 1;
    // ptr++;
    // printf("*(ptr) : %d\n", *(ptr));

    // printf("ptr : %p \n", ptr);
    // ptr = ptr - 1;
    // printf("*(ptr) : %d\n", *(ptr));

    // printf("ptr : %p \n", ptr);

    // ptr = ptr + 30000;
    // printf("ptr = ptr + 3;\n");
    // printf("*(ptr) : %d\n", *(ptr));

    // printf("ptr : %p \n", ptr);

    //printf("**dptr : %d\n", **dptr);

    printf("aptr : %p \n", ptr);

    printf("*aptr : %d\n", *aptr);

    printf("aptr[0] : %d\n", aptr[0]);
    printf("aptr[1] : %d\n", aptr[1]);


    return (0);
}