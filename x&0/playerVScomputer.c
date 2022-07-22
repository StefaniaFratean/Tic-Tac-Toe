/**************************************************************************/
/** playerVScomputer.c - Program for player vs computer game version     **/
/** University: Technical University of Cluj-Napoca                      **/
/** Author: Stefania Fratean                                             **/
/** Version:  4.01.2021                                                  **/
/**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "playerVScomputer.h"
#include "twoPlayersVersion.h"


int startFirstOrSecond() {
    /// Gives the oportunity to choose to play with X or 0
    char choice[100]="";
    printf("\n\n\tDo you want to start first ( X ) or second ( 0 )? \n");
    printf("\tType \" exit \" to end the program \n\n");
    printf("\tEnter your choice (X, 0 or exit): ");
    scanf("%s", choice);

    while((strlen(choice) != 1 && strcmp(choice, "exit") != 0) || (strlen(choice) == 1 && (choice[0] != 'X' && choice[0] != '0'))) {
        printf("\n\tPlease enter only X, 0 or exit and then press Enter: ");
        scanf("%s", choice);
    }
    if(choice[0] == '0') {
        return 2;
    }
    else if(choice[0] == 'X') {
        return 1;
    }
    else{
        return 3;
    }
}

void printMap(char box[]) {
    system("cls"); ///function that clears the screen
    printf("\n\n\tTic Tac Toe\n\n");

    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", box[1], box[2], box[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", box[4], box[5], box[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", box[7], box[8], box[9]);

    printf("     |     |     \n\n");
}

    ///step 1
int win_if_you_can(char box[], int round) {
    char computerMark; ///saves the computer option ( X or 0 )
    if(round == 1)
        computerMark = '0';
    else computerMark = 'X';
///checking the rows
    if(check_row(1, box, computerMark) != -1) {
        box[check_row(1, box, computerMark)] = computerMark;
        return 1;
    }
    else if(check_row(4, box, computerMark) != -1) {
        box[check_row(4, box, computerMark)] = computerMark;
        return 1;
    }
    else if(check_row(7, box, computerMark) != -1){
        box[check_row(7, box, computerMark)] = computerMark;
        return 1;
    }
///checking the collumns
    else if(check_column(1, box, computerMark) != -1) {
        box[check_column(1, box, computerMark)] = computerMark;
        return 1;
    }
    else if(check_column(2, box, computerMark) != -1) {
        box[check_column(2, box, computerMark)] = computerMark;
        return 1;
    }
    else if(check_column(3, box, computerMark) != -1) {
        box[check_column(3, box, computerMark)] = computerMark;
        return 1;
    }
///checking the diagonals
    else if(check_PD(box, computerMark) != -1){
        box[check_PD(box, computerMark)] = computerMark;
        return 1;
    }
    else if(check_SD(box, computerMark) != -1){
        box[check_SD(box, computerMark)] = computerMark;
        return 1;
    }
    return 0;
}

    ///step 2
int block_the_opponent(char box[], int round) {
    char computerMark, playerMark; ///saves the computer option ( X or 0 )
    if(round == 1) {
        computerMark = '0';
        playerMark = 'X';
    }
    else {
        computerMark = 'X';
        playerMark = '0';
    }

///checking the rows
    if(check_row(1, box, playerMark) != -1) {
        box[check_row(1, box, playerMark)] = computerMark;
        return 1;
    }
    else if(check_row(4, box, playerMark) != -1) {
        box[check_row(4, box, playerMark)] = computerMark;
        return 1;
    }
    else if(check_row(7, box, playerMark) != -1){
        box[check_row(7, box, playerMark)] = computerMark;
        return 1;
    }
///checking the collumns
    else if(check_column(1, box, playerMark) != -1) {
        box[check_column(1, box, playerMark)] = computerMark;
        return 1;
    }
    else if(check_column(2, box, playerMark) != -1) {
        box[check_column(2, box, playerMark)] = computerMark;
        return 1;
    }
    else if(check_column(3, box, playerMark) != -1) {
        box[check_column(3, box, playerMark)] = computerMark;
        return 1;
    }
///checking the diagonals
    else if(check_PD(box, playerMark) != -1){
        box[check_PD(box, playerMark)] = computerMark;
        return 1;
    }
    else if(check_SD(box, playerMark) != -1){
        box[check_SD(box, playerMark)] = computerMark;
        return 1;
    }
    return 0;
}

    ///step 3
int choose_the_middle(char box[], int round) {
    char computerMark; ///saves the computer option ( X or 0 )
    if(round == 1)
        computerMark = '0';
    else computerMark = 'X';
///Checks if the middle is empty and marks it
    if(box[5] == '5'){
        box[5] = computerMark;
        return 1;
    }
   return 0;
}

    ///step 4
int choose_corner(char box[], int round, int roundNr) {
    char computerMark; ///saves the computer option ( X or 0 )
    char playerMark;    ///saves the player option ( X or 0 )
    if(round == 1) {
        computerMark = '0';
        playerMark = 'X';
    }
    else {
        computerMark = 'X';
        playerMark = '0';
    }

    if(roundNr == 2){      ///if this is the second round, computer tries to choose a corner
        if(box[1] == '1'){
            box[1] = computerMark;
            return 1;
        }
        else if(box[3] == '3'){
            box[3] = computerMark;
            return 1;
        }
        else if(box[7] == '7'){
            box[7] = computerMark;
            return 1;
        }
        else if(box[9] == '9'){
            box[9] = computerMark;
            return 1;
        }
    }
    else if(roundNr == 4){   /// if this is the 4th round, it's checked a particular case
        if(box[2] == playerMark && box[4] == playerMark){
            if(box[1] == '1'){
                box[1] = computerMark;
                return 1;
            }
            else if(box[3] == '3'){
                box[3] = computerMark;
                return 1;
            }
            else if(box[7] == '7'){
                box[7] = computerMark;
                return 1;
            }
        }
        else if(box[4] == playerMark && box[8] == playerMark){
            if(box[1] == '1'){
                box[1] = computerMark;
                return 1;
            }
            else if(box[7] == '7'){
                box[7] = computerMark;
                return 1;
            }
            else if(box[9] == '9'){
                box[9] = computerMark;
                return 1;
            }
        }
        else if(box[8] == playerMark && box[6] == playerMark){
            if(box[3] == '3'){
                box[3] = computerMark;
                return 1;
            }
            else if(box[7] == '7'){
                box[7] = computerMark;
                return 1;
            }
            else if(box[9] == '9'){
                box[9] = computerMark;
                return 1;
            }
        }
        else if(box[6] == playerMark && box[2] == playerMark){
            if(box[1] == '1'){
                box[1] = computerMark;
                return 1;
            }
            else if(box[3] == '3'){
                box[3] = computerMark;
                return 1;
            }
            else if(box[9] == '9'){
                box[9] = computerMark;
                return 1;
            }
        }
        else if(box[5] == playerMark && box[9] == playerMark){   ///it's checked another particular case
            box[3] = computerMark;
                return 1;
        }
    }
    return 0;
}

    ///step 5
int choose_middle_side(char box[], int round) {
    ///chooses a one of the positions 2, 4, 6 or 8, if this is possible
    char computerMark;///saves the computer option ( X or 0 )
    if(round == 1)
        computerMark = '0';
    else computerMark = 'X';

    if(box[2] == '2'){
        box[2] = computerMark;
        return 1;
    }
    else if(box[6] == '6'){
        box[6] = computerMark;
        return 1;
    }
    else if(box[8] == '8'){
        box[8] = computerMark;
        return 1;
    }
    else if(box[4] == '4'){
        box[4] = computerMark;
        return 1;
    }
    return 0;
}

    ///step 6
int choose_anything(char box[], int round){
    ///if the first 5 steps can not be done, the computer chooses the first empty position
    char computerMark;          ///saves the computer option ( X or 0 )
    char playerMark;            ///saves the player option ( X or 0 )
    if(round == 1) {
        computerMark = '0';
        playerMark = 'X';
    }
    else{
        computerMark = 'X';
        playerMark = '0';
    }

    if (box[1] == '1')
        box[1] = computerMark;

    else if (box[2] == '2')
        box[2] = computerMark;

    else if (box[3] == '3')
        box[3] = computerMark;

    else if (box[4] == '4')
        box[4] = computerMark;

    else if (box[5] == '5')
        box[5] = computerMark;

    else if (box[6] == '6')
        box[6] = computerMark;

    else if (box[7] == '7')
        box[7] = computerMark;

    else if (box[8] == '8')
        box[8] = computerMark;

    else if (box[9] == '9')
        box[9] = computerMark;
    return 0;
}

void player_chooses(char box[], int round, int i){        ///trebe scos int i
    printMap(box);
    char playerMark;                 ///saves the player option ( X or 0 )
    if(round == 1)
        playerMark = 'X';
    else playerMark = '0';

    char choice[100]="";      ///Whatever the user will enter
    int x;
    printf("\n\tPlease enter a position and then press Enter: ");
    scanf("%s", choice);
    while(strlen(choice) != 1 || (strlen(choice) == 1 &&
                ((!(choice[0] >= '1' && choice[0] <= '9')) ||
                ((choice[0] >= '1' && choice[0] <= '9') && box[choice[0]-'0'] != choice[0])))) {
        printf("\n\tPlease enter a position and then press Enter: ");
        scanf("%s", choice);
    }

    int choice_int = choice[0]-'0';        /// the position entered by user
    box[choice_int] = playerMark;         /// the position is marked
}

int computer_move(char box[], int round, int roundNr){
    if(win_if_you_can(box, round))
        return 1;
    else if(block_the_opponent(box, round))
        return 1;
    else if(choose_the_middle(box, round))
        return 1;
    else if(choose_corner(box, round, roundNr))
        return 1;
    else if (choose_middle_side(box, round))
        return 1;
    else choose_anything(box, round);
    return 0;
}


void runVersionB(char box[]) {
    ///This function is the game controller.
    int round;                  /// save the choice of the user (to be the first or the second)
    int did_anyone_won = -1;
    round = startFirstOrSecond();
    if(round == 1){
        for(int i=1; i<=9; i++){             /// There are at most 9 rounds because is a 3x3 matrix
            printMap(box);
            if(i%2 == 1){           ///If the player chooses to be the first, he will choose a position on odd rounds
                player_chooses(box, round, i);
                printMap(box);
                did_anyone_won = check_winner(box);
                if(did_anyone_won == 1){       ///checking if the player won
                    i = 10;
                    int smiley = 002;
                    printf("\tYou won! %c %c %c", smiley, smiley, smiley);
                    printf("\nPress any key to continue. ");
                    getch();
                }
                else if(did_anyone_won == 0){         ///checking if it's a draw
                    printf("\tIt's a draw!\n");
                    printf("\nPress any key to continue. ");
                    getch();
                }
                else{
                    printMap(box);
                }
            }
            else{
                computer_move(box, round, i);       ///The computer makes its choice
                printMap(box);
                did_anyone_won = check_winner(box);
                if(did_anyone_won == 1){        ///checking if the computer won
                    i = 10;
                    int smiley = 002;
                    printf("\tThe computer won! %c %c %c", smiley, smiley, smiley);
                    printf("\nPress any key to continue. ");
                    getch();
                }
                else if(did_anyone_won == 0){     ///checking if it's a draw
                    printf("\tIt's a draw!\n");
                    printf("\nPress any key to continue. ");
                    getch();
                }
                else{
                    printMap(box);
                }
            }
        }
    }
    else if(round == 2){
        for(int i=1; i<=9; i++){    /// There are at most 9 rounds
            if(i%2 == 0){         ///If the player chooses to be the second, he will choose a position on even rounds
                player_chooses(box, round, i);
                printMap(box);
                did_anyone_won = check_winner(box);
                if(did_anyone_won == 1){     ///checking if the player won
                    i = 10;
                    int smiley = 002;
                    printf("\tYou won! %c %c %c", smiley, smiley, smiley);
                    printf("\nPress any key to continue. ");
                    getch();
                }
                else if(did_anyone_won == 0){       ///checking if it's a draw
                    printf("\tIt's a draw!\n");
                    printf("\nPress any key to continue. ");
                    getch();
                }
            }
            else{
                computer_move(box, round, i);      ///The computer makes its choice
                printMap(box);
                did_anyone_won = check_winner(box);
                if(did_anyone_won == 1){         ///checking if the computer won
                    i = 10;
                    int smiley = 002;
                    printf("\tThe computer won! %c %c %c", smiley, smiley, smiley);
                    printf("\nPress any key to continue. ");
                    getch();
                }
                else if(did_anyone_won == 0){        ///checking if it's a draw
                    printf("\tIt's a draw!\n");
                    printf("\nPress any key to continue. ");
                    getch();
                }
            }
        }
    }
}
