#include <stdio.h>

int main(void)
{
    //variable declaration
    int num_vva;

    //code
    printf("Enter value for 'num_vva' : ");
    scanf("%d", &num_vva);

    if (num_vva < 0) // If - 01
    {
        printf("num_vva = %d is less than 0 (NEGATIVE) !!!\n\n", num_vva);
    }
    else // else - 01
    {
        if ((num_vva > 0) && (num_vva <= 100)) // if - 02
        {
            printf("num_vva = %d is between 0 and 100 !!!\n\n", num_vva);
        }
        else // else 02
        {
            if ((num_vva > 100) && (num_vva <= 200)) // if - 03
            {
                printf("num_vva = %d is between 100 and 200 !!! \n\n", num_vva);
            }
            else // else 03
            {
                if ((num_vva > 200) && (num_vva <= 300)) // if - 04
                {
                    printf("num_vva = %d is between 200 and 300 !!! \n\n", num_vva);
                }
                else // else - 04
                {
                    if ((num_vva > 300) && (num_vva <= 400)) // if - 05
                    {
                        printf("num_vva = %d is between 300 and 400 !!! \n\n", num_vva);
                    }
                    else // else - 05
                    {
                        if ((num_vva > 400) && (num_vva <= 500)) // if - 06
                        {
                            printf("num_vva = %d is between 400 and 500 !!! \n\n", num_vva);
                        }
                        else
                        {
                            printf("num_vva = %d is greater than 500 !!! \n\n", num_vva);
                        } // closing brace of else 06
                    } // closing brace of else 05
                } // closing brace of else 04 
            } // closing brace of else 03
        } // closing brace of else 02
    } // closing brace of else 01
    return (0);
}