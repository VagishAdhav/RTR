#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define NAME_LENGTH 100
#define MARITAL_STATUS 10

struct Employee
{
    char name[NAME_LENGTH];
    int age;
    char sex;
    float salary;
    char marital_status;
};

int main(void)
{
    // function prototype
    void MyGetString(char[], int);

    // variable declaration
    struct Employee *pEmployeeRecord_vva = NULL;
    int num_vva_employees, i;

    // code
    printf("\n\n");
    printf("Enter number of employees whose details you want to record : ");
    scanf("%d", &num_vva_employees);

    printf("\n\n");
    pEmployeeRecord_vva = (struct Employee *)malloc(sizeof(struct Employee) * num_vva_employees);
    if (pEmployeeRecord_vva == NULL)
    {
        printf("FAILED TO ALLOCATE MEMORY FOR %d EMPLOYEES !!! EXITING NOW ...\n\n", num_vva_employees);
        exit(0);
    }
    else
    {
        printf("SUCCESSFULLY ALLOCATED MEMORY FOR %d EMPLOYEES !!!\n\n", num_vva_employees);
    }

    // **** USER INPUT INITIALIZATION OF ARRAY OF struct Employee ****
    for (i = 0; i < num_vva_employees; i++)
    {
        printf("\n\n\n\n");
        printf("***********DATA ENTRY FOR EMPLOYEE NUMBER %d *********\n", (i + 1));
        printf("\n\n");
        printf("Enter Employee Name : ");
        MyGetString(pEmployeeRecord_vva[i].name, NAME_LENGTH);

        printf("\n\n");
        printf("Enter Employee's Age (in years) : ");
        scanf("%d", &pEmployeeRecord_vva[i].age);

        printf("\n\n");
        printf("Enter Employee's sex (M/m for male, F/f for Female) : " );
        pEmployeeRecord_vva[i].sex = getch();
        printf("%c", pEmployeeRecord_vva[i].sex);
        pEmployeeRecord_vva[i].sex = toupper(pEmployeeRecord_vva[i].sex);

        printf("\n\n\n\n");
        printf("Enter Employee's Salary (in Indian Rupees) : ");
        scanf("%f", &pEmployeeRecord_vva[i].salary);

        printf("\n\n");
        printf("Is the Employee Married? (Y/y for yes, N/n for No) : ");
        pEmployeeRecord_vva[i].marital_status = getch();
        printf("%c", pEmployeeRecord_vva[i].marital_status);
        pEmployeeRecord_vva[i].marital_status = toupper(pEmployeeRecord_vva[i].marital_status);

    }

    // ** DISPLAY ***
    printf("\n\n\n\n");
    printf("******* DISPLAYING EMPLOYEE RECORDS *********\n\n");
    for (i = 0; i < num_vva_employees; i++) 
    {
        printf("********* EMPLOYEE NUMBER %d *********\n\n", (i + 1));
        printf("Name            : %s\n", pEmployeeRecord_vva[i].name);
        printf("Age             : %d years\n", pEmployeeRecord_vva[i].age);

        if (pEmployeeRecord_vva[i].sex == 'M')
            printf("Sex             : Male\n");
        else if (pEmployeeRecord_vva[i].sex == 'F')
            printf("Sex             : Female\n");
        else
            printf("Sex             : Invalid data entered\n");

        printf("Salary          : Rs. %f\n", pEmployeeRecord_vva[i].salary);

        if (pEmployeeRecord_vva[i].marital_status == 'Y')
            printf("Marital           : Married\n");
        else if (pEmployeeRecord_vva[i].marital_status == 'N')
            printf("Marital           : Unmarried\n");
        else
            printf("Marital           : Invalid data entered\n");

        printf("\n\n");
    }

    if (pEmployeeRecord_vva)
    {
        free(pEmployeeRecord_vva);
        pEmployeeRecord_vva = NULL;
        printf("MEMORY ALLOCATED T0 %d EMPLOYEES HAS BEEN SUCCESSFULLY FREED !!! \n\n", num_vva_employees);
    }
    return(0);
}

// ** Simple rudimentary implementation of gets_s() ***
// ** Implemented due to different behaviour of gets_s()/fgets()/fscanf() on different platforms***
// ** backspace/character deletion and arrow cursor movement not implemented

void MyGetString(char str_vva[], int str_size_vva)
{
    //variable declaration
    int i;
    char ch = '\0';

    //code
    i = 0;
    do
    {
        ch = getch();
        str_vva[i] = ch;
        printf("%c", str_vva[i]);
        i++;
    }while((ch != '\r') && (i < str_size_vva));

    if (i == str_size_vva)
        str_vva[i - 1] = '\0';
    else
        str_vva[i] = '\0';
}