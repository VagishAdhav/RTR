#include <stdio.h>
#include <conio.h>

struct MyData
{
    int i;
    float f;
    double d;
    char ch;
};


int main(void)
{
    // variable declaration
    struct MyData data; //declaring a single struct variable

    //code 
    // User input for values of data members of 'struct Mydata'
    printf("\n\n");

    printf("Enter integer value for data members 'i' of 'struct MyData' : \n");
    scanf("%d", &data.i);

    printf("Enter floating-point value for data members 'f' of 'struct MyData' : \n");
    scanf("%f", &data.f);

    printf("Enter 'Double' value for data members 'd' of 'struct MyData' : \n");
    scanf("%lf", &data.d);

    printf("Enter character value for data members 'ch' of 'struct MyData' : \n");
    data.ch = getch();

    // Display value of data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata' ARE : \n\n");
    printf("i = %d\n", data.i);
    printf("f = %f\n", data.f);
    printf("d = %lf\n", data.d);
    printf("ch = %c\n", data.ch);

    return (0);
}