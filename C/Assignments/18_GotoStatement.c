#include <stdio.h>
#include <string.h> // for toupper()

int main(void)
{
    // variable declarations
    char ch, ch_i;
    unsigned int ascii_ch = 0;

    //code
    printf("\n\n");
    printf("Enter the first character of first name : ");
    ch = getch();
    ch = toupper(ch);

    for(ch_i = 'A'; ch_i <= 'Z'; ch_i++)
    {
        if (ch == ch_i)
        {
            ascii_ch = (unsigned int)ch;
            goto result_output; // program flow jumps directly to label "result_output"
        }
    }

    printf("\n\n");
    printf("Goto statement not executed , so printing \"Hello World !!!\".\n"); // will be omitted if goto statement is executed

result_output:  // label itself does not alter flow of program. Following code is executed regardless of whether goto statement is executed or not

    printf("\n\n");

    if(ascii_ch == 0)
    {
        printf("You must have a strange name!Could not find the character '%c' in the entire english alphabet!\n", ch);
    }
    else
    {
        printf("Character '%c' found. It has ASCII value %u.\n", ch, ascii_ch);
    }
    printf("\n\n");
    return (0);
}