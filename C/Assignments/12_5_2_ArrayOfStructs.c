#include <stdio.h>

#define num_vva_EMPLOYEES 5 // simply change this constant value to have as many as number of employee records as you please..

#define NAME_LENGTH 100

struct Employee
{
    char name[NAME_LENGTH];
    int age;
    float salary;
    char sex;
    char marital_status;
};

int main(void)
{

    // function prototype
    void MyGetString(char[], int);

    // variable declarations
    struct Employee vva_EmployeeRecord[num_vva_EMPLOYEES]; // Array of num_vva_EMPLOYEES structs of type struct Employee

    int i_vva;

    //code
    // *** User input initialization of array of struct Employee ****
    for (i_vva = 0; i_vva < num_vva_EMPLOYEES; i_vva++)
    {
        printf("\n\n\n\n");
        printf("********** DATA ENTRY FOR EMPLOYEE num_vvaBER %d ******\n", (i_vva + 1));

        printf("\n\n");
        printf("Enter Employee's Name : ");
        MyGetString(vva_EmployeeRecord[i_vva].name, NAME_LENGTH);

        printf("\n\n");
        printf("Enter Employee's Age (in years) : ");
        scanf("%d", &vva_EmployeeRecord[i_vva].age);

        printf("\n\n");
        printf("Enter Employee's sex (M/m for male, F/f for Female) : " );
        vva_EmployeeRecord[i_vva].sex = getch();
        printf("%c", vva_EmployeeRecord[i_vva].sex);
        vva_EmployeeRecord[i_vva].sex = toupper(vva_EmployeeRecord[i_vva].sex);

        printf("\n\n\n\n");
        printf("Enter Employee's Salary (in Indian Rupees) : ");
        scanf("%f", &vva_EmployeeRecord[i_vva].salary);

        printf("\n\n");
        printf("Is the Employee married? (Y/y for yes, N/n for No) : ");
        vva_EmployeeRecord[i_vva].marital_status = getch();
        printf("%c", vva_EmployeeRecord[i_vva].marital_status);
        vva_EmployeeRecord[i_vva].marital_status = toupper(vva_EmployeeRecord[i_vva].marital_status);
    }

    // ** DISPLAY ***
    printf("\n\n\n\n");
    printf("******* DISPLAYING EMPLOYEE RECORD *********\n\n");
    for (i_vva = 0; i_vva < num_vva_EMPLOYEES; i_vva++)
    {
        printf("********* EMPLOYEE num_vvaBER %d *********\n\n", (i_vva + 1));
        printf("Name            : %s\n", vva_EmployeeRecord[i_vva].name);
        printf("Age             : %d years\n", vva_EmployeeRecord[i_vva].age);

        if (vva_EmployeeRecord[i_vva].sex == 'M')
            printf("Sex             : Male\n");
        else if (vva_EmployeeRecord[i_vva].sex == 'F')
            printf("Sex             : Female\n");
        else
            printf("Sex             : Invalid data entered\n");

        printf("Salary          : Rs. %f\n", vva_EmployeeRecord[i_vva].salary);

        if (vva_EmployeeRecord[i_vva].marital_status == 'Y')
            printf("Marital           : Married\n");
        else if (vva_EmployeeRecord[i_vva].marital_status == 'N')
            printf("Marital           : Unmarried\n");
        else
            printf("Marital             : Invalid data entered\n");

        printf("\n\n");
    }

    return (0);
}

// ** Simple implementation of gets_s() ***
// ** Implemented due to different behaviour of gets_s()/fgets()/fscanf() on different platforms***
// ** backspace/character deletion and arrow cursor movement not implemented

void MyGetString(char str[], int str_size)
{
    //variable declaration
    int i_vva;
    char c_vvah = '\0';

    //code
    i_vva = 0;
    do
    {
        c_vvah = getch();
        str[i_vva] = c_vvah;
        printf("%c", str[i_vva]);
        i_vva++;
    }while((c_vvah != '\r') && (i_vva < str_size));

    if (i_vva = str_size)
        str[i_vva - 1] = '\0';
    else
        str[i_vva] = '\0';
}