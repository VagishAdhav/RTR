#include <stdio.h>

int main(void)
{
    //code 
    printf("\n\n");
    
    printf("Going on to next line using \\n sequence \n\n");
    printf("Demonstrating \t horizontal \t tab  \t using \t \\t escape sequence !!! \n\n");
    printf("\"This is a double quoted output\" done using \\\" \\\" escape sequence\n\n");
    printf("\'This is single quoted output\' sone using \\\' \\\' escape sequence\\n\n");
    printf("BACKSPACE turned to BACKSPACE\b using escape sequence \\b\n\n");
    printf("\r Demonstrating carriage return using \\r escape sequence\n");
    printf("Demonstrating \r carriage return using \\r escape sequence\n");
    printf("Demonstrating carriage \r return using \\\r escape sequence\n\n");

    // 0x41 is the hexadecimal code for letter 'A' , 'xhh' is the placeholder for 'x' followed by two digits (hh), along together forming a hexadecimal number.
    printf("Demonstrating \x41 using \\xhh escape sequence \n\n");

    //102 is the octal code for letter 'B'. 'ooo' is the placeholder for 3 digits forming an octal number
    printf("Demonstrating \102 using \\ooo escape sequence\n\n");

    return (0);

}