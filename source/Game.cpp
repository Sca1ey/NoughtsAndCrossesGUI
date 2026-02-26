#include <stdio.h>
#include <iostream>
#include <limits>
#include "Game.h"

void Game::InitBoard(){
    for (int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++){
            board[x][y] = 0;
        }
    }
}

Game::Game(){};

int Game::GetPosition(int x, int y)
{
    return board[x][y];
};

void Game::SetPosition(int x, int y, int state)
{
    board[x][y] = state;
}

bool Game::CheckWin()
{
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

int Game::GetPlayer()
{
    return player;
}

int Game::SwitchPlayer()
{
    if(player == 1){player = 2;} else {player = 1;}
    return player;
};