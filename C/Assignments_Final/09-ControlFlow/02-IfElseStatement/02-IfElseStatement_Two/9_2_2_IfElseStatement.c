#include <stdio.h>

int main(void)
{
    //variable declaration
    int age_vva;

    //code
    printf("\n\n");
    printf("Enter age : ");
    scanf("%d", &age_vva);
    printf("\n\n");
    if (age_vva >= 18)
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