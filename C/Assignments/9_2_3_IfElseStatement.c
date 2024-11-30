#include <stdio.h>

int main(void)
{
    //variable declaration
    int vva_num;

    //code
    printf("Enter value for 'num' : ");
    scanf("%d", &vva_num);

    if (vva_num < 0) // If - 01
    {
        printf("Num = %d is less than 0 (NEGATIVE) !!!\n\n", vva_num);
    }
    else // else - 01
    {
        if ((vva_num > 0) && (vva_num <= 100)) // if - 02
        {
            printf("Num = %d is between 0 and 100 !!!\n\n", vva_num);
        }
        else // else 02
        {
            if ((vva_num > 100) && (vva_num <= 200)) // if - 03
            {
                printf("Num = %d is between 100 and 200 !!! \n\n", vva_num);
            }
            else // else 03
            {
                if ((vva_num > 200) && (vva_num <= 300)) // if - 04
                {
                    printf("Num = %d is between 200 and 300 !!! \n\n", vva_num);
                }
                else // else - 04
                {
                    if ((vva_num > 300) && (vva_num <= 400)) // if - 05
                    {
                        printf("Num = %d is between 300 and 400 !!! \n\n", vva_num);
                    }
                    else // else - 05
                    {
                        if ((vva_num > 400) && (vva_num <= 500)) // if - 06
                        {
                            printf("Num = %d is between 400 and 500 !!! \n\n", vva_num);
                        }
                        else
                        {
                            printf("Num = %d is greater than 500 !!! \n\n", vva_num);
                        } // closing brace of else 06
                    } // closing brace of else 05
                } // closing brace of else 04 
            } // closing brace of else 03
        } // closing brace of else 02
    } // closing brace of else 01
    return (0);
}