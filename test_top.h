#include <stdio.h>
#include <string.h>
#include "color.h"

struct Player {
    char name[50];
    int score;
};

void winner(int score[]) {
    char winnerName[50];
    struct Player players[10] = { {"", 0} };
    int numPlayers = 0;

    FILE *file = fopen("top10.txt", "r");
    if (file != NULL) {
        for (int i = 0; i < 10; i++) {
            if (fscanf(file, "%49s %d", players[i].name, &players[i].score) != 2) {
                players[i].name[0] = '\0';
                players[i].score = 0;
            } else {
                numPlayers++;
            }
        }
        fclose(file);
    }

    int winner_no;
    if (score[1] > score[2]) {
        printf(yellow "Player 1 is the winner with score %i\n" rest, score[1]);
        printf(white "The winner name: " white);
        scanf("%49s", winnerName);
        winner_no = 1;
    } else if (score[1] < score[2]) {
        printf(blue "Player 2 is the winner with score %i\n" rest, score[2]);
        printf(white "The winner name: " white);
        scanf("%49s", winnerName);
        winner_no = 2;
    } else {
        printf("The game is a draw\n");
        return;
    }

    int found = -1;
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(players[i].name, winnerName) == 0) {
            found = i;
            break;
        }
    }

    int lowestScore = 0; 
    if (numPlayers > 0) {
        lowestScore = players[numPlayers - 1].score; // Setting lowestScore to last one in the file if numPlayers is greater than 0
    }

    if (found != -1) {
        // if a player whose name already in the list and scored higher score
        if (players[found].score < score[winner_no]) {
            players[found].score = score[winner_no];
        }
    } else {
        // Check if the leaderboard is full and a new player's score passes the lowest score
        if (numPlayers < 10 || score[winner_no] > lowestScore) {
            if (numPlayers >= 10) {
                // Replace the player with the lowest score
                strcpy(players[numPlayers - 1].name, winnerName);
                players[numPlayers - 1].score = score[winner_no];
            } else {
                // Add a new player
                strcpy(players[numPlayers].name, winnerName);
                players[numPlayers].score = score[winner_no];
                numPlayers++;
            }
        }
    }
    // sorting of the leaderboard in descending order 
    for (int i = 0; i < numPlayers - 1; i++) {
        for (int j = i + 1; j < numPlayers; j++) {
            if (players[i].score < players[j].score) {
                struct Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
    file = fopen("top10.txt", "w"); // Update the leaderboard file
    if (file != NULL) {
        for (int i = 0; i < 10; ++i) {
            if (players[i].score > 0 && players[i].name[0] != '\0') {
                fprintf(file, "%-20s %d\n", players[i].name, players[i].score);
            }
        }
        fclose(file);
}
}


