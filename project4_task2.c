/*
Clayton Scharf
U13191590
A short program that loops through an array and prints the number of equal values to the left and right
of *(array + i)
*/
#include <stdio.h>

void before_after(int *array, int n);

int main() {
    int size;

    scanf("%d", &size);
    int array[size];

    for(int *p = array; p < array + size; p++) {
        scanf("%d", p);
    }

    before_after(array, size);
}

void before_after(int *array, int n) {
    //loops through every element of array
    for(int *p = array; p < array + n; p++) {
        int count = 0;  //counting variable used to keep track of equivalent values
        //loops through array again to compare *p to every other value
        for(int *q = array; q < array + n; q++) {
            //when q == p the left half of array has been looped through
            if(q == p) {
                printf("%d ", count);
                count = 0;  //reset count back to 0 to get an accurate count of the right side
                continue;
            }
            if(*q == *p) {
                count++;
            }
        }
        printf("%d\n", count);
        //count is reset back to 0 at the beginning of the loop
    }
}