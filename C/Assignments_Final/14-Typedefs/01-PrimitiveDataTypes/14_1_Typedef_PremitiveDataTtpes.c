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
    MY_INT a_vva = 10, i_vva;
    MY_INT iArray_vva[] = {9, 18, 27, 36, 45, 54, 63, 72, 81, 90};

    PVG_FLOAT f_pvg_vva = 30.9f;
    const PVG_FLOAT f_pvg_pi_vva = 3.14f;

    CHARACTER ch_vva = '*';
    CHARACTER chArray_01_vva[] = "Hello";
    CHARACTER chArray_02_vva[][10] = {"RTR", "Batch", "2024-2025"};

    MY_DOUBLE d_vva = 8.041997;

    // ** Just random numbers - they have nothing to do with any windows handle_vva or instance handle_vva !!! This is just fo understanding
    UINT uint_vva = 3456;
    HANDLE handle_vva = 987;
    HWND hwnd_vva = 9876;
    HINSTANCE hInstance_vva = 14466;

    //code
    printf("\n\n");
    printf("Type MY_INT variable a_vva %d\n", a_vva);

    printf("\n\n");
    for ( i_vva = 0; i_vva < (sizeof(iArray_vva)/sizeof(int)); i_vva++)
    {
        printf("Type MY_INT array variable iArray_vva[%d] = %d\n", i_vva, iArray_vva[i_vva]);
    }
    printf("\n\n");

    printf("\n\n");
    printf("Type PVG_FLOAT variable f = %f\n", f_pvg_vva);
    printf("Type PVG_FLOAT variable f_pvg_pi_vva = %f\n", f_pvg_pi_vva);

    printf("\n\n");
    printf("Type MY_DOUBLE variable d_vva = %lf\n", d_vva);

    printf("\n\n");
    printf("Type CHARACTER variable ch_vva = %c\n", ch_vva);

    printf("\n\n");
    printf("Type CHARACTER array variable chArray_01_vva = %s\n", chArray_01_vva);

    printf("\n\n");
    for ( i_vva = 0; i_vva < (sizeof(chArray_02_vva)/sizeof(chArray_02_vva[0])); i_vva++)
    {
        printf("%s\t", chArray_02_vva[i_vva]);
    }
    printf("\n\n");

    printf("\n\n");
    printf("Type UINT variable uint_vva = %u\n\n", uint_vva);
    printf("Type HANDLE variable handle_vva = %u\n\n", handle_vva);
    printf("Type HWND variable hwnd_vva = %u\n\n", hwnd_vva);
    printf("Type HINSTANCE variable hInstance_vva = %u\n\n", hInstance_vva);
    printf("\n\n");


    MY_INT x_vva = 90;
    MY_INT y_vva = 30;
    MY_INT ret_vva;

    ret_vva = Add(x_vva, y_vva);
    printf("ret_vva = %d\n\n", ret_vva);

    return (0);
}

MY_INT Add(MY_INT a_vva, MY_INT b_vva)
{
    // variable declaration
    MY_INT c_vva;

    //code
    c_vva = a_vva + b_vva;
    return (c_vva);
}