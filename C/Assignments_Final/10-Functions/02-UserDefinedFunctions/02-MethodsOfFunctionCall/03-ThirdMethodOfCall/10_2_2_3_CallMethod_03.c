#include <stdio.h> // 'stdio.h' contains declaration of 'printf()'

// **** user defined functions : method of calling function 2 ****
// **** calling only two functions directly in main(), rest of functions trace their call indirectly to main() ***

int main(int argc, char *argv[], char *envp[])
{
    // function prototypes
    void function_country(void);

    // code
    function_country(); // function call

    return (0);
}

// ***** user-defined functions 

void function_country(void) // function definition
{
    //function declaration 
    void function_ofAMC(void);

    // code 
    function_ofAMC();

    printf("\n\n");

    printf("I live in India");

    printf("\n\n");
}

void function_ofAMC(void)// function definition 
{ 
    //function declaration 
    void function_surname(void);

    //code
    function_surname();
    printf("\n\n");
    printf("of ASTROMEDICOMP");
}

void function_surname(void)// function definition 
{ 
    //function declaration 
    void function_middlename(void);

    //code
    function_middlename();
    printf("\n\n");
    printf("Adhav");
}

void function_middlename(void)// function definition 
{
    // function declaration 
    void function_firstname(void);

    //code
    function_firstname(); 
    printf("\n\n");
    printf("Vishvanath");
}

void function_firstname(void)// function definition 
{ 
    // function declarations
    void function_is(void);

    //code
    function_is();
    printf("\n\n");
    printf("Vagish");
}

void function_is(void)// function definition 
{
    // function declaration
    void function_name(void);

    //code
    function_name();
    printf("\n\n");
    printf("is");
}

void function_name(void)// function definition 
{
    // function declaration 
    void function_my(void);

    //code
    function_my();
    printf("\n\n");
    printf("name");
}


void function_my(void)// function definition 
{
    //code
    printf("\n\n");
    printf("My");
}
