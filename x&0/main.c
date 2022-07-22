/******************************************************/
/** Complex application - main program               **/
/** University: Technical University of Cluj-Napoca  **/
/** Authors: Stefania Fratean                        **/
/** Version:  4.01.2021                              **/
/******************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "playerVScomputer.h"
#include "twoPlayersVersion.h"

#define DIMENSION 3

int main()
{
    char box[10]={'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    play_game(box);


    return 0;
}

