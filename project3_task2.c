/*
Clayton Scharf
U13191590
A short program that takes in an array of integers, removes the duplicates and prints them in ascending order
*/
#include <stdio.h>
//function declaration
int distArray(int n[], int r[], int s);
void sortAlg(int r[], int s);

int main () {
    int size, i;
    //initializes the array that will hold the integers and the array that will hold the distinct integers
    printf("Enter the size of sequence: ");
    scanf("%d", &size);
    int nums[size], distinct[size];

    //puts values in the number array
    printf("Enter numbers: ");
    for(i=0;i<size;i++) scanf("%d", &nums[i]);
    
    //calls the distArray function to both create an array with the distinct integers and return the size of said array
    int distinct_size = distArray(nums, distinct, size);

    //calls the sortAlg function to put the distinct integer array into ascending order
    sortAlg(distinct, distinct_size);

    //prints the properly ordered distinct integer array
    printf("Output: ");
    for(i=0;i<distinct_size;i++) {
        printf("%d ", distinct[i]);
    }

    return 0;
}

//function that creates an array with distinct integers and returns the size of the array
int distArray(int n[], int r[], int s) {
    int distinct_size = 0;
    int distinct_flag = 1;
    int i, j;

    //first for loop iterates over the number of items in the original integer array
    for(i=0;i<s;i++) {
        /*second for loop iterates over the number of items in the new distinct array
        this loop compares every value in the new array to the old array
        if the value isn't present in the new array it's added with the if statement below*/
        for(j=0;j<distinct_size;j++) {
            if(n[i] == r[j]) {
                distinct_flag = 0; //this triggers the if statement below to be skipped if the value is already found the the new array
                break;
            }
        }

        if(distinct_flag == 1) {
            r[distinct_size] = n[i];
            distinct_size++;
        }

        distinct_flag = 1; //resets the flag for the next i value
    }

    return distinct_size;
}

//function to sort the new array into ascending order
void sortAlg(int r[], int s) {
    int i, temp, max = 0;

    //this for loop finds the max value in the array
    for(i=0;i<s;i++) {
        if(r[i] > r[max]) max = i;
    }
    //this is the stopping condition for the recursive loop
    if(s == 1) return;
    //this swaps the last value in the array with the max value
    else {
        temp = r[s-1];
        r[s-1] = r[max];
        r[max] = temp;
        sortAlg(r, s-1); //runs the sorting function again but shrinks the size by one avoid the last array value
    }
}