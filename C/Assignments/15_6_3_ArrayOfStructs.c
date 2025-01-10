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
    struct Employee *pEmployeeRecord = NULL;
    int num_vva_employees, i;

    // code
    printf("\n\n");
    printf("Enter number of employees whose details you want to record : ");
    scanf("%d", &num_vva_employees);

    printf("\n\n");
    pEmployeeRecord = (struct Employee *)malloc(sizeof(struct Employee) * num_vva_employees);
    if (pEmployeeRecord == NULL)
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
        printf("***********DATA ENTRY FOR EMPLOYEE num_vvaBER %d *********\n", (i + 1));
        printf("\n\n");
        printf("Enter Employee Name : ");
        MyGetString(pEmployeeRecord[i].name, NAME_LENGTH);

        printf("\n\n");
        printf("Enter Employee's Age (in years) : ");
        scanf("%d", &pEmployeeRecord[i].age);

        printf("\n\n");
        printf("Enter Employee's sex (M/m for male, F/f for Female) : " );
        pEmployeeRecord[i].sex = getch();
        printf("%c", pEmployeeRecord[i].sex);
        pEmployeeRecord[i].sex = toupper(pEmployeeRecord[i].sex);

        printf("\n\n\n\n");
        printf("Enter Employee's Salary (in Indian Rupees) : ");
        scanf("%f", &pEmployeeRecord[i].salary);

        printf("\n\n");
        printf("Is the Employee Married? (Y/y for yes, N/n for No) : ");
        pEmployeeRecord[i].marital_status = getch();
        printf("%c", pEmployeeRecord[i].marital_status);
        pEmployeeRecord[i].marital_status = toupper(pEmployeeRecord[i].marital_status);

    }

    // ** DISPLAY ***
    printf("\n\n\n\n");
    printf("******* DISPLAYING EMPLOYEE RECORDS *********\n\n");
    for (i = 0; i < num_vva_employees; i++) 
    {
        printf("********* EMPLOYEE num_vvaBER %d *********\n\n", (i + 1));
        printf("Name            : %s\n", pEmployeeRecord[i].name);
        printf("Age             : %d years\n", pEmployeeRecord[i].age);

        if (pEmployeeRecord[i].sex == 'M')
            printf("Sex             : Male\n");
        else if (pEmployeeRecord[i].sex == 'F')
            printf("Sex             : Female\n");
        else
            printf("Sex             : Invalid data entered\n");

        printf("Salary          : Rs. %f\n", pEmployeeRecord[i].salary);

        if (pEmployeeRecord[i].marital_status == 'Y')
            printf("Marital           : Married\n");
        else if (pEmployeeRecord[i].marital_status == 'N')
            printf("Marital           : Unmarried\n");
        else
            printf("Marital           : Invalid data entered\n");

        printf("\n\n");
    }

    if (pEmployeeRecord)
    {
        free(pEmployeeRecord);
        pEmployeeRecord = NULL;
        printf("MEMORY ALLOCATED T0 %d EMPLOYEES HAS BEEN SUCCESSFULLY FREED !!! \n\n", num_vva_employees);
    }
    return(0);
}

// ** Simple rudimentary implementation of gets_s() ***
// ** Implemented due to different behaviour of gets_s()/fgets()/fscanf() on different platforms***
// ** backspace/character deletion and arrow cursor movement not implemented

void MyGetString(char str[], int str_size)
{
    //variable declaration
    int i;
    char ch = '\0';

    //code
    i = 0;
    do
    {
        ch = getch();
        str[i] = ch;
        printf("%c", str[i]);
        i++;
    }while((ch != '\r') && (i < str_size));

    if (i = str_size)
        str[i - 1] = '\0';
    else
        str[i] = '\0';
}