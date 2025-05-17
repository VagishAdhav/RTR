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
    // variable declaration
    // 35 will be assigned to 'i' of 'data_vva_one'
    // 3.9 will be assigned to 'f' of 'data_vva_one'
    // 1.23765 will be assigned to 'd' of 'data_vva_one'
    // 'A' will be assigned to 'c' of 'data_vva_one'
    struct MyData data_vva_one = {35, 3.9, 1.23765, 'A'}; //inline initialisation

    // 'P' will be assigned to 'i' of 'data_vva_two'.. but 'P 'is character and 'i' is integer .. so 'P' is treated as its decimal integer ASCII value (80)
    // 6.2 will be assigned to 'f' of 'data_vva_two'
    // 12.199523 will be assigned to 'd' of 'data_vva_one'
    // 68 will be assigned to 'c' of 'data_vva_two' which is equivalent to ASCII 'D'
    struct MyData data_vva_two = {'P', 6.2, 12.199523, 68}; //inline initialisation

    // 36 will be assigned to 'i of 'data_vva_three'
    // ASCII equivalent of 'G' i.e. 71 is assigned to 'f'
    // rest elements are initialised to 0
    struct MyData data_vva_three = {36, 'G'};

    // 79 will be assigned to 'i' of data_four
    // rest elements will be initialised to 0
    struct MyData data_vva_four = { 79 }; //inline initialisation

    //code
    // displaying values of the data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata data_vva_one' ARE : \n\n");
    printf("i = %d\n", data_vva_one.i);
    printf("f = %f\n", data_vva_one.f);
    printf("d = %lf\n", data_vva_one.d);
    printf("c = %c\n", data_vva_one.c);
    
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata data_vva_two' ARE : \n\n");
    printf("i = %d\n", data_vva_two.i);
    printf("f = %f\n", data_vva_two.f);
    printf("d = %lf\n", data_vva_two.d);
    printf("c = %c\n", data_vva_two.c);
    
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata data_vva_three' ARE : \n\n");
    printf("i = %d\n", data_vva_three.i);
    printf("f = %f\n", data_vva_three.f);
    printf("d = %lf\n", data_vva_three.d);
    printf("c = %c\n", data_vva_three.c);
    
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata data_vva_four' ARE : \n\n");
    printf("i = %d\n", data_vva_four.i);
    printf("f = %f\n", data_vva_four.f);
    printf("d = %lf\n", data_vva_four.d);
    printf("c = %c\n", data_vva_four.c);
    
    return (0);

}