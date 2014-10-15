#include "Brainz.h"

/* Game starts always with player X.

    |0|1|2|
    |3|4|5|
    |6|7|8|
*/
char brainz(char mat[3][3]){
    char player=0, human=0;
    char turns=-1;
//    char nextMove=-1;

    player=checkPlayer(mat);
    if(player=='X')
        human='O';
    else
        human='X';

    turns=checkTurns(mat);
    if(turns==0){
        return firstTurn(mat, player, human);
    }
    else if(turns==1){
        return secondTurn(mat,player,human);
    }
    else if (checkWin(mat, player)>0){
        return checkWin(mat, player);
    }
    else if(checkBlock(mat, human)>0){
        return checkBlock(mat, human);
    }
    else if(checkFork(mat,player)>=0){
        return checkFork(mat,player);
    }
    else if(blockFork(mat, player, human)>=0){
        return blockFork(mat, player, human);
    }
    else if(checkCenter(mat,EMPTY)>0){
        return 4;
    }
    else if(checkOppCorner(mat,human)>=0){
        return checkOppCorner(mat,human);
    }
    else if(checkCorner(mat,EMPTY)>0){
        return checkCorner(mat,EMPTY);
    }

    else if(checkSideMiddle(mat)>0){
        return checkSideMiddle(mat);
    }
    else{
        for(int i=0;i<9;i++){
            if(checkFieldIsClaimed(mat,i)!=EMPTY){
                return i;
            }
        }
    }
//    else
//        return -1;
}

//checkPlayer returns 'X' if computer player is X and 'O' if computer player is O.
char checkPlayer(char mat[3][3]){
    unsigned char i=0, j=0;                  //as Player X always begins, the Program can determine if it plays X or O
    unsigned char x=0,o=0;
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
    unsigned char i=0, j=0;
    unsigned char x=0,o=0;
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
        return x;
    else if (x<o)   //????????????????????????????? shouldn't be possible
        return x;
    else
        return o;
}

//firstTurn returns the opening move or the move responding to a human opening move
char firstTurn(char mat [3][3], char player, char human){

    if (player=='X'){           //if computer has first move, claim right top corner, as a corner opening move has
        return 2;               //the biggest potential for a wrong move by the opponent.
    }

    if(player=='O'){                      //if computer has second move...
        if(checkCorner(mat,human)>=0){     //...claim middle square if human has claimed a corner field
            return 4;
        }
        else if(checkCenter(mat,human)>0){ //...claim corner if human has claimed the middle field
            return 6;
        }
        else
            return 4;                   //...claim middle square if human has opened with a side edge square
    }                                   //this two lines of code could be included to the cases above.

}

//secondTurn returns the move of the computer in the second turn
char secondTurn(char mat [3][3], char player, char human){
    if (player=='X' && (checkCenter(mat, human)>0)){          //if computer is X and human played center in first turn
        return 6;                                           //claim opposite corner of own first claim.
    }

    else if (player=='X' && checkCorner(mat, human)>0){     //if computer is X and human played a corner(human is gonna
        int n=0, o=0;                                       //lose!) claim an other corner.
        while(n<9){
            if(checkFieldIsClaimed(mat,n)==EMPTY)
            return n;

            n+=2+((o%2)*2); //Produces 0,2,6,8 which are the corner fields.
            o++;
        }
    }

    else if (player=='X'){                                  //if computer is X and human played a side field in first turn
        int n=0, o=0;                                       //human is gonna loose!
        char toTestAgainst[3][3];

        for(int i=0;i<3;i++){                                   //
            for(int j=0;j<3;j++){
                toTestAgainst[i][j]=mat[i][j];
            }
        }

        while(n<9){
            if(checkFieldIsClaimed(mat,n)==EMPTY){  //if field is not claimed write X to test copy of game board and check if...
                toTestAgainst[n/3][n%3]='X';

                char positionNextBlockMove=checkBlock(mat,'O');     //..blocking move of O..

                toTestAgainst[positionNextBlockMove/3][positionNextBlockMove%3]='O';
                if(checkWin(toTestAgainst,'O')<0)                                       //..would produce 2 in a row for O.
                    return n;                                                       //if not claim this field.
            }

            n+=2+((o%2)*2); //Produces 0,2,6,8 which are the corner fields.
            o++;
        }
    }

    else if(player=='O'&&(checkCenter(mat,'X')<0)){         //if humans very first move was not center,
            char temp=checkWin(mat,'X');                     //take a side square.

            if(temp>0){
                return temp;
            }
            else{
                return checkSideMiddle(mat);
            }
    }
    //????????????????????????????????????????????????????????????????? finished yet??? wenn computer O und oben trifft
    //nicht zu, dann normal weiter. Noch implementieren!!!!
}

//checkWin returns the ID of the box the computer player needs to claim to win
char checkWin(char mat [3][3], char checkFor){
    return checkTwoInRow_all(mat, checkFor);
}

//checkBlock returns the ID of the box the computer player needs to claim to block a winning move of the human player
char checkBlock(char mat [3][3], char checkFor){
    return checkTwoInRow_all(mat, checkFor);
}

//checkFork returns the ID of the field player checkFor has to claim to produce a fork
char checkFork(char mat[3][3], char checkFor){

    char player, human;
    char own=0, opponent=0;
    char row[3]={-1, -1, -1}, column[3]={-1, -1, -1};
    char lToR=0, rToL=0;
    unsigned char index=0;
    char row_temp=-1, column_temp=-1;

    player=checkFor;
    if(player=='X')
        human='O';
    else
        human='X';

    for(int i=0;i<3;i++){                   //check if row is candidate for fork, if so write row to row array
        own=0;
        opponent=0;

        for(int j=0;j<3;j++){
            if(mat[i][j]==player){
                own++;
            }
            else if(mat[i][j]==human){
                opponent++;
            }
        }
        if(own==1&&opponent==0){
            row[index]=i;
            index++;
        }
    }

    index=0;

     for(int i=0;i<3;i++){                   //check if column is candidate for a fork, if so write column to col. array
        own=0;
        opponent=0;

        for(int j=0;j<3;j++){
            if(mat[j][i]==player){
                own++;
            }
            else if(mat[j][i]==human){
                opponent++;
            }
        }
        if(own==1&&opponent==0){
            column[index]=i;
            index++;
        }
    }

    for(int i=0;i<3;i++){                   //check all crossings between marked rows and columns
        if(row[i]>-1){                      //if field where crossing occurs is claimed ->discard, else field is valid
            row_temp=row[i];
        }
        for(int j=0;j<3;j++){
            if(column[j]>-1){
                column_temp=column[j];
            }
            if(row_temp>=0 && column_temp>=0 && checkFieldIsClaimed(mat,row_temp*3+column_temp)==EMPTY){
                return row_temp*3+column_temp;
            }
        }
    }

    own=0;
    opponent=0;
    for(int i=0;i<9;i+=4){                  //check if left to right diagonal is candidate for a fork,
        if(checkFieldIsClaimed(mat,i)==player){
            own++;
        }
        else if(checkFieldIsClaimed(mat,i)==human){
            opponent++;
        }
    }
    if(own==1&&opponent==0){
        lToR=1;
    }

    own=0;
    opponent=0;
    for(int i=2;i<7;i+=2){                  //check if right to left diagonal is candidate for a fork,
        if(checkFieldIsClaimed(mat,i)==player){
            own++;
        }
        else if(checkFieldIsClaimed(mat,i)==human){
            opponent++;
        }
    }
    if(own==1&&opponent==0){
        rToL=1;
    }



    if(lToR==1){                            //check crossings between LEFT to right diagonal and marked rows and columns
        for(int i=0;i<3;i++){
            if(row[i]>-1){
                if(checkFieldIsClaimed(mat,row[i]*4)==EMPTY){
                    return row[i]*4;
                }
            }
        }

        for(int i=0;i<3;i++){
            if(column[i]>-1){
                if(checkFieldIsClaimed(mat,column[i]*4)==EMPTY){
                    return column[i]*4;
                }
            }
        }
    }

    if(rToL==1){                            //check crossings between RIGHT to left diagonal and marked rows and columns
        for(int i=0;i<3;i++){
            if(row[i]>-1){
                if(checkFieldIsClaimed(mat,row[i]*2+2)==EMPTY){
                    return row[i]*2+2;
                }
            }
        }

        for(int i=0;i<3;i++){
            if(column[i]>-1){
                if(checkFieldIsClaimed(mat,6-column[i]*2)==EMPTY){
                    return 6-column[i]*2;
                }
            }
        }
    }

    return -1;
}

//blockFork checks if opponent has the chance to fork, if so returns the field ID to block fork or to produce own two in a row
char blockFork(char mat[3][3], char player, char human){
    if(checkFork(mat,human)>=0){
        if(checkTwoInRow_all(mat, player)>=0){
            return checkTwoInRow_all(mat, player);
        }
        else{
            return checkFork(mat, human);
        }
    }
    return -1;
}
//checkCorner returns the first corner claimed by checkFor
char checkCorner(char mat [3][3],char checkFor){
    int i=0,j=0;
    while(i<9){
            if(checkFieldIsClaimed(mat,i)==checkFor){
                return i;
            }
            i+=2+((j%2)*2); //Produces 0,2,6,8 which are the corner fields.
            j++;
    }

    return -1;
}

//checkOppCorner returns the first not yet claimed corner which is opposite of a corner claimed by checkFor
char checkOppCorner(char mat[3][3], char checkFor){
    int i=0,j=0;
    while(i<9){
            if(checkFieldIsClaimed(mat,i)==checkFor){
                if(checkFieldIsClaimed(mat,8-i)==EMPTY)     //8-ID of current field gives opposite field
                    return 8-i;
            }
            i+=2+((j%2)*2); //Produces 0,2,6,8 which are the corner fields.
            j++;
    }

    return -1;
}
//checkSideMiddle returns the ID of the first not claimed side middle field. if all side middle fields are claimed returns -1.
char checkSideMiddle(char mat [3][3]){
    for(int i=1;i<8;i+=2){
        if(checkFieldIsClaimed(mat,i)==EMPTY)
            return i;
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

//checkFieldIsClaimed returns EMPTY if Field is not already claimed else it returns the player who claimed it
char checkFieldIsClaimed(char mat[3][3], char field){
    if(mat[field/3][field%3]==EMPTY)
        return EMPTY;
    else if(mat[field/3][field%3]=='X')
        return 'X';
    else
        return 'O';
}

//checkTwoInRow Returns the adjacent empty field of two equal fields in a row or a column.
char checkTwoInRow_top(char mat[3][3], char checkFor){
    unsigned char i=0;
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
    unsigned char i=0;
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
    unsigned char i=0;
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
    unsigned char i=0;
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
    unsigned char i=0;
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
    unsigned char i=0;
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
