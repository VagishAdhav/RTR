#include <stdio.h>

#define MAX_NAME_LENGTH 100

struct Employee
{
    char name[MAX_NAME_LENGTH];
    unsigned int age;
    char gender;
    double salary;
};

struct MyData
{
    int i;
    float f;
    double d;
    char c;
};

int main(void)
{
    //typedefs 
    typedef struct Employee MY_EMPLOYEE_TYPE;
    typedef struct MyData MY_DATA_TYPE;

    // variable declarations
    struct Employee emp_vva = {"Funny", 25, 'M', 10000.00};
    MY_EMPLOYEE_TYPE emp_typedef_vva = {"Bunny", 23, 'F', 20400.00};

    struct MyData md_vva = {30, 11.45f, 26.122017, 'X'};
    MY_DATA_TYPE md_typedef_vva;

    //code
    
    md_typedef_vva.i = 9;
    md_typedef_vva.f = 1.5f;
    md_typedef_vva.d = 8.041997;
    md_typedef_vva.c = 'P';

    printf("\n\n");
    printf("strut Employee : \n\n");
    printf("emp_vva.name = %s\n", emp_vva.name);
    printf("emp_vva.age = %d\n", emp_vva.age);
    printf("emp_vva.gender = %c\n", emp_vva.gender);
    printf("emp_vva.salary = %lf\n", emp_vva.salary);

    printf("\n\n");
    printf("MY_EMPLOYEE_TYPE: \n\n");
    printf("emp_typedef_vva.name = %s\n", emp_typedef_vva.name);
    printf("emp_typedef_vva.age = %d\n", emp_typedef_vva.age);
    printf("emp_typedef_vva.gender = %c\n", emp_typedef_vva.gender);
    printf("emp_typedef_vva.salary = %lf\n", emp_typedef_vva.salary);

    printf("\n\n");
    printf("struct MyData : \n\n");
    printf("md_vva.i %d\n", md_vva.i);
    printf("md_vva.f %f\n", md_vva.f);
    printf("md_vva.d %lf\n", md_vva.d);
    printf("md_vva.c %c\n", md_vva.c);
    
    
    printf("\n\n");
    printf("MY_DATA_TYPE : \n\n");
    printf("md_typedef_vva.i %d\n", md_typedef_vva.i);
    printf("md_typedef_vva.f %f\n", md_typedef_vva.f);
    printf("md_typedef_vva.d %lf\n", md_typedef_vva.d);
    printf("md_typedef_vva.c %c\n", md_typedef_vva.c);

    printf("\n\n");
    
    return (0);

}