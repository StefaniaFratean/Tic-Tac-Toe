/******************************************************/
/** menu.h - Header file for module menu             **/
/** University: Technical University of Cluj-Napoca  **/
/** Authors: Stefania Fratean, Daria Lupu Dima       **/
/** Version:  4.01.2021                              **/
/******************************************************/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

extern void printMenu();
extern int getGameType(char []);
extern void reset_box(char[]);
extern void play_game(char[]);

#endif // MENU_H_INCLUDED
