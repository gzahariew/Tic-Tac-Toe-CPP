#include <iostream>

using namespace std;

char board[3][3] = {{'0', '1', '2'},
                    {'3', '4', '5'},
                    {'6', '7', '8'}};

void logBoard(char board[3][3])
{
    cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---------" << endl;
    cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---------" << endl;
    cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool winCheck(char board[3][3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return true;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return true;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }
    return false;
}

void updateTable(bool &who ,int move, char board[3][3])
{

    if (board[0][move] == 'X' || board[0][move] == 'O')
    {
        cout << "Invalid move! Spot already taken. Try again." << endl;
        return;
    }
    if (who)
    {
        board[0][move] = 'X';
        who = !who;
    }
    else
    {
        board[0][move] = 'O';
        who = !who;
    }
}

int main()
{
    int playerMove;
    bool who = true; 


    while (playerMove != 9)
    {
        string player = (who) ? "X" : "O";
        logBoard(board);
        cout << "Make a move " << player << "(end session with 9)" << endl;
        cin >> playerMove;
        updateTable(who ,playerMove, board);
        if (winCheck(board))
        {
            cout << "Congrats " << player << ", you won!!" << endl;
            cout << endl;
            logBoard(board);
            playerMove = 9;
        }

    }

    return 0;
}