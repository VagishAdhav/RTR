#include <stdio.h>

int main(void)
{
    // variable declaration
    int iArrayOne_vva[10];
    int iArrayTwo_vva[10];

    // code

    // *******iArrayOne_vva[]************
    iArrayOne_vva[0] = 3;
    iArrayOne_vva[1] = 6;
    iArrayOne_vva[2] = 9;
    iArrayOne_vva[3] = 12;
    iArrayOne_vva[4] = 15;
    iArrayOne_vva[5] = 18;
    iArrayOne_vva[6] = 21;
    iArrayOne_vva[7] = 24;
    iArrayOne_vva[8] = 27;
    iArrayOne_vva[9] = 30;

    printf("\n\n");
    printf("Piece-meal (Hard-coded) assignment and display of elements to Array 'iArray_vva[]': \n\n");
    printf("1st Element of Array 'iArrayOne_vva[]' or element at 0th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[0]);
    printf("2nd Element of Array 'iArrayOne_vva[]' or element at 1th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[1]);
    printf("3rd Element of Array 'iArrayOne_vva[]' or element at 2th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[2]);
    printf("4th Element of Array 'iArrayOne_vva[]' or element at 3th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[3]);
    printf("5th Element of Array 'iArrayOne_vva[]' or element at 4th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[4]);
    printf("6th Element of Array 'iArrayOne_vva[]' or element at 5th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[5]);
    printf("7th Element of Array 'iArrayOne_vva[]' or element at 6th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[6]);
    printf("8th Element of Array 'iArrayOne_vva[]' or element at 7th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[7]);
    printf("9th Element of Array 'iArrayOne_vva[]' or element at 8th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[8]);
    printf("10th Element of Array 'iArrayOne_vva[]' or element at 9th index of array 'iArrayOne_vva[] = %d\n", iArrayOne_vva[9]);

    // *** iArrayTwo_vva[] ********
    printf("\n\n");

    printf("Enter 1st  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[0]);
    printf("Enter 2nd  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[1]);
    printf("Enter 3rd  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[2]);
    printf("Enter 4th  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[3]);
    printf("Enter 5th  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[4]);
    printf("Enter 6th  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[5]);
    printf("Enter 7th  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[6]);
    printf("Enter 8th  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[7]);
    printf("Enter 9th  element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[8]);
    printf("Enter 10th element of array 'iArrayTwo_vva[] : ");
    scanf("%d", &iArrayTwo_vva[9]);

    printf("\n\n");
    printf("Piece-meal (user-input) assignment and display of elements to Array 'iArray_vva[]': \n\n");
    printf("1st Element of Array 'iArrayTwo_vva[]' or element at 0th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[0]);
    printf("2nd Element of Array 'iArrayTwo_vva[]' or element at 1th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[1]);
    printf("3rd Element of Array 'iArrayTwo_vva[]' or element at 2th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[2]);
    printf("4th Element of Array 'iArrayTwo_vva[]' or element at 3th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[3]);
    printf("5th Element of Array 'iArrayTwo_vva[]' or element at 4th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[4]);
    printf("6th Element of Array 'iArrayTwo_vva[]' or element at 5th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[5]);
    printf("7th Element of Array 'iArrayTwo_vva[]' or element at 6th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[6]);
    printf("8th Element of Array 'iArrayTwo_vva[]' or element at 7th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[7]);
    printf("9th Element of Array 'iArrayTwo_vva[]' or element at 8th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[8]);
    printf("10th Element of Array 'iArrayTwo_vva[]' or element at 9th index of array 'iArrayTwo_vva[] = %d\n", iArrayTwo_vva[9]);

    return (0);    

}