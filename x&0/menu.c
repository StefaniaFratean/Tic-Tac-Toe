/******************************************************/
/** menu.c - Program for module menu                 **/
/** University: Technical University of Cluj-Napoca  **/
/** Authors: Stefania Fratean,                       **/
/** Version:  4.01.2021                              **/
/******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "twoPlayersVersion.h"
#include "playerVScomputer.h"


void printMenu() {
    printf("Hello! This is a Tic Tac Toe game. It has two versions. You can play with a friend or against the computer.\n");
    printf("Choose an option: \n");
    printf("   1 - play with a friend\n");
    printf("   2 - play against the computer\n");
    printf("   3 - exit\n");
    printf("Your option is: ");
}

int getGameType(char box[]) {
    char choice[100]="";
    scanf("%s", choice);

    while((strlen(choice) != 1) || (strlen(choice) == 1 && (choice[0] != '1' && choice[0] != '2' && choice[0] != '3'))) {
        printf("\n\tPlease enter only 1, 2 or 3 and then press Enter: ");
        scanf("%s", choice);
    }
    if(choice[0] == '1') {
        return 1;
    } else if(choice[0] == '2') {
        return 2;
    } else {
        return 3;
    }
}

void reset_box(char box[]){
    for(int i=1; i<=9; i++) {
        box[i] = i + '0';
    }
}

void play_game(char box[]){

    int gameType = 0;

    do {
        printMenu();
        gameType = getGameType(box);
        if(gameType == 1){
            runVersionA(box);
        } else if(gameType == 2){
            runVersionB(box);
        }
        system("cls");
        reset_box(box);
    } while(gameType != 3);

}

