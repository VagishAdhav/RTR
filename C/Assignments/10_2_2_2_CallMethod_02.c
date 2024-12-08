#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// **** user defined functions : method of calling function 2 ****
// **** calling only two functions directly in main(), rest of functions trace their call indirectly to main() ***

int main(int argc, char *argv[], char *envp[])
{
    // function prototypes
    void display_information(void);
    void function_country(void);

    // code
    display_information(); // function call
    function_country(); // function call

    return (0);
}

// ***** user-defined functions 
void display_information(void) // function definition
{
    // function prototype 
    void function_my(void);
    void function_name(void);
    void function_is(void);
    void function_firstname(void);
    void function_middlename(void);
    void function_surname(void);
    void function_ofAMC(void);

    //code 
    function_my();
    function_name();
    function_is();
    function_firstname();
    function_middlename();
    function_surname();
    function_ofAMC();
}

void function_my(void)// function definition 
{
    printf("\n\n");
    printf("My");
}

void function_name(void)// function definition 
{ 
    printf("\n\n");
    printf("name");
}

void function_is(void)// function definition 
{ 
    printf("\n\n");
    printf("is");
}

void function_firstname(void)// function definition 
{ 
    printf("\n\n");
    printf("Vagish");
}

void function_middlename(void)// function definition 
{ 
    printf("\n\n");
    printf("Vishvanath");
}

void function_surname(void)// function definition 
{ 
    printf("\n\n");
    printf("Adhav");
}

void function_ofAMC(void)// function definition 
{ 
    printf("\n\n");
    printf("of ASTROMEDICOMP");
}

void function_country(void) // function definition
{
    printf("\n\n");

    printf("I live in India");

    printf("\n\n");
}