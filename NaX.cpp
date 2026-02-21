#include <stdio.h>
#include <iostream>
#include <limits>

enum PositionState {
    EMPTY,
    NOUGHT,
    CROSS
};

class Game {

    public:

        void initBoard(){
            for (int y = 0; y < 3; y++){
                for (int x = 0; x < 3; x++){
                    board[x][y] = EMPTY;
                }
            }
        }

        void displayBoard(){

        std::cout << "\n\t1\t2\t3\n\n";

        for (int y = 0; y < 3; y++){

            std::cout << y+1;

                for (int x = 0; x < 3; x++){


                    switch(getPosition(x,y)){
                        case 1:
                            std::cout << "\tO";
                            break;
                        case 2:
                            std::cout << "\tX";
                            break;
                        default:
                            std::cout << "\t.";
                    }
                    if(x == 2){ std::cout << "\n\n";}
                }
            }
        }

        PositionState getPosition(int x, int y){
            return board[x][y];
        };

        void setPosition(int x, int y, PositionState state){
            board[x][y] = state;
        }

        bool checkWin(){
            for (int i = 0; i < 8; i++){
                int winLine[3];
                for (int j = 0; j < 3; j++){
                    winLine[j] = board[ winLines[i][j][0] ][ winLines[i][j][1] ];
                }
                if(winLine[0] != EMPTY && winLine[0] == winLine[1] && winLine[0] == winLine[2]){
                    std::cout <<"\nPlayer " << winLine[0] << " wins!\n";
                    displayBoard(); 
                    return true;
                }
            }
        return false;
        }

    private:
        PositionState board[3][3];
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

int main(){
    
    std::cout << "Noughts and Crosses\n\n";
    
    Game game = Game();
    game.initBoard();
        
    bool run = true;
    PositionState player = NOUGHT;
    int turns = 0;
    while(run){

        bool takingTurn = true;
        do{
            game.displayBoard();       
            int posx = 0, posy = 0;
            std::cout << "\nPlayer "<< player <<", enter a column (1-3) then Enter: ";
            std::cin >> posx;

            if (std::cin.fail()) {
                std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            std::cout << "\nand a row (1-3) then Enter: ";
            std::cin >> posy;

            if (std::cin.fail()) {
                std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if(posx > 0 && posx < 4 && posy > 0 && posy < 4 && game.getPosition(posx-1,posy-1) == EMPTY){
                game.setPosition(posx-1,posy-1,player);
                takingTurn = false;
            } else {
                std::cout << "\nInvalid square, try again!\n\n";
                continue;
            }
        } while (takingTurn);

        run = !game.checkWin();

        if (player == NOUGHT) {player = CROSS;} else {player = NOUGHT;};

        turns++;
        if(turns == 9){
            std::cout << "\nStalemate - no one wins!";
            run = false;
        }
              
    }

    return 0;
}
