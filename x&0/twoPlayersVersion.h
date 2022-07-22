/**************************************************************************/
/** playerVScomputer.c - program for two player game version             **/
/** University: Technical University of Cluj-Napoca                      **/
/** Author: Daria Lupu Dima                                              **/
/** Version:  4.01.2021                                                  **/
/**************************************************************************/

#ifndef TWOPLAYERSVERSION_H_INCLUDED
#define TWOPLAYERSVERSION_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h> ///merge si fara dar e consola care are functia de clear screen

extern int check_winner(char[]); /// nu imi merge cu void
extern void printMap(char[]);
extern int player_number(); ///a function that shows the number of the player so basically the turns
extern char sign(); /// a function that gives 'X' and '0'
extern void choosePosition(char[], int, char, int*);
extern void runVersionA(char[]);

#endif // TWOPLAYERSVERSION_H_INCLUDED
