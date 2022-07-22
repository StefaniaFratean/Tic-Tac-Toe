/**************************************************************************/
/** computerChecks.h - Header file for movement check program (computer) **/
/** University: Technical University of Cluj-Napoca                      **/
/** Author: Stefania Fratean                                             **/
/** Version:  4.01.2021                                                  **/
/**************************************************************************/

#ifndef COMPUTERSCHECKS_H_INCLUDED
#define COMPUTERSCHECKS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

extern int check_row(int, char[], char);
extern int check_column(int, char[], char);
extern int check_PD(char[], char);
extern int check_SD(char[], char);

#endif // COMPUTERSCHECKS_H_INCLUDED
