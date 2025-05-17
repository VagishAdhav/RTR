#include <stdio.h>

int main(void)
{
    // variabkle declarations
    int a_vva;
    int b_vva;
    int c_vva;
    int result_vva;

    //code
    printf("\n\n");
    printf("Enter first integer : ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter second integer : ");
    scanf("%d", &b_vva);

    printf("\n\n");
    printf("Enter third integer : ");
    scanf("%d", &c_vva);

    printf("\n\n");
    printf("If answer = 0, is is 'FALSE'\n");
    printf("If answer = 1, is is 'TRUE'\n\n");

    result_vva = (a_vva <= b_vva) && (b_vva != c_vva);
    printf("Logical AND (&&) : Answer is TRUE(1) if and only if both conditions are true. The answer is FALSE if any or both conditions are false\n\n");
    printf("A = %d is less than or equal to B = %d AND  B = %d is not equal to C = %d \t Answer = %d\n\n", a_vva, b_vva, b_vva, c_vva, result_vva);

    result_vva = (b_vva >= a_vva) || (a_vva == c_vva);
    printf("Logical OR (||) : Answer is TRUE(1) if any of the condition is true. The answer is FALSE if both conditions are false\n\n");
    printf("Either B = %d is greater than or equal to A = %d OR A = %d is equal to C = %d \t Answer = %d\n\n", b_vva, a_vva, a_vva, c_vva, result_vva);

    result_vva = !a_vva;
    printf("A = %d and using logical NOT (!) operator on a_vva gives result = %d\n\n", a_vva, result_vva);

    result_vva = !b_vva;
    printf("B = %d and using logical NOT (!) operator on a_vva gives result = %d\n\n", b_vva, result_vva);

    result_vva = !c_vva;
    printf("C = %d and using logical NOT (!) operator on a_vva gives result = %d\n\n", c_vva, result_vva);
    
    result_vva = (!(a_vva <= b_vva) && !(b_vva != c_vva));
    printf("Using logical NOT (!) on (a_vva <= b_vva) and also (a_vva != b_vva) and then ANDing them afterwords gives result = %d\n", result_vva);
    
    printf("\n\n");

    result_vva = !((b_vva >= a_vva) || (a_vva == c_vva));
    printf("Using logical NOT (!) on entire logical expession (b_vva >= a_vva) || (a_vva == c_vva) gives result = %d\n", result_vva);

    printf("\n\n");

    return(0);
  
}