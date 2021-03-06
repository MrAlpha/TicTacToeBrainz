#ifndef BRAINZ_H_INCLUDED
#define BRAINZ_H_INCLUDED

#define EMPTY '-'


char brainz(char mat[3][3]);
char checkPlayer(char mat[3][3]);
char checkTurns(char mat [3][3]);
char firstTurn(char mat [3][3], char player, char human);
char secondTurn(char mat [3][3], char player, char human);
char checkWin(char mat [3][3], char checkFor);
char checkBlock(char mat [3][3], char checkFor);
char checkFork(char mat[3][3], char checkFor);
char blockFork(char mat[3][3], char player, char human);
char checkCorner(char mat [3][3],char checkFor);
char checkOppCorner(char mat[3][3], char checkFor);
char checkSideMiddle(char mat [3][3]);
char checkCenter(char mat [3][3], char checkFor);
char checkFieldIsClaimed(char mat[3][3], char field);
char checkTwoInRowPossible(char mat [3][3], char player, char human, char row, char column);

char checkTwoInRow_top(char mat[3][3], char checkFor);
char checkTwoInRow_left(char mat[3][3], char checkFor);
char checkTwoInRow_right(char mat[3][3], char checkFor);
char checkTwoInRow_bottom(char mat[3][3], char checkFor);

char checkTwoInRow_vertGap(char mat[3][3], char checkFor);
char checkTwoInRow_horiGap(char mat[3][3], char checkFor);
char checkTwoInRow_centerGapLeftToRight(char mat[3][3], char checkFor);
char checkTwoInRow_centerGapRightToLeft(char mat[3][3], char checkFor);

char checkTwoInRow_crossGapCorner_rightTop(char mat[3][3], char checkFor);
char checkTwoInRow_crossGapCorner_leftTop(char mat[3][3], char checkFor);
char checkTwoInRow_crossGapCorner_leftBottom(char mat[3][3], char checkFor);
char checkTwoInRow_crossGapCorner_rightBottom(char mat[3][3], char checkFor);
char checkTwoInRow_crossGapCorner_all(char mat[3][3], char checkFor);

char checkTwoInRow_all(char mat[3][3], char checkFor);

#endif // BRAINZ_H_INCLUDED
