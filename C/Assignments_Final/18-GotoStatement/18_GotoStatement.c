#include <stdio.h>
#include <string.h> // for toupper()

int main(void)
{
    // variable declarations
    char ch_vva, ch_i_vva;
    unsigned int ascii_ch_vva = 0;

    //code
    printf("\n\n");
    printf("Enter the first character of first name : ");
    ch_vva = getch();
    ch_vva = toupper(ch_vva);

    for(ch_i_vva = 'A'; ch_i_vva <= 'Z'; ch_i_vva++)
    {
        if (ch_vva == ch_i_vva)
        {
            ascii_ch_vva = (unsigned int)ch_vva;
            goto result_output; // program flow jumps directly to label "result_output"
        }
    }

    printf("\n\n");
    printf("Goto statement not executed , so printing \"Hello World !!!\".\n"); // will be omitted if goto statement is executed

result_output:  // label itself does not alter flow of program. Following code is executed regardless of whether goto statement is executed or not

    printf("\n\n");

    if(ascii_ch_vva == 0)
    {
        printf("You must have a strange name!Could not find the character '%c' in the entire english alphabet!\n", ch_vva);
    }
    else
    {
        printf("Character '%c' found. It has ASCII value %u.\n", ch_vva, ascii_ch_vva);
    }
    printf("\n\n");
    return (0);
}