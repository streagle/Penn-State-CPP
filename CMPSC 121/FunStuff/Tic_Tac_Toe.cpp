//This project is a game of tic-tac-toe with a working AI as an opponent

//TODO: Add a way to play again
//TODO: Make the AI harder to beat


#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>
#include <stack>
#include <queue>
#include <random>
#include <ctime>

using namespace std;
//Methods

//Game Board
void gameBoard(char board[3][3]){
    cout << "  0 1 2" << endl;
    for (int i = 0; i < 3; i++){
        cout << i << " ";
        for (int j = 0; j < 3; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

//Check for winner
bool checkWinner(char board[3][3], char player){
    //Check rows
    for (int i = 0; i < 3; i++){
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player){
            return true;
        }
    }
    //Check columns
    for (int i = 0; i < 3; i++){
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player){
            return true;
        }
    }
    //Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player){
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player){
        return true;
    }
    return false;
}

bool checkTie(char board[3][3]){
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

//AI
void ai(char board[3][3]){
    //Random number generator
    srand(time(0));
    int row = rand() % 3;
    int col = rand() % 3;
    while (board[row][col] != ' '){
        row = rand() % 3;
        col = rand() % 3;
    }
    board[row][col] = 'O';
}



int main(){
//Variables
char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
char player = 'X';
bool winner = false;

//Game Loop

while (!winner){
    //Game Board
    gameBoard(board);
    //Player Input
    int row, col;
    cout << "Enter row: ";
    cin >> row;
    cout << "Enter column: ";
    cin >> col;
    if (board[row][col] == ' '){
        board[row][col] = player;
    }
    else{
        cout << "Invalid move" << endl;
        continue;
    }
    //Check for winner
    winner = checkWinner(board, player);
    if (winner){
        cout << "Player " << player << " wins!" << endl;
        gameBoard(board);
        break;
    }
    //check for tie
    if (checkTie(board)){
        cout << "Tie game!" << endl;
        gameBoard(board);
        break;
    }
    //AI
    ai(board);
    //Check for winner
    winner = checkWinner(board, 'O');
    if (winner){
        cout << "Player O wins!" << endl;
        gameBoard(board);
        break;
    }
    //check for tie
    if (checkTie(board)){
        cout << "Tie game!" << endl;
        gameBoard(board);
        break;
    }
}


return 0;
}