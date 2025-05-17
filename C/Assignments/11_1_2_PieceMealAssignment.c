#include <stdio.h>

int main(void)
{
    // variable declaration
    int i_vvaArrayOne[10];
    int i_vvaArrayTwo[10];

    // code

    // *******i_vvaArrayOne[]************
    i_vvaArrayOne[0] = 3;
    i_vvaArrayOne[1] = 6;
    i_vvaArrayOne[2] = 9;
    i_vvaArrayOne[3] = 12;
    i_vvaArrayOne[4] = 15;
    i_vvaArrayOne[5] = 18;
    i_vvaArrayOne[6] = 21;
    i_vvaArrayOne[7] = 24;
    i_vvaArrayOne[8] = 27;
    i_vvaArrayOne[9] = 30;

    printf("\n\n");
    printf("Piece-meal (Hard-coded) assignment and display of elements to Array 'i_vvaArray[]': \n\n");
    printf("1st Element of Array 'i_vvaArrayOne[]' or element at 0th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[0]);
    printf("2nd Element of Array 'i_vvaArrayOne[]' or element at 1th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[1]);
    printf("3rd Element of Array 'i_vvaArrayOne[]' or element at 2th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[2]);
    printf("4th Element of Array 'i_vvaArrayOne[]' or element at 3th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[3]);
    printf("5th Element of Array 'i_vvaArrayOne[]' or element at 4th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[4]);
    printf("6th Element of Array 'i_vvaArrayOne[]' or element at 5th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[5]);
    printf("7th Element of Array 'i_vvaArrayOne[]' or element at 6th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[6]);
    printf("8th Element of Array 'i_vvaArrayOne[]' or element at 7th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[7]);
    printf("9th Element of Array 'i_vvaArrayOne[]' or element at 8th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[8]);
    printf("10th Element of Array 'i_vvaArrayOne[]' or element at 9th index of array 'i_vvaArrayOne[] = %d\n", i_vvaArrayOne[9]);

    // *** i_vvaArrayTwo[] ********
    printf("\n\n");

    printf("Enter 1st  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[0]);
    printf("Enter 2nd  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[1]);
    printf("Enter 3rd  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[2]);
    printf("Enter 4th  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[3]);
    printf("Enter 5th  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[4]);
    printf("Enter 6th  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[5]);
    printf("Enter 7th  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[6]);
    printf("Enter 8th  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[7]);
    printf("Enter 9th  element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[8]);
    printf("Enter 10th element of array 'i_vvaArrayTwo[] : ");
    scanf("%d", &i_vvaArrayTwo[9]);

    printf("\n\n");
    printf("Piece-meal (user-input) assignment and display of elements to Array 'i_vvaArray[]': \n\n");
    printf("1st Element of Array 'i_vvaArrayTwo[]' or element at 0th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[0]);
    printf("2nd Element of Array 'i_vvaArrayTwo[]' or element at 1th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[1]);
    printf("3rd Element of Array 'i_vvaArrayTwo[]' or element at 2th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[2]);
    printf("4th Element of Array 'i_vvaArrayTwo[]' or element at 3th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[3]);
    printf("5th Element of Array 'i_vvaArrayTwo[]' or element at 4th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[4]);
    printf("6th Element of Array 'i_vvaArrayTwo[]' or element at 5th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[5]);
    printf("7th Element of Array 'i_vvaArrayTwo[]' or element at 6th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[6]);
    printf("8th Element of Array 'i_vvaArrayTwo[]' or element at 7th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[7]);
    printf("9th Element of Array 'i_vvaArrayTwo[]' or element at 8th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[8]);
    printf("10th Element of Array 'i_vvaArrayTwo[]' or element at 9th index of array 'i_vvaArrayTwo[] = %d\n", i_vvaArrayTwo[9]);

    return (0);    

}