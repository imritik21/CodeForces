#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printBoard(vector<vector<char>> &board)
{
    cout << "--------Chess-------" << endl;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}
bool isValid(vector<vector<char>> &board, int row, int col)
{
    // we have 3 condtions for queens
    // vertically up col-const and row-1 til 0
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
            return false;
    }
    // diagonally left up
    // means i-1 and j-1 till failure
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    // diagonally right up
    // means i-- and j++
    for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
            return false;
    }
    return true;
}
void nQueens(vector<vector<char>> &board, int row)
{
    if (row == board.size())
    {
        printBoard(board);
        return;
    }
    // recur
    for (int j = 0; j < board.size(); j++)
    {
        if (isValid(board, row, j))
        {
            board[row][j] = 'Q';
            nQueens(board, row + 1);
            board[row][j] = 'x';
        }
    }
}
int main()
{
    int n = 4;
    vector<vector<char>> board(n, vector<char>(n, 'x'));
    nQueens(board, 0);
}