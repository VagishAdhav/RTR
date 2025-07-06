#include <stdio.h>

int main(void)
{
    printf(" -10 mod 3 : %d\n", -10 % 3);  // -1
    printf(" -10 mod -3 : %d\n", -10 % -3); // 1
    printf(" 10 mod 3 : %d\n", 10 % 3 ); // 1
    printf(" 10 mod -3 : %d\n", 10 % -3); // -1
    return 0;
}