#include <stdio.h>

//defining struct 
struct MyData
{
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{
    //function prototype
    
    struct MyData AddStructMembers(struct MyData, struct MyData, struct MyData);
    
    //variable declaration
    struct MyData data1_vva, data2_vva, data3_vva, answer_data_vva;

    //code
    // ** data1_vva **
    printf("\n\n\n\n");
    printf("*********** DATA 1*******\n\n");
    printf("Enter integer value 'i' of 'struct Mydata data1_vva' :  ");
    scanf("%d", &data1_vva.i);
    
    printf("\n\n");
    printf("Enter floating-point value 'f' of 'struct Mydata data1_vva' :  ");
    scanf("%f", &data1_vva.f);

    printf("\n\n");
    printf("Enter Double value 'd' of 'struct Mydata data1_vva' :  ");
    scanf("%lf", &data1_vva.d);

    printf("\n\n");
    printf("Enter character value 'c' of 'struct Mydata data1_vva' :  ");
    data1_vva.c = getch();
    printf("%c", data1_vva.c);

    // ** data2_vva **
    printf("\n\n\n\n");
    printf("*********** DATA 1*******\n\n");
    printf("Enter integer value 'i' of 'struct Mydata data2_vva' :  ");
    scanf("%d", &data2_vva.i);
    
    printf("\n\n");
    printf("Enter floating-point value 'f' of 'struct Mydata data2_vva' :  ");
    scanf("%f", &data2_vva.f);

    printf("\n\n");
    printf("Enter Double value 'd' of 'struct Mydata data2_vva' :  ");
    scanf("%lf", &data2_vva.d);

    printf("\n\n");
    printf("Enter character value 'c' of 'struct Mydata data2_vva' :  ");
    data2_vva.c = getch();
    printf("%c", data2_vva.c);


    // ** data3_vva **
    printf("\n\n\n\n");
    printf("*********** DATA 1*******\n\n");
    printf("Enter integer value 'i' of 'struct Mydata data3_vva' :  ");
    scanf("%d", &data3_vva.i);
    
    printf("\n\n");
    printf("Enter floating-point value 'f' of 'struct Mydata data3_vva' :  ");
    scanf("%f", &data3_vva.f);

    printf("\n\n");
    printf("Enter Double value 'd' of 'struct Mydata data3_vva' :  ");
    scanf("%lf", &data3_vva.d);

    printf("\n\n");
    printf("Enter character value 'c' of 'struct Mydata data3_vva' :  ");
    data3_vva.c = getch();
    printf("%c", data3_vva.c);


    // calling function 'AddStructMembers()' which accepts three variables of type 'struct MyData' as parameters and adds up the respective members and returns the answer_vva in another structure of same type
    answer_data_vva = AddStructMembers(data1_vva, data2_vva, data3_vva);

    printf("\n\n\n\n");
    printf("*************ANSWER***************\n\n");
    printf("answer_data_vva.i = %d\n", answer_data_vva.i);
    printf("answer_data_vva.i = %f\n", answer_data_vva.f);
    printf("answer_data_vva.i = %lf\n\n", answer_data_vva.d);

    answer_data_vva.c = data1_vva.c;
    printf("answer_data_vva.c (from data1_vva) = %c\n\n", answer_data_vva.c);

    answer_data_vva.c = data2_vva.c;
    printf("answer_data_vva.c (from data2_vva) = %c\n\n", answer_data_vva.c);

    answer_data_vva.c = data3_vva.c;
    printf("answer_data_vva.c (from data3_vva) = %c\n\n", answer_data_vva.c);

    return (0);
}

struct MyData AddStructMembers(struct MyData md_one_vva, struct MyData md_two_vva, struct MyData md_three_vva)
{
    //variable declaration 
    struct MyData answer_vva;

    //code
    answer_vva.i = md_one_vva.i + md_two_vva.i + md_three_vva.i;
    answer_vva.f = md_one_vva.f + md_two_vva.f + md_three_vva.f;
    answer_vva.d = md_one_vva.d + md_two_vva.d + md_three_vva.d;

    return (answer_vva);
    
}