#include <stdio.h>

int main(void)
{
    //variable declaration
    int age_vva;

    //code
    printf("\n\n");
    printf("Enter age : ");
    scanf("%d", &age_vva);
    if (age_vva >= 18)
    {
        printf("You are eligible for voting !!!\n\n");
    }

    return (0);
}