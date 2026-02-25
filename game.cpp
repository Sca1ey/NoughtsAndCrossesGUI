#include <stdio.h>
#include <iostream>
#include <limits>



class Game {

    public:

        void initBoard(){
            for (int y = 0; y < 3; y++){
                for (int x = 0; x < 3; x++){
                    board[x][y] = 0;
                }
            }
        }

        int getPosition(int x, int y){
            return board[x][y];
        };

        void setPosition(int x, int y, int state){
            board[x][y] = state;
        }

        bool checkWin(){
            for (int i = 0; i < 8; i++){
                int winLine[3];
                for (int j = 0; j < 3; j++){
                    winLine[j] = board[ winLines[i][j][0] ][ winLines[i][j][1] ];
                }
                if(winLine[0] != 0 && winLine[0] == winLine[1] && winLine[0] == winLine[2]){                 
                    return true;
                }
            }
        return false;
        }

        int getPlayer(){
            return player;
        }

        int switchPlayer(){
            if(player == 1){player = 2;} else {player = 1;}
            return player;
        }

    private:

        int player = 1;

        int board[3][3];
        
        int winLines[8][3][2] = {
            {{0,0},{0,1},{0,2}},
            {{1,0},{1,1},{1,2}},
            {{2,0},{2,1},{2,2}},
            {{0,0},{1,0},{2,0}},
            {{0,1},{1,1},{2,1}},
            {{0,2},{1,2},{2,2}},
            {{0,0},{1,1},{2,2}},
            {{2,0},{1,1},{0,2}}
        };
};