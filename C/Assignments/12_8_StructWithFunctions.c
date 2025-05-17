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
    struct MyData data1, data2, data3, answer_data;

    //code
    // ** data1 **
    printf("\n\n\n\n");
    printf("*********** DATA 1*******\n\n");
    printf("Enter integer value 'i' of 'struct Mydata data1' :  ");
    scanf("%d", &data1.i);
    
    printf("\n\n");
    printf("Enter floating-point value 'f' of 'struct Mydata data1' :  ");
    scanf("%f", &data1.f);

    printf("\n\n");
    printf("Enter Double value 'd' of 'struct Mydata data1' :  ");
    scanf("%lf", &data1.d);

    printf("\n\n");
    printf("Enter character value 'c' of 'struct Mydata data1' :  ");
    data1.c = getch();
    printf("%c", data1.c);

    // ** data2 **
    printf("\n\n\n\n");
    printf("*********** DATA 1*******\n\n");
    printf("Enter integer value 'i' of 'struct Mydata data2' :  ");
    scanf("%d", &data2.i);
    
    printf("\n\n");
    printf("Enter floating-point value 'f' of 'struct Mydata data2' :  ");
    scanf("%f", &data2.f);

    printf("\n\n");
    printf("Enter Double value 'd' of 'struct Mydata data2' :  ");
    scanf("%lf", &data2.d);

    printf("\n\n");
    printf("Enter character value 'c' of 'struct Mydata data2' :  ");
    data2.c = getch();
    printf("%c", data2.c);


    // ** data3 **
    printf("\n\n\n\n");
    printf("*********** DATA 1*******\n\n");
    printf("Enter integer value 'i' of 'struct Mydata data3' :  ");
    scanf("%d", &data3.i);
    
    printf("\n\n");
    printf("Enter floating-point value 'f' of 'struct Mydata data3' :  ");
    scanf("%f", &data3.f);

    printf("\n\n");
    printf("Enter Double value 'd' of 'struct Mydata data3' :  ");
    scanf("%lf", &data3.d);

    printf("\n\n");
    printf("Enter character value 'c' of 'struct Mydata data3' :  ");
    data3.c = getch();
    printf("%c", data3.c);


    // calling function 'AddStructMembers()' which accepts three variables of type 'struct MyData' as parameters and adds up the respective members and returns the answer in another structure of same type
    answer_data = AddStructMembers(data1, data2, data3);

    printf("\n\n\n\n");
    printf("*************ANSWER***************\n\n");
    printf("answer_data.i = %d\n", answer_data.i);
    printf("answer_data.i = %f\n", answer_data.f);
    printf("answer_data.i = %lf\n\n", answer_data.d);

    answer_data.c = data1.c;
    printf("answer_data.c (from data1) = %c\n\n", answer_data.c);

    answer_data.c = data2.c;
    printf("answer_data.c (from data2) = %c\n\n", answer_data.c);

    answer_data.c = data3.c;
    printf("answer_data.c (from data3) = %c\n\n", answer_data.c);

    return (0);
}

struct MyData AddStructMembers(struct MyData md_one, struct MyData md_two, struct MyData md_three)
{
    //variable declaration 
    struct MyData answer;

    //code
    answer.i = md_one.i + md_two.i + md_three.i;
    answer.f = md_one.f + md_two.f + md_three.f;
    answer.d = md_one.d + md_two.d + md_three.d;

    return (answer);
    
}