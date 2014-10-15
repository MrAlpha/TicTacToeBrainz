#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Brainz.h"

void printBoard(char playboard [3][3]);
char evaluation(char game_mat[3][3]);
void setMove(char playboard[3][3], char field, char mark);
char game(char playboard[3][3], int *wins, int *draw);

using namespace std;


int main(){

    int iter=100, games=0;
    char playboard [3][3]= {{'-','-','-'},
                            {'-','-','-'},
                            {'-','-','-'}};

    srand(time(NULL));
    int wins=0, draw=0;

    while(iter-games){
        playboard ={{'-','-','-'},
                    {'-','-','-'},
                    {'-','-','-'}};

        if(game(playboard, &wins, &draw)==-1){
            cout<<"ERROR"<<endl;
        }

        games++;
        cout<<"Game "<<games<<endl;
    }

    cout<<wins<<" Wins and "<<draw<<" Draws"<<endl;

    return 0;
}

char game(char playboard[3][3], int *wins, int *draw){
    char hMove;
    char check=0;

    while (1){
        check=0;
        while(check==0){                                        //set simulated human mark on playfield
            hMove=rand()%9;
            if(checkFieldIsClaimed(playboard, hMove)==EMPTY){
                setMove(playboard, hMove, 'X');
                check=1;
            }
        }
        if(brainz(playboard)!=-1){                              //set mark belonging to da brainz
            setMove(playboard,brainz(playboard),'O');
        }
        else
            return -1;

        printBoard(playboard);

        if(evaluation(playboard)==-2){                          //write some statistics
            *draw+=1;
            return 1;
        }
        else if(evaluation(playboard)=='O'){
            *wins+=1;
            return 1;
        }
        else if(evaluation(playboard)=='X')
            return -1;
//        else
//            return -1;
    }
}

void setMove(char playboard[3][3], char field, char mark){
    playboard[field/3][field%3]=mark;
}

void printBoard(char playboard [3][3]){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout<<"|"<<playboard[i][j];
        }
        cout<<"|"<<endl;
    }
    cout<<endl;
}

char evaluation(char game_mat[3][3]){
    char winner = -1;
    char unclaimed=0;
//search for a winner
	for(int a =0; a <= 2; a++){
		if((game_mat[a][0] == game_mat[a][1]) && (game_mat[a][1] == game_mat[a][2])){ //evaluation vertical
			winner = game_mat[a][0];
		};
		if((game_mat[0][a] == game_mat[1][a]) && (game_mat[1][a] == game_mat[2][a])){ //evaluation horizontal
			winner = game_mat[0][a];
		};
	};
	if((game_mat[0][2] == game_mat[1][1]) && (game_mat[1][1] == game_mat[2][0])){ //evaluation diagonal
		winner = game_mat[1][1];
	};
	if((game_mat[0][0] == game_mat[1][1]) && (game_mat[1][1] == game_mat[2][2])){ //evaluation diagonal
		winner = game_mat[1][1];
	};
    if(winner!=-1){
        return winner;
    }
//search for a draw
	for(int i=0; i<9; i++){
        if(checkFieldIsClaimed(game_mat,i)==EMPTY){
            unclaimed++;
        }
	}
	if(unclaimed==0)    //return -2 if draw is detected
        winner=-2;
return winner;
//clear command line
//system("cls");
// aaaand the winner is....
//cout << " Tic Tac Toe feld an die Kamera halten und die Erkennung beginnt!!!" << endl << endl;
//	if(winner == '0') std::cout << "There is still no winner!" << endl;
//	else std::cout << "The winner is : << " << winner << " >>" << endl;
//// show matrix
//	for(short a =0; a <= 2; a++){
//		for(short b =0;b <= 2; b++){
//			if(!((game_mat[a][b] == 'X') || (game_mat[a][b] == 'O'))) game_mat[a][b]='-'; // clear empty places
//			std::cout << game_mat[a][b] << ' '; // show matrix
//			game_mat[a][b] = '0'+3*a+b; // clear matrix
//		}
//		std::cout << endl;
//	}
}
