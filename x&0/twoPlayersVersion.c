/**************************************************************************/
/** playerVScomputer.c - program for two player game version             **/
/** University: Technical University of Cluj-Napoca                      **/
/** Author: Stefania Fratean                                               **/
/** Version:  4.01.2021                                                  **/
/**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "twoPlayersVersion.h"

///function so you can choose a place in the box for your "X" or "0"

void choosePosition(char box[], int choice, char game_value, int *player) {

  ///this if statement returns to the player that inserted a wrong value and does not permit the game to go to the next player
    if(player==1)
     if((scanf("%d", &choice)!=1) || (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6 && choice!=7 && choice!=8 && choice!=9))
            *player = player_number(*player)-1;



    if (choice == 1 && box[1] == '1')
        box[1] = game_value;

    else if (choice == 2 && box[2] == '2')
        box[2] = game_value;

    else if (choice == 3 && box[3] == '3')
        box[3] = game_value;

    else if (choice == 4 && box[4] == '4')
        box[4] = game_value;

    else if (choice == 5 && box[5] == '5')
        box[5] = game_value;

    else if (choice == 6 && box[6] == '6')
        box[6] = game_value;

    else if (choice == 7 && box[7] == '7')
        box[7] = game_value;

    else if (choice == 8 && box[8] == '8')
        box[8] = game_value;

    else if (choice == 9 && box[9] == '9')
        box[9] = game_value;

    else {
        printf("Invalid move ");

        *player = player_number(*player)-1;

        printf("\nPress any key to continue.");
        getch(); /// this is so that the player can input a key to continue

    }

}

///function to check if the the game is over or not, returning 1 if the game is over and a player won, 0 if it is a tie and -1 if the game is not over yet

int check_winner(char box[])
{
    if (box[1] == box[2] && box[2] == box[3])
        return 1;

    else if (box[4] == box[5] && box[5] == box[6])
        return 1;

    else if (box[7] == box[8] && box[8] == box[9])
        return 1;

    else if (box[1] == box[4] && box[4] == box[7])
        return 1;

    else if (box[2] == box[5] && box[5] == box[8])
        return 1;

    else if (box[3] == box[6] && box[6] == box[9])
        return 1;

    else if (box[1] == box[5] && box[5] == box[9])
        return 1;

    else if (box[3] == box[5] && box[5] == box[7])
        return 1;

    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' && box[4] != '4' && box[5] != '5' && box[6] != '6' && box[7] != '7' && box[8] != '8' && box[9] != '9')
        return 0;
    else
        return  - 1;
}

///function that assigns a number to a player (turns for the game)
int player_number(int p)
{
     if (p % 2 == 0)
        {
            p = 2;

        } else p = 1;
    return p;
}

///function that gives the player "X" or "0"
char sign(int p)
{
    char m;
    if(p == 1)
            m = 'X';
        else m = 'O';

    return m;
}

///function to run the two player version of the game
void runVersionA(char box[]){
    int i = 0, player = 1, choice = 0;
    int x;
    char game_value;

    ///this makes the game repeat until the function check_winner gives the value -1 (game is over)
    do
    {
        printMap(box);
        player = player_number(player);

        printf("Player %d, enter a number:  ", player);
        x = scanf("%d", &choice);
        if(x==0) ///with this if statement the program ignores a value if it is a character
            {
                scanf("%*s");
            }


        game_value = sign(player);

        choosePosition(box, choice, game_value, &player);
        i = check_winner(box);
        player++;

    }while (i == - 1);

     printMap(box);

    if (i == 1)
        {
            int smiley = 002;
            printf("\tPlayer %d won! %c %c %c", --player, smiley, smiley, smiley);
            printf("\nPress any key to continue. ");
        }
    else
        {printf("\tGame draw");
        printf("\nPress any key to continue. ");}

    getch();
}
