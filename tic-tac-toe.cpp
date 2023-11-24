#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool tie = false;
string n1 = "";
string n2 = "";
// Creating a function for displaying  the current state of the board
void showBoard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}
// Creating a  function to get the player's move
void getPlayerMove()
{

    int digit;
    if (token == 'x')
    {
        cout << n1 << " "
             << "Please Enter: \n";
        cin >> digit;
    }
    if (token == '0')
    {
        cout << n2 << " "
             << "Please Enter: \n";
        cin >> digit;
    }
    // Mapping digit to respective row and column
    if (digit == 1) {
        row = 0;
        column = 0;
    }

    if (digit == 2){
        row = 0;
        column = 1;
    }

    if (digit == 3){
        row = 0;
        column = 2;
    }

    if (digit == 4){
        row = 1;
        column = 0;
    }
    if (digit == 5){
        row = 1;
        column = 1;
    }
    if (digit == 6){
        row = 1;
        column = 2;
    }
    if (digit == 7){
        row = 2;
        column = 0;
    }
    if (digit == 8){
        row = 2;
        column = 1;
    }
    if (digit == 9){
        row = 2;
        column = 2;
    }
    // Check for valid input
    else if (digit < 1 || digit > 9)
    {
        cout << "Invalid input!! Enter a number between 1 and 9." << endl;
    }

    if ((token == 'x' || token == '0') && board[row][column] != 'x' && board[row][column] != '0')
    {
        board[row][column] = token;
        token = (token == 'x') ? '0' : 'x';
    }
    else
    {
        cout << "Invalid move! Please choose an empty space." << endl;
        getPlayerMove();
    }

    showBoard();
}

bool isGameOver()
{
    // Checking rows and columns for winning conditions
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][i] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return true;
        }
    }
    // Checking diagonal for winning  condtions
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] || board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return true;
    }

    // Checking  for a tie
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Checking if 'x' and '0' are present in any place or not
            if (board[i][j] != 'x' && board[i][j] != '0')
            {
                return false;
            }
        }
    }

    // If there is no winner and no empty cells, it's a tie
    tie = true;
    return false;
}
void resetBoard()
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            board[i][j] = '1' + i * 3 + j; // Reset the board with numbers 1 to 9 removing the present tokens
        }
    }
    token = 'x'; // to  Reset the token to 'x'
    tie = false; // to  Reset the tie flag
}
int main()
{
    char playAgain = 'Y'; // Initialize playAgain to 'Y' for playing for the first time

    while (toupper(playAgain) == 'Y')
    {
        cout << "Enter the name of the first player : \n";
        getline(cin, n1);
        cout << "Enter the name of the second player : \n";
        getline(cin, n2);
        showBoard();
        cout << n1 << " is player1 so he/she will play first \n";
        cout << n2 << " is player2 so he/she will play second \n";

        // running while loop till game is over ; it returns true only if game is finished
        while (!isGameOver())
        {
            // showBoard();
            getPlayerMove();
            isGameOver();
        }
        // Displaying the final  result
        // If the game is not tied and the last turn was of player 1 then player 2 wins ND VICE VERSA
        if (token == 'x' && tie == false)
        {

            cout << n2 << " "
                 << "Won!!" << endl;
        }
        else if (token == '0' && tie == false)
        {
            cout << n1 << " "
                 << "Won!!" << endl;
        } // if above  both conditions are not meeting then its a draw
        else
        {
            cout << "It's a draw!" << endl;
        }
        // Ask if they want to play again
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        // Reset the board for a new game if they choose to play again
        if (toupper(playAgain) == 'Y')
        {
            resetBoard();
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
