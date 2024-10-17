/*
Clayton Scharf
U13191590
A short program that determines the winner of a simple number game.
*/
#include <stdio.h>

void round_result(int *board, int n);

int starting_player_key = 0;    //global variable used to alternate the starting player

int main() {
    int rounds;
    scanf("%d", &rounds);

    for(int i = 0; i < rounds; i++) {   //main loop for each round
        int size;
        scanf("%d", &size);

        int board[size];
        int *p; //pointer used instead of i to add values to the board array

        for(p = board; p < board + size; p++) {
            scanf("%d", p);
        }
        //if i % 2 == 0 Marjorie starts so starting_player_key = 0
        //if i % 2 == 1 John starts so starting_player_key = 1
        starting_player_key = i % 2;

        round_result(board, size);
    }
    return 0;
}


void round_result(int *board, int n) {
    int start_offset = 0;
    int end_offset = 1; //this starts at 1 because the starting index of an array is 0
    //the round_count starts at either 0 or 1 depending on the starting player for the round. this is used later
    int round_count = starting_player_key;
    int john = 0, marjorie = 0;
    int selection;

    while(start_offset <= n - end_offset) {
        //this compares board[start_offset] with board[n - end_offset] using pointers
        //this will compare board[0] with board[n-1] on the first iteration
        if(*(board + start_offset) > *(board + n - end_offset)) {
            selection = *(board + start_offset);
            start_offset++; //effectively "removes" the left most value in the array by offsetting the start by 1
        }
        else {
            selection = *(board + n - end_offset);
            end_offset++;   //effectively "removes" the right most value in the array by offsetting the end by 1
        }
        //round_count % 2 is used to alternate between Marjorie and John each cycle
        //if round_count starts at 1 instead of 0 John will go first hence why round_count is initialized to starting_player_key
        if(round_count % 2 == 0) {
            marjorie += selection;
        }
        else {
            john += selection;
        }
        round_count++;
    }

    //prints the winner
    if(marjorie > john) {
        printf("Marjorie\n");
    }
    else if(marjorie < john) {
        printf("John\n");
    }
    else {
        printf("Draw\n");
    }
}
