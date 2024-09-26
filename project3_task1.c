/*
Clayton Scharf
U13191590
A short program that checks if a particular array of numbers is "good" or "bad"
*/
#include <stdio.h>

int main() {
    int size, i, square;
    //initializes the nums array with size and sq_nums array with size - 1 (we don't need to find the square of the last value)
    printf("Enter the size of sequence: ");
    scanf("%d", &size);
    int nums[size];
    int sq_nums[size - 1];
    
    //puts the desired integers into array nums
    printf("Enter numbers: ");
    for(i=0;i<size;i++)
        scanf("%d", &nums[i]);
    
    //creates the sq_nums array
    for(i=0;i<size;i++) {
        square = (i + 1) * (i + 1);
        sq_nums[i] = square;
    }

    int j, count = 0;
    //compares every integer in nums to size
    for(i=0;i<size;i++) {
        if(nums[i] < size) count++;
        //if a given integer is larger than size it's compared to every squared value
        else {
            for(j=0;j<size;j++) {
                if(nums[i] == sq_nums[j]) count++;
            }
        }
    }

    /*
    when nums[i] is either less than size or equal to a value in sq_nums the count variable is incremented by 1
    count == size is a good sequence
    */

    if(count == size) printf("Output: yes");
    else printf("Output: no");

    return 0;
}