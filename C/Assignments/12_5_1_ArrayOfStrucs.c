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
    struct Employee vva_EmployeeRecord[5]; // Array of 5 structs of type struct Employee

    char employee_rajesh[] = "Rajesh";
    char employee_sameer[] = "Sameer";
    char employee_kalyani[] = "Kalyani";
    char employee_sonali[] = "Sonali";
    char employee_shantanu[] = "Shantanu";

    int i_vva;

    //code
    // *** HARD-CODED INITIALIZATION OF ARRAY OF 'struct Employee' ****

    // **** EMPLOYEE 1 *********
    strcpy(vva_EmployeeRecord[0].name, employee_rajesh);
    vva_EmployeeRecord[0].age = 30;
    vva_EmployeeRecord[0].sex = 'M';
    vva_EmployeeRecord[0].salary = 50000.0f;
    strcpy(vva_EmployeeRecord[0].marital_status, "Unmarried");


    // **** EMPLOYEE 2 *********
    strcpy(vva_EmployeeRecord[1].name, employee_sameer);
    vva_EmployeeRecord[1].age = 32;
    vva_EmployeeRecord[1].sex = 'M';
    vva_EmployeeRecord[1].salary = 60000.0f;
    strcpy(vva_EmployeeRecord[1].marital_status, "Married");

    // **** EMPLOYEE 3 *********
    strcpy(vva_EmployeeRecord[2].name, employee_kalyani);
    vva_EmployeeRecord[2].age = 29;
    vva_EmployeeRecord[2].sex = 'F';
    vva_EmployeeRecord[2].salary = 62000.0f;
    strcpy(vva_EmployeeRecord[2].marital_status, "Unmarried");

        // **** EMPLOYEE 4 *********
    strcpy(vva_EmployeeRecord[3].name, employee_sonali);
    vva_EmployeeRecord[3].age = 33;
    vva_EmployeeRecord[3].sex = 'F';
    vva_EmployeeRecord[3].salary = 50000.0f;
    strcpy(vva_EmployeeRecord[3].marital_status, "Married");

        // **** EMPLOYEE 5 *********
    strcpy(vva_EmployeeRecord[4].name, employee_shantanu);
    vva_EmployeeRecord[4].age = 35;
    vva_EmployeeRecord[4].sex = 'M';
    vva_EmployeeRecord[4].salary = 55000.0f;
    strcpy(vva_EmployeeRecord[4].marital_status, "Married");

    // ** DISPLAY ***
    printf("\n\n");
    printf("******* DISPLAYING EMPLOYEE RECORD *********\n\n");
    for (i_vva = 0; i_vva < 5; i_vva++)
    {
        printf("********* EMPLOYEE num_vvaBER %d *********\n\n", (i_vva + 1));
        printf("Name            : %s\n", vva_EmployeeRecord[i_vva].name);
        printf("Age             : %d years\n", vva_EmployeeRecord[i_vva].age);

        if (vva_EmployeeRecord[i_vva].sex == 'M' || vva_EmployeeRecord[i_vva].sex == 'm')
            printf("Sex             : Male\n");
        else
            printf("Sex             : Female\n");

        printf("Salary          : Rs. %f\n", vva_EmployeeRecord[i_vva].salary);
        printf("Marital Status : %s\n", vva_EmployeeRecord[i_vva].marital_status);

        printf("\n\n");
    }

    return (0);
}