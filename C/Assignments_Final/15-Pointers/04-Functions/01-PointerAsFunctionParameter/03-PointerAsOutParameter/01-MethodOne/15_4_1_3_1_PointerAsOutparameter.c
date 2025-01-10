#include <stdio.h>

int main(void)
{
    // function declaration
    void MathematicalOperations(int, int, int *, int *, int*, int *, int *);

    // variable declaration
    int a_vva;
    int b_vva;
    int answer_sum_vva;
    int answer_difference_vva;
    int answer_product_vva;
    int answer_quotient_vva;
    int answer_remainder_vva;

    //code
    printf("\n\n");
    printf("Enter value of 'A' :  ");
    scanf("%d", &a_vva);

    printf("\n\n");
    printf("Enter value of 'B' :  ");
    scanf("%d", &b_vva);

    // PASSING ADDRESSES TO FUNCTION .. FUNCTION WILL FILL THEM UP WITH VALUES...
    // HENCE THEY FO INTO FUNCTION AS ADDRESS PARAMETERS AND COME OUT OF THE FUNCTION FILLED WITH VALID VALUES
    // THUS (&answer_sum_vva, &answer_difference_vva, &answer_product_vva, &answer_quotient_vva, &answer_remainder_vva)
    // ..ARE CALLED AS OUT PARAMETERS OR PARAMETERIZED RETURN VALUE

    // HENCE, ALTHOUGH EACH FUNCTION HAS ONLY ONE RETURN VALUE, USING THE CONCEPT OF "PARAMETERIZED RETURN VALUE" OUT FUNCTION GIVES 5 RETURN VALUES
    MathematicalOperations(a_vva, b_vva, &answer_sum_vva, &answer_difference_vva, &answer_product_vva, &answer_quotient_vva, &answer_remainder_vva);

    printf("\n\n");
    printf("****** RESULTS ************: \n\n");
    printf("Sum = %d\n\n", answer_sum_vva);
    printf("Difference = %d\n\n", answer_difference_vva);
    printf("Product = %d\n\n", answer_product_vva);
    printf("quotient_vva = %d\n\n", answer_quotient_vva);
    printf("remainder_vva = %d\n\n", answer_remainder_vva);

    return (0);
}

void MathematicalOperations(int x, int y, int *sum, int *difference, int *product, int *quotient_vva, int *remainder_vva)
{
    //code
    *sum = x + y;           // Value at address 'sum' = (x + y)      
    *difference = x - y;    // Value at address 'difference' = (x - y)  
    *product = x * y;       // Value at address 'product' = (x * y)  
    *quotient_vva = x / y;      // Value at address 'quotient_vva' = (x / y)    
    *remainder_vva = x % y;     // Value at address 'remainder_vva' = (x % y)
}