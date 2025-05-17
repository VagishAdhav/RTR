#include <stdio.h>

int main(void){
    int a[5] = {1, 2, 3, 4, 5};  

    int *p = &a;
    printf("address of a[0] = %p\n", &a[0]);
    printf("address of a[] = %p\n", &a);
    int (*ptr)[5] = &a;
    printf("address of a[0] = %p\n", &ptr[0]);
    printf("address of a[] = %p\n", ptr);
    printf("address of ptr = %p\n", ptr);
    //printf("address of ++ptr = %p\n", ++ptr);

    printf("address of (*ptr)[0] = %d\n", (*ptr)[0]);
    //printf("address of (ptr)[0] = %d\n", ptr)[0]);



    return (0);
}