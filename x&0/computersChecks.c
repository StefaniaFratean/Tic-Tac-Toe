/**************************************************************************/
/** computerChecks.c - Program for movement check (computer)             **/
/** University: Technical University of Cluj-Napoca                      **/
/** Author: Stefania Fratean                                             **/
/** Version:  4.01.2021                                                  **/
/**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "computersChecks.h"
#include "playerVScomputer.h"


int check_row(int first_elem_in_row, char box[], char mark) {
    /// Methods for checking the map ( box )
    ///checks if the first two elements are marked and returns the third one
    if(box[first_elem_in_row] == mark && box[first_elem_in_row+1] == mark && box[first_elem_in_row+2]-'0' == first_elem_in_row+2){
        return first_elem_in_row+2;
    }
    ///checks if the first and the third elements are marked and returns the second one
    else if(box[first_elem_in_row] == mark && box[first_elem_in_row+2] == mark && box[first_elem_in_row+1]-'0' == first_elem_in_row+1){
        return first_elem_in_row+1;
    }
    ///checks if the second and the third elements are marked and returns the third one
    else if(box[first_elem_in_row+1] == mark && box[first_elem_in_row+2] == mark && box[first_elem_in_row]-'0' == first_elem_in_row){
        return first_elem_in_row;
    }
    return -1;
}

int check_column(int first_elem_in_col, char box[], char mark) {
    ///checks if the first two elements are marked and returns the third one
    if(box[first_elem_in_col] == mark && box[first_elem_in_col+3] == mark && box[first_elem_in_col+6]-'0' == first_elem_in_col+6){
        return first_elem_in_col+6;
    }
    ///checks if the first and the third elements are marked and returns the second one
    else if(box[first_elem_in_col] == mark && box[first_elem_in_col+6] == mark && box[first_elem_in_col+3]-'0' == first_elem_in_col+3){
        return first_elem_in_col+3;
    }
    ///checks if the second and the third elements are marked and returns the third one
    else if(box[first_elem_in_col+3] == mark && box[first_elem_in_col+6] == mark && box[first_elem_in_col]-'0' == first_elem_in_col){
        return first_elem_in_col;
    }
    return -1;
}

int check_PD(char box[], char mark) {
    ///Checks the principal diagonal
    if(box[1] == mark && box[5] == mark && box[9] == '9'){
        return 9;
    }
    else if(box[1] == mark && box[9] == mark && box[5] == '5'){
        return 5;
    }
    else if(box[5] == mark && box[9] == mark && box[1] == '1'){
        return 1;
    }
    return -1;
}

int check_SD(char box[], char mark) {
    ///Checks the secondary diagonal
    if(box[3] == mark && box[5] == mark && box[7] == '7'){
        return 7;
    }
    else if(box[3] == mark && box[7] == mark && box[5] == '5'){
        return 5;
    }
    else if(box[5] == mark && box[7] == mark && box[3] == '3'){
        return 3;
    }
    return -1;
}
