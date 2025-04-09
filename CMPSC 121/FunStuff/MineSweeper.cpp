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




char keep_playing = 'y';

// Function to display the game board
void displayBoard(char **board, char **revealed, int rows, int columns)
{
    cout << "    "; // Add extra space for alignment
    for (int j = 0; j < columns; j++)
    {
        cout << setw(3) << j + 1; // Use setw(3) for consistent spacing
    }
    cout << endl;

    for (int i = 0; i < rows; i++)
    {
        cout << setw(3) << i + 1 << " "; // Adjust row numbers to align with column headers
        for (int j = 0; j < columns; j++)
        {
            if (revealed[i][j] == 1)
            {
                cout << setw(3) << board[i][j]; // Use setw(3) for consistent spacing
            }
            else if (revealed[i][j] == 2)
            {
                cout << setw(3) << "?";
            }
            else
            {
                cout << setw(3) << "#";
            }
        }
        cout << endl;
    }
}

// Function to create mines on the game board
void createMines(int rows, int columns, int mines, char **board)
{
    int row;
    int column;

    int mine_locations[rows][columns];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            mine_locations[i][j] = 0;
        }
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < mines; i++)
    {
        row = rand() % rows;
        column = rand() % columns;
        if (mine_locations[row][column] == 1)
        {
            i--;
        }
        else
        {
            mine_locations[row][column] = 1;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (mine_locations[i][j] == 1)
            {
                board[i][j] = '*';
            }
            else
            {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to reveal a cell on the game board
void revealCell(char **board, char **revealed, int rows, int columns, int row, int column)
{
    if (board[row][column] == '*')
    {
        cout << "You hit a mine! Game over!" << endl;
        keep_playing = 'n';
        return;
    }

    if (revealed[row][column])
    {
        return;
    }

    int mines_surrounding = 0;

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = column - 1; j <= column + 1; j++)
        {
            if (i >= 0 && i < rows && j >= 0 && j < columns)
            {
                if (board[i][j] == '*')
                {
                    mines_surrounding++;
                }
            }
        }
    }

    revealed[row][column] = true;
    board[row][column] = mines_surrounding + '0';

    if (mines_surrounding == 0)
    {
        for (int i = row - 1; i <= row + 1; i++)
        {
            for (int j = column - 1; j <= column + 1; j++)
            {
                if (i >= 0 && i < rows && j >= 0 && j < columns)
                {
                    if (!revealed[i][j])
                    {
                        revealCell(board, revealed, rows, columns, i, j);
                    }
                }
            }
        }
    }
}

// Function to check if the player has won the game
bool checkWin(char **board, char **revealed, int rows, int columns, int mines)
{
    int cells_revealed = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (revealed[i][j] == 1 && board[i][j] != '#')
            {
                cells_revealed++;
            }
        }
    }

    if (cells_revealed == rows * columns - mines)
    {
        cout << "Congratulations! You have revealed all the cells that do not contain mines!" << endl;
        return true;
    }
    return false;
}

// Function to mark or unmark a cell
void markCell(char **revealed, int row, int column)
{
    if (revealed[row][column] == 0)
    {
        revealed[row][column] = 2; // Mark cell
    }
    else if (revealed[row][column] == 2)
    {
        revealed[row][column] = 0; // Unmark cell
    }
}

// Function to clear the consol (checks the platform then runs the appropriate command to clear the consol)
void clearConsol()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    int rows;
    int columns;
    int mines;
    int row;
    int column;
    int max_size = 40;

    cout << "Welcome to Minesweeper!" << endl;
    do
    {
        cout << "How many rows would you like the game to have? ";
        cin >> rows;
        if (rows > max_size)
        {
            cout << "The number of rows cannot exceed " << max_size << "." << endl;
        }
    } while (rows > max_size);
    do
    {
        cout << "How many columns would you like the game to have? ";
        cin >> columns;
        if (columns > max_size)
        {
            cout << "The number of columns cannot exceed " << max_size << "." << endl;
        }
    } while (columns > max_size);
    do
    {
        cout << "How many mines would you like the game to have? ";
        cin >> mines;
        if (mines >= rows * columns)
        {
            cout << "The number of mines cannot be equal or exceed the number of cells on the board." << endl;
        }
    } while (mines > rows * columns);

    // Create dynamic 2D arrays for the game board and revealed board
    char **game_board = new char *[rows];
    char **revealed_board = new char *[rows];
    for (int i = 0; i < rows; i++)
    {
        game_board[i] = new char[columns];
        revealed_board[i] = new char[columns];
    }

    // Initialize game board and revealed board
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            game_board[i][j] = ' ';
            revealed_board[i][j] = 0; // Initialize revealed_board with 0
        }
    }

    createMines(rows, columns, mines, game_board);
    displayBoard(game_board, revealed_board, rows, columns);

    // Main game loop
    do
    {
        int choice;
        cout << "1. Reveal a cell" << endl;
        cout << "2. Mark a cell" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the row and column of the cell you would like to reveal: ";
            cin >> row >> column;
            row -= 1;
            column -= 1;
            revealCell(game_board, revealed_board, rows, columns, row, column);
            // clear the screen
            clearConsol();
            displayBoard(game_board, revealed_board, rows, columns);

            // Check if player hit a mine and end the game
            if (keep_playing == 'n')
            {
                break;
            }

            // Check for win condition
            if (checkWin(game_board, revealed_board, rows, columns, mines))
            {
                keep_playing = 'n';
            }
            break;

        case 2:
            cout << "Enter the row and column of the cell you would like to mark: ";
            cin >> row >> column;
            row -= 1;
            column -= 1;
            markCell(revealed_board, row, column);
            displayBoard(game_board, revealed_board, rows, columns);
            break;

        case 3:
            keep_playing = 'n';
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }

    } while (keep_playing == 'y' || keep_playing == 'Y');

    // Free allocated memory
    for (int i = 0; i < rows; i++)
    {
        delete[] game_board[i];
        delete[] revealed_board[i];
    }
    delete[] game_board;
    delete[] revealed_board;

    return 0;
}
