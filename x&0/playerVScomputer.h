/**************************************************************************/
/** playerVScomputer.h - Header file for player vs computer game version **/
/** University: Technical University of Cluj-Napoca                      **/
/** Author: Stefania Fratean                                             **/
/** Version:  4.01.2021                                                  **/
/**************************************************************************/

#ifndef PLAYERVSCOMPUTER_H_INCLUDED
#define PLAYERVSCOMPUTER_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

extern int startFirstOrSecond();

extern int win_if_you_can(char[], int);
extern int block_the_opponent(char[], int);
extern int choose_the_middle(char[], int);
extern int choose_corner(char[], int, int);
extern int choose_middle_side(char[], int);
extern int choose_anything(char[], int);

extern void player_chooses(char[], int, int); ///trebe scos ultimul int
extern int computer_move(char[], int, int);
extern void runVersionB(char[]);


#endif // PLAYERVSCOMPUTER_H_INCLUDED
