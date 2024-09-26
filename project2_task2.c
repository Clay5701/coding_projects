/*
Clayton Scharf
U13191590
A short program that computes and compares the number of points earned by 2 different entered phrases.
*/
#include <stdio.h>
int main() {
    //variable initialization
    char ch;
    int marjorie_score = 0;
    int john_score = 0;

    printf("Enter the first sequence: ");

    //do while loop to compute score of first phrase.
    do {
        ch = getchar();
        if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u')
            marjorie_score = marjorie_score + 1;
        else if(ch == 't'||ch == 'n'||ch == 's'||ch == 'r'||ch == 'h')
            marjorie_score = marjorie_score + 2;
        else if(ch >= 'a' && ch <= 'z')
            marjorie_score = marjorie_score + 3;
    }
    while(ch != '\n');

    printf("Enter the second sequence: ");

    //do while loop to compute score of second phrase. (A function would be more efficient here.)
    do {
        ch = getchar();
        if(ch == 'a'||ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u')
            john_score = john_score + 1;
        else if(ch == 't'||ch == 'n'||ch == 's'||ch == 'r'||ch == 'h')
            john_score = john_score + 2;
        else if(ch >= 'a' && ch <= 'z')
            john_score = john_score + 3;
    }
    while(ch != '\n');

    //compares values from marjorie_score and john_score to declare a winner.
    if(marjorie_score > john_score) printf("Marjorie wins!");
    else if(john_score > marjorie_score) printf("John wins!");
    else printf("Play again!");

    return 0;
}