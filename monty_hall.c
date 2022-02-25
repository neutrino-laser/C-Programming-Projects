//
// Created by James Quiaoit on 2/24/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for seeding srand()

#define NUM_SIM 10000
#define NUM_DOORS 3

// Monty Hall problem for 3 doors
static void monty_hall(int doSwitch, int *win_cnt) {
    int doors[] = {rand() % 2, rand() % 2,rand() % 2}; // representation of doors
    int user_choice = rand() % NUM_DOORS;                         // user chooses door
    int host_choice = rand() % NUM_DOORS;                         // host chooses door
    while ((host_choice != 0) && (host_choice != user_choice)) {  // ensure host chooses door that is 0 and non-user
        host_choice = rand() % NUM_DOORS;
    }
    if (doSwitch) { // switch choice to other door
        int oldChoice = user_choice;
        while ((user_choice != oldChoice) && (user_choice != host_choice)) {
            user_choice = rand() % NUM_DOORS;
        }
        *win_cnt += (doors[user_choice] == 1);
        return;
    }
    *win_cnt += (doors[user_choice] == 1); // stay with original choice
}

// test harness code
int main() {
    srand(time(NULL));
    int no_sw_win_cnt = 0;
    int sw_win_cnt = 0;
    for (int i = 0; i < NUM_SIM; i++) { // run monty hall problem NUM_SIM times w/0 switching
        monty_hall(0, &no_sw_win_cnt);
        monty_hall(1, &sw_win_cnt);
    }
    printf("Without switching win rate: %d/%d\n", no_sw_win_cnt, NUM_SIM);
    printf("With switching win rate: %d/%d\n", sw_win_cnt, NUM_SIM);
    return 0;
}

