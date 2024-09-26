/*
Clayton Scharf
U13191590
Simple program that computes the rental cost of a bounce house
*/
#include <stdio.h>
int main(){
    //Variable initialization
    int house, hour_min, hour_rate, per_day;
    printf("Please select from four bounce houses: 1, 2, 3, and 4\n");
    printf("Enter bounce house selection: ");
    scanf("%d", &house);

    //Input validation
    if(house < 1 || house > 4)
        printf("Invalid selection. Select from 1 to 4.");
    
    else {
        //Switch statement to assign the proper hour_min, hour_rate, and per_day values
        switch (house) {
            case 1:
                hour_min = 58;
                hour_rate = 8;
                per_day = 80;
                break;
            case 2: 
                hour_min = 85;
                hour_rate = 12;
                per_day = 120;
                break;
            case 3:
                hour_min = 100;
                hour_rate = 12;
                per_day = 150;
                break;
            case 4:
                hour_min = 180;
                hour_rate = 20;
                per_day = 250;
                break;
            /*
            Default case here just in case some value other than 1, 2, 3, or 4 
            slips by even though that should be impossible
            */
            default:
                break;
        }

        //Variable initialization
        int days, hours, hour_cost, day_cost, total;
        printf("Enter days:");
        scanf("%d", &days);
        //Calculates total per day cost
        day_cost = per_day * days;

        printf("Enter hours:");
        scanf("%d", &hours);

        //Input validation
        if(hours < 0 || hours >= 24)
            printf("Invalid hours.");
    
        else if(days == 0) {
            //Calculates hourly cost
            hours = hours - 3;
            if(hours < 0)//Stops hours from being negative after subtracting the 3 hour minimum
                hours = 0;
            hour_cost = hour_min + (hours * hour_rate);
        }

        //Calculates hourly cost when number of days is not 0
        else
            hour_cost = hour_rate * hours;

        //Ensures hourly cost does not go above per day cost
        if(hour_cost > per_day)
                hour_cost = per_day;
        
        //Calculates total cost
        total = hour_cost + day_cost;

        printf("Charge($): %d", total);
    }

    return 0;

}