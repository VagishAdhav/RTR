#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_age;

    //code
    printf("\n\n");
    printf("Enter age : ");
    scanf("%d", &vva_age);
    if (vva_age >= 18)
    {
        printf("You are eligible for voting !!!\n\n");
    }

    return (0);
}