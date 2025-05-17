#include <stdio.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
    char name[NAME_LENGTH];
    int age;
    float salary;
    char sex;
    char marital_status[MARITAL_STATUS];
};

int main(void)
{
    // variable declarations
    struct Employee EmployeeRecord_vva[5]; // Array of 5 structs of type struct Employee

    char employee_rajesh[] = "Rajesh";
    char employee_sameer[] = "Sameer";
    char employee_kalyani[] = "Kalyani";
    char employee_sonali[] = "Sonali";
    char employee_shantanu[] = "Shantanu";

    int i_vva;

    //code
    // *** HARD-CODED INITIALIZATION OF ARRAY OF 'struct Employee' ****

    // **** EMPLOYEE 1 *********
    strcpy(EmployeeRecord_vva[0].name, employee_rajesh);
    EmployeeRecord_vva[0].age = 30;
    EmployeeRecord_vva[0].sex = 'M';
    EmployeeRecord_vva[0].salary = 50000.0f;
    strcpy(EmployeeRecord_vva[0].marital_status, "Unmarried");


    // **** EMPLOYEE 2 *********
    strcpy(EmployeeRecord_vva[1].name, employee_sameer);
    EmployeeRecord_vva[1].age = 32;
    EmployeeRecord_vva[1].sex = 'M';
    EmployeeRecord_vva[1].salary = 60000.0f;
    strcpy(EmployeeRecord_vva[1].marital_status, "Married");

    // **** EMPLOYEE 3 *********
    strcpy(EmployeeRecord_vva[2].name, employee_kalyani);
    EmployeeRecord_vva[2].age = 29;
    EmployeeRecord_vva[2].sex = 'F';
    EmployeeRecord_vva[2].salary = 62000.0f;
    strcpy(EmployeeRecord_vva[2].marital_status, "Unmarried");

        // **** EMPLOYEE 4 *********
    strcpy(EmployeeRecord_vva[3].name, employee_sonali);
    EmployeeRecord_vva[3].age = 33;
    EmployeeRecord_vva[3].sex = 'F';
    EmployeeRecord_vva[3].salary = 50000.0f;
    strcpy(EmployeeRecord_vva[3].marital_status, "Married");

        // **** EMPLOYEE 5 *********
    strcpy(EmployeeRecord_vva[4].name, employee_shantanu);
    EmployeeRecord_vva[4].age = 35;
    EmployeeRecord_vva[4].sex = 'M';
    EmployeeRecord_vva[4].salary = 55000.0f;
    strcpy(EmployeeRecord_vva[4].marital_status, "Married");

    // ** DISPLAY ***
    printf("\n\n");
    printf("******* DISPLAYING EMPLOYEE RECORD *********\n\n");
    for (i_vva = 0; i_vva < 5; i_vva++)
    {
        printf("********* EMPLOYEE NUMBER %d *********\n\n", (i_vva + 1));
        printf("Name            : %s\n", EmployeeRecord_vva[i_vva].name);
        printf("Age             : %d years\n", EmployeeRecord_vva[i_vva].age);

        if (EmployeeRecord_vva[i_vva].sex == 'M' || EmployeeRecord_vva[i_vva].sex == 'm')
            printf("Sex             : Male\n");
        else
            printf("Sex             : Female\n");

        printf("Salary          : Rs. %f\n", EmployeeRecord_vva[i_vva].salary);
        printf("Marital Status : %s\n", EmployeeRecord_vva[i_vva].marital_status);

        printf("\n\n");
    }

    return (0);
}