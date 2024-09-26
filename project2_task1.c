/*
Clayton Scharf
U13191590
A small progam that calculates the number of grade oscillations for a give number of grades
*/
#include <stdio.h>
int main() {
    //initialization
    int num_grade, grade, current_min, current_max;
    int first_flag = 1;
    int osc = 0;

    //Number of grades prompt and input
    printf("Enter the number of grades: ");
    scanf("%d", &num_grade);

    //grades prompt
    printf("Enter the grades: ");

    //loop for input. loops for num_grades.
    for(int i = 0; i < num_grade; i++) {
        scanf("%d", &grade);

        /*
        the first grade is both the current lowest and highest grade
        this block gives current_min and current_max the value of the first grade
        this only needs to run once hence the flag
        */
        if(first_flag == 1) {
            current_min = grade;
            current_max = grade;
            first_flag = 0;
        }

        //compares grade with current_min and current_max
        else {
            //if grade > current_max, one is added to the oscillation count and current_max is set to grade
            if(grade > current_max) {
                current_max = grade;
                osc++;
            }
            //if grade < current_min, one is added to the oscillation count and current_min is set to grade
            else if(grade < current_min) {
                current_min = grade;
                osc++;
            }
            //grade is insignificant and skipped
            else
                continue;
        }
        
    }

    printf("%d", osc);

    return 0;
}