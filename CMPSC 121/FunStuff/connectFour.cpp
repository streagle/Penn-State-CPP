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

// Methods
void displayMenu()
{
    cout << "Connect Four" << endl;
    cout << "1. Start Game" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter your choice: ";
}

void displayBoard(char board[6][7])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(char board[6][7], char player)
{
    // Check horizontal win
    for (int row = 0; row < 6; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (board[row][col] == player && board[row][col + 1] == player &&
                board[row][col + 2] == player && board[row][col + 3] == player)
            {
                return true;
            }
        }
    }

    // Check vertical win
    for (int col = 0; col < 7; col++)
    {
        for (int row = 0; row < 3; row++)
        {
            if (board[row][col] == player && board[row + 1][col] == player &&
                board[row + 2][col] == player && board[row + 3][col] == player)
            {
                return true;
            }
        }
    }

    // Check diagonal (bottom-left to top-right) win
    for (int row = 3; row < 6; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (board[row][col] == player && board[row - 1][col + 1] == player &&
                board[row - 2][col + 2] == player && board[row - 3][col + 3] == player)
            {
                return true;
            }
        }
    }

    // Check diagonal (top-left to bottom-right) win
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (board[row][col] == player && board[row + 1][col + 1] == player &&
                board[row + 2][col + 2] == player && board[row + 3][col + 3] == player)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    // Variables
    int choice;
    int player = 1;
    int playerChoice;
    bool gameOver = false;
    char board[6][7] = {{' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    // Inputs
    do
    {
        displayMenu();
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 2)
        {
            cout << "Invalid choice. Please enter a number between 1 and 2." << endl;
        }

        if (choice == 1 || cin)
        {
            do
            {
                displayBoard(board);

                do
                {
                    cout << "Player " << player << " enter your choice (1-7): ";
                    cin >> playerChoice;

                    if (cin.fail() || playerChoice < 1 || playerChoice > 7)
                    {
                        cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                    }
                } while (playerChoice < 1 || playerChoice > 7 || cin.fail());

                for (int i = 5; i >= 0; i--)
                {
                    if (board[i][playerChoice - 1] == ' ')
                    {
                        if (player == 1)
                        {
                            board[i][playerChoice - 1] = 'X';

                            if (checkWin(board, 'X'))
                            {
                                displayBoard(board);
                                cout << "Player 1 wins!" << endl;
                                gameOver = true;
                            }

                            player = 2;
                        }
                        else
                        {
                            board[i][playerChoice - 1] = 'O';

                            if (checkWin(board, 'O'))
                            {
                                displayBoard(board);
                                cout << "Player 2 wins!" << endl;
                                gameOver = true;
                            }

                            player = 1;
                        }
                        break;
                    }
                }
            } while (gameOver == false);
        }

        if (choice == 2)
        {
            cout << "Quitting the program." << endl;
            break;
        }
    } while (!cin.fail() || choice < 1 || choice > 2);

    return 0;
}