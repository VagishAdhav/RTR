#include <stdio.h>

int main(void)
{
    // variable declaration
    int vva_iArrayOne[10];
    int vva_iArrayTwo[10];

    // code

    // *******vva_iArrayOne[]************
    vva_iArrayOne[0] = 3;
    vva_iArrayOne[1] = 6;
    vva_iArrayOne[2] = 9;
    vva_iArrayOne[3] = 12;
    vva_iArrayOne[4] = 15;
    vva_iArrayOne[5] = 18;
    vva_iArrayOne[6] = 21;
    vva_iArrayOne[7] = 24;
    vva_iArrayOne[8] = 27;
    vva_iArrayOne[9] = 30;

    printf("\n\n");
    printf("Piece-meal (Hard-coded) assignment and display of elements to Array 'vva_iArray[]': \n\n");
    printf("1st Element of Array 'vva_iArrayOne[]' or element at 0th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[0]);
    printf("2nd Element of Array 'vva_iArrayOne[]' or element at 1th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[1]);
    printf("3rd Element of Array 'vva_iArrayOne[]' or element at 2th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[2]);
    printf("4th Element of Array 'vva_iArrayOne[]' or element at 3th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[3]);
    printf("5th Element of Array 'vva_iArrayOne[]' or element at 4th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[4]);
    printf("6th Element of Array 'vva_iArrayOne[]' or element at 5th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[5]);
    printf("7th Element of Array 'vva_iArrayOne[]' or element at 6th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[6]);
    printf("8th Element of Array 'vva_iArrayOne[]' or element at 7th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[7]);
    printf("9th Element of Array 'vva_iArrayOne[]' or element at 8th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[8]);
    printf("10th Element of Array 'vva_iArrayOne[]' or element at 9th index of array 'vva_iArrayOne[] = %d\n", vva_iArrayOne[9]);

    // *** vva_iArrayTwo[] ********
    printf("\n\n");

    printf("Enter 1st  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[0]);
    printf("Enter 2nd  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[1]);
    printf("Enter 3rd  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[2]);
    printf("Enter 4th  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[3]);
    printf("Enter 5th  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[4]);
    printf("Enter 6th  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[5]);
    printf("Enter 7th  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[6]);
    printf("Enter 8th  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[7]);
    printf("Enter 9th  element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[8]);
    printf("Enter 10th element of array 'vva_iArrayTwo[] : ");
    scanf("%d", &vva_iArrayTwo[9]);

    printf("\n\n");
    printf("Piece-meal (user-input) assignment and display of elements to Array 'vva_iArray[]': \n\n");
    printf("1st Element of Array 'vva_iArrayTwo[]' or element at 0th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[0]);
    printf("2nd Element of Array 'vva_iArrayTwo[]' or element at 1th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[1]);
    printf("3rd Element of Array 'vva_iArrayTwo[]' or element at 2th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[2]);
    printf("4th Element of Array 'vva_iArrayTwo[]' or element at 3th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[3]);
    printf("5th Element of Array 'vva_iArrayTwo[]' or element at 4th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[4]);
    printf("6th Element of Array 'vva_iArrayTwo[]' or element at 5th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[5]);
    printf("7th Element of Array 'vva_iArrayTwo[]' or element at 6th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[6]);
    printf("8th Element of Array 'vva_iArrayTwo[]' or element at 7th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[7]);
    printf("9th Element of Array 'vva_iArrayTwo[]' or element at 8th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[8]);
    printf("10th Element of Array 'vva_iArrayTwo[]' or element at 9th index of array 'vva_iArrayTwo[] = %d\n", vva_iArrayTwo[9]);

    return (0);    

}