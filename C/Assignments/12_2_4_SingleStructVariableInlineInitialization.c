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
    // 35 will be assigned to 'i' of 'd_vvaata_one'
    // 3.9 will be assigned to 'f' of 'd_vvaata_one'
    // 1.23765 will be assigned to 'd' of 'd_vvaata_one'
    // 'A' will be assigned to 'c' of 'd_vvaata_one'
    struct MyData d_vvaata_one = {35, 3.9, 1.23765, 'A'}; //inline initialisation

    // 'P' will be assigned to 'i' of 'd_vvaata_two'.. but 'P 'is character and 'i' is integer .. so 'P' is treated as its decimal integer ASCII value (80)
    // 6.2 will be assigned to 'f' of 'd_vvaata_two'
    // 12.199523 will be assigned to 'd' of 'd_vvaata_one'
    // 68 will be assigned to 'c' of 'd_vvaata_two' which is equivalent to ASCII 'D'
    struct MyData d_vvaata_two = {'P', 6.2, 12.199523, 68}; //inline initialisation

    // 36 will be assigned to 'i of 'd_vvaata_three'
    // ASCII equivalent of 'G' i.e. 71 is assigned to 'f'
    // rest elements are initialised to 0
    struct MyData d_vvaata_three = {36, 'G'};

    // 79 will be assigned to 'i' of data_four
    // rest elements will be initialised to 0
    struct MyData d_vvaata_four = { 79 }; //inline initialisation

    //code
    // displaying values of the data members of struct MyData
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata d_vvaata_one' ARE : \n\n");
    printf("i = %d\n", d_vvaata_one.i);
    printf("f = %f\n", d_vvaata_one.f);
    printf("d = %lf\n", d_vvaata_one.d);
    printf("c = %c\n", d_vvaata_one.c);
    
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata d_vvaata_two' ARE : \n\n");
    printf("i = %d\n", d_vvaata_two.i);
    printf("f = %f\n", d_vvaata_two.f);
    printf("d = %lf\n", d_vvaata_two.d);
    printf("c = %c\n", d_vvaata_two.c);
    
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata d_vvaata_three' ARE : \n\n");
    printf("i = %d\n", d_vvaata_three.i);
    printf("f = %f\n", d_vvaata_three.f);
    printf("d = %lf\n", d_vvaata_three.d);
    printf("c = %c\n", d_vvaata_three.c);
    
    printf("\n\n");
    printf("DATA MEMBERS of 'struct Mydata d_vvaata_four' ARE : \n\n");
    printf("i = %d\n", d_vvaata_four.i);
    printf("f = %f\n", d_vvaata_four.f);
    printf("d = %lf\n", d_vvaata_four.d);
    printf("c = %c\n", d_vvaata_four.c);
    
    return (0);

}