#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_age;

    //code
    printf("\n\n");
    printf("Enter age : ");
    scanf("%d", &vva_age);
    printf("\n\n");
    if (vva_age >= 18)
    {
        printf("Entering if-block...\n\n");
        printf("You are eligible for voting !!!\n\n");
    }
    else
    {
        printf("Entering else-block..\n\n");
        printf("You are NOT eligible for voting !!!\n\n");
    }
    printf("Bye !!!\n\n");
    return (0);
}