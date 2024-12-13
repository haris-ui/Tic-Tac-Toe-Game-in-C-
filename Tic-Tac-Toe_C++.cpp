#include <iostream>
#include <cstdlib>
using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char currentPlayer = 'X';
int choice;
bool gameOver = false;

void DrawBoard()
{
    system("cls");
    cout << "\n Tic Tac Toe Board: \n"<<endl;
    cout << "Player 1 (X)  -  Player 2 (O)";
    cout << "\n\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  \n";
    cout << "_____|_____|_____ \n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  \n";
    cout << "     |     |     \n";
    cout << "\n";
}
void PlayerTurn() 
{
    cout << "Player " << currentPlayer << ", enter a number (1-9) to mark: ";
    cin >> choice;
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') 
    {
        board[row][col] = currentPlayer;
    }
    else 
    {
        cout << "Invaild Move!Make A Move Again....\n";
        PlayerTurn();
    }
}
bool CheckWin() 
{
    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||(board[0][i] == board[1][i] && board[1][i] == board[2][i])) 
        {
            return true;
        }
    }
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }

    return false;
}

bool CheckTie() 
{
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return false;
            }
        }
    }
    return true;
}
int main() 
{
    while (!gameOver) 
    {
        DrawBoard();
        PlayerTurn();

        if (CheckWin()) 
        {
            DrawBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            gameOver = true;
        }
        else if (CheckTie()) 
        {
            DrawBoard();
            cout << "It's a tie!\n";
            gameOver = true;
        }
        if (currentPlayer == 'X') 
        { 
            currentPlayer = 'O';
        }
        else 
        { 
            currentPlayer = 'X'; 
        }
    }
    return 0;
}
