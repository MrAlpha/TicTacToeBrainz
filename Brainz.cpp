#include "Brainz.h"

/* Game starts always with player X.

*/
char brainz(char mat[3][3]){
    char player=0, human=0;
    char turns=-1;
    char nextMove=-1;
//    extern state=-1; //defined in Brainz.h

    player=checkPlayer(mat);
    if(player=='X')
        human='O';
    else
        human='X';

    turns=checkTurns(mat);
    if (turns==1&&player=='X'){ //if computer has first move, claim right top corner, as a corner opening move has
        return 2;               //the biggest potential for a wrong move by the opponent.
    }

    if(turns==1&&player=='O'){          //if computer has second move...
        if(checkCorner(mat,human)>0){     //...claim middle square if human has claimed a corner field
            return 4;
        }
        else if(checkCenter(mat,human)>0){ //...claim corner if human has claimed the middle field
            return 6;
        }
        else
            return 4;                   //...claim middle square if human has opened with a side edge square
    }                                   //this two lines of code could be included to the cases above.

    nextMove=checkWin(mat, player);
    if(nextMove>0)
        return nextMove;

    nextMove=checkBlock(mat, human);
    if(nextMove>0)
        return nextMove;
}

//void stateMachine(){
//    switch(extern state){
//    case 1:
//        break;
//
//    case 2:
//        break;
//
//    }
//}

//checkPlayer returns 'X' if computer player is X and 'O' if computer player is O.
char checkPlayer(char mat[3][3]){
    char i=0, j=0;
    char x=0,o=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(mat[i][j]=='X'){
                x++;
            }
            else if(mat[i][j]=='O'){
                o++;
            }
        }
    }
    if(x==o)
        return 'X';
    else
        return 'O';
}

//checkTurns returns the number of turns played previous in the game
char checkTurns(char mat [3][3]){
    char i=0, j=0;
    char x=0,o=0;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(mat[i][j]=='X'){
                x++;
            }
            else if(mat[i][j]=='O'){
                o++;
            }
        }
    }
    if(x>=o)
        return x;
    else
        return o;
}

//checkWin returns the ID of the box the computer player needs to claim to win
char checkWin(char mat [3][3], char checkFor){
    return checkTwoInRow_all(mat, checkFor);
}

//checkBlock returns the ID of the box the computer player needs to claim to block a winning move of the human player
char checkBlock(char mat [3][3], char checkFor){
    return checkTwoInRow_all(mat, checkFor);
}

//checkCorner returns the first corner claimed by checkFor
char checkCorner(char mat [3][3],char checkFor){
    if(mat[0][0]==checkFor){
        return 0;
    }
    if(mat[0][2]==checkFor){
        return 2;
    }
    if(mat[2][0]==checkFor){
        return 6;
    }
    if(mat[0][0]==checkFor){
        return 8;
    }
    return -1;
}

//checkCenter returns 4 if the center field is claimed by checkFor
char checkCenter(char mat [3][3], char checkFor){
    if(mat [1][1]==checkFor)
        return 4;
    else
        return -1;
}

//checkTwoInRow Returns the adjacent empty field of two equal fields in a row or a column.
char checkTwoInRow_top(char mat[3][3], char checkFor){
    char i=0;
    char valReturn=-1;

    for(i=0;i<3;i++){

        if((mat[0][i]== checkFor)&      //check top two rows
           (mat[1][i]== checkFor)&
           (mat[2][i]== EMPTY)){
        valReturn = i+6;
        }
    }
    return valReturn;
}

char checkTwoInRow_left(char mat[3][3], char checkFor){
    char i=0;
    char valReturn=-1;

    for(i=0;i<3;i++){
        if((mat[i][0]==checkFor)&       //check left two columns
           (mat[i][1]==checkFor)&
           (mat[i][2]==EMPTY)){
        valReturn= (i*3)+2;
        }
    }
    return valReturn;
}

char checkTwoInRow_right(char mat[3][3], char checkFor){
    char i=0;
    char valReturn=-1;

    for(i=0;i<3;i++){
        if((mat[i][0]== EMPTY)&        //check right two colums
           (mat[i][1]== checkFor)&
           (mat[i][2]== checkFor)){
        valReturn= (i*3);
        }
    }
    return valReturn;
}

char checkTwoInRow_bottom(char mat[3][3], char checkFor){
    char i=0;
    char valReturn=-1;

    for(i=0;i<3;i++){
        if((mat[0][i]== EMPTY)&        //check bottom two colums
           (mat[1][i]== checkFor)&
           (mat[2][i]== checkFor)){
        valReturn= i;
        }
    }
    return valReturn;
}

char checkTwoInRow_horiGap(char mat[3][3], char checkFor){
    char i=0;
    char valReturn=-1;

    for(i=0;i<3;i++){

        if((mat[0][i]== checkFor)&      //check horizontal gap
           (mat[1][i]== EMPTY)&
           (mat[2][i]== checkFor)){
        valReturn = i+3;
        }
    }
    return valReturn;
}

char checkTwoInRow_vertGap(char mat[3][3], char checkFor){
    char i=0;
    char valReturn=-1;

    for(i=0;i<3;i++){
        if((mat[i][0]==checkFor)&       //check vertical gap
           (mat[i][1]==EMPTY)&
           (mat[i][2]==checkFor)){
        valReturn= (i*3)+1;
        }
    }
    return valReturn;
}

char checkTwoInRow_centerGapLeftToRight(char mat[3][3], char checkFor){
    char valReturn=-1;

        if((mat[0][0]==checkFor)&       //check center cross gap left top to right bottom
           (mat[1][1]==EMPTY)&
           (mat[2][2]==checkFor)){
        valReturn= 4;
        }
        return valReturn;
}

char checkTwoInRow_centerGapRightToLeft(char mat[3][3], char checkFor){
    char valReturn=-1;

        if((mat[0][2]==checkFor)&       //check center cross gap right top to left bottom
           (mat[1][1]==EMPTY)&
           (mat[2][0]==checkFor)){
        valReturn= 4;
        }
        return valReturn;
}

char checkTwoInRow_crossGapCorner_rightTop(char mat[3][3], char checkFor){
    char valReturn=-1;

        if((mat[2][0]==checkFor)&       //check cross corner gap at top right
           (mat[1][1]==checkFor)&
           (mat[0][2]==EMPTY)){
        valReturn= 2;
        }
        return valReturn;
}

char checkTwoInRow_crossGapCorner_leftTop(char mat[3][3], char checkFor){
    char valReturn=-1;

        if((mat[2][2]==checkFor)&       //check cross corner gap at top left
           (mat[1][1]==checkFor)&
           (mat[0][0]==EMPTY)){
        valReturn= 0;
        }
        return valReturn;
}

char checkTwoInRow_crossGapCorner_leftBottom(char mat[3][3], char checkFor){
    char valReturn=-1;

        if((mat[0][2]==checkFor)&       //check cross corner gap at bottom left
           (mat[1][1]==checkFor)&
           (mat[2][0]==EMPTY)){
        valReturn= 6;
        }
        return valReturn;
}

char checkTwoInRow_crossGapCorner_rightBottom(char mat[3][3], char checkFor){
    char valReturn=-1;

        if((mat[0][0]==checkFor)&       //check cross corner gap at bottom right
           (mat[1][1]==checkFor)&
           (mat[2][2]==EMPTY)){
        valReturn= 8;
        }
        return valReturn;
}

char checkTwoInRow_crossGapCorner_all(char mat[3][3], char checkFor){
    char corner=-1, temp =-1;

    temp=checkTwoInRow_crossGapCorner_rightTop(mat, checkFor);
    corner = corner < temp ? temp: corner;
    temp=checkTwoInRow_crossGapCorner_leftTop(mat, checkFor);
    corner = corner < temp ? temp: corner;
    temp=checkTwoInRow_crossGapCorner_rightBottom(mat, checkFor);
    corner = corner < temp ? temp: corner;
    temp=checkTwoInRow_crossGapCorner_leftBottom(mat, checkFor);
    corner = corner < temp ? temp: corner;

    return corner;

}


char checkTwoInRow_all(char mat[3][3], char checkFor){
    char valReturn=-1;
    char temp=-1;

    temp= checkTwoInRow_top(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp=checkTwoInRow_left(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp= checkTwoInRow_right(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp = checkTwoInRow_bottom(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp = checkTwoInRow_horiGap(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp= checkTwoInRow_vertGap(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp= checkTwoInRow_centerGapLeftToRight(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp= checkTwoInRow_centerGapRightToLeft(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    temp= checkTwoInRow_crossGapCorner_all(mat, checkFor);
    valReturn = valReturn < temp ? temp: valReturn;

    return valReturn;
}
