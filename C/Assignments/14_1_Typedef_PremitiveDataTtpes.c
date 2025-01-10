#include <stdio.h>

//global typedef 
typedef int MY_INT; // type 'int' has been redefined as MY_INT, now MY_INT can be treated just like  integer


int main(void)
{
    // function prototype 
    MY_INT Add(MY_INT, MY_INT);

    //Typedefs 
    typedef int MY_INT; // type 'int' has been redefined as MY_INT, now MY_INT can be treated just like  integer
    typedef float PVG_FLOAT; // type 'float' has been redefined as PVG_FLOAT, now PVG_FLOAT can be treated just like float 
    typedef char CHARACTER; // type 'char' has been redefined as CHARACTER, now CHARACTER can be treated just like char
    typedef double MY_DOUBLE; // type 'double' has been redefined as MY_DOUBLE, now MY_DOUBLE can be treated just like double

    // **** JUST LIKE IN Win32SDK !!! ******
    typedef unsigned int UINT;
    typedef UINT HANDLE;
    typedef HANDLE HWND;
    typedef HANDLE HINSTANCE;

    //variable declarations
    MY_INT a = 10, i;
    MY_INT iArray[] = {9, 18, 27, 36, 45, 54, 63, 72, 81, 90};

    PVG_FLOAT f_pvg = 30.9f;
    const PVG_FLOAT f_pvg_pi = 3.14f;

    CHARACTER ch = '*';
    CHARACTER chArray_01[] = "Hello";
    CHARACTER chArray_02[][10] = {"RTR", "Batch", "2024-2025"};

    MY_DOUBLE d = 8.041997;

    // ** Just random num_vvabers - they have nothing to do with any windows handle or instance handle !!! This is just fo understanding
    UINT uint = 3456;
    HANDLE handle = 987;
    HWND hwnd = 9876;
    HINSTANCE hInstance = 14466;

    //code
    printf("\n\n");
    printf("Type MY_INT variable a %d\n", a);

    printf("\n\n");
    for ( i = 0; i < (sizeof(iArray)/sizeof(int)); i++)
    {
        printf("Type MY_INT array variable iArray[%d] = %d\n", i, iArray[i]);
    }
    printf("\n\n");

    printf("\n\n");
    printf("Type PVG_FLOAT variable f = %f\n", f_pvg);
    printf("Type PVG_FLOAT variable f_pvg_pi = %f\n", f_pvg_pi);

    printf("\n\n");
    printf("Type MY_DOUBLE variable d = %lf\n", d);

    printf("\n\n");
    printf("Type CHARACTER variable ch = %c\n", ch);

    printf("\n\n");
    printf("Type CHARACTER array variable chArray_01 = %s\n", chArray_01);

    printf("\n\n");
    for ( i = 0; i < (sizeof(chArray_02)/sizeof(chArray_02[0])); i++)
    {
        printf("%s\t", chArray_02[i]);
    }
    printf("\n\n");

    printf("\n\n");
    printf("Type UINT variable uint = %u\n\n", uint);
    printf("Type HANDLE variable handle = %u\n\n", handle);
    printf("Type HWND variable hwnd = %u\n\n", hwnd);
    printf("Type HINSTANCE variable hInstance = %u\n\n", hInstance);
    printf("\n\n");


    MY_INT x = 90;
    MY_INT y = 30;
    MY_INT ret;

    ret = Add(x, y);
    printf("ret = %d\n\n", ret);

    return (0);
}

MY_INT Add(MY_INT a, MY_INT b)
{
    // variable declaration
    MY_INT c;

    //code
    c = a + b;
    return (c);
}