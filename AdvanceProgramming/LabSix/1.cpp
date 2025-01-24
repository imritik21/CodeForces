// 9x9 Sudoku
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool isValid(int i, int j, vector<vector<char>> &board, char c)
{
    // check 3 conditions
    // row conditions wheter it conatains or not
    for (int k = 0; k < 9; k++)
    {
        if (board[i][k] == c)
            return false;
    }
    // col conditions wheter it conatains or not
    for (int k = 0; k < 9; k++)
    {
        if (board[k][j] == c)
            return false;
    }
    // 3*3 matrix conditions wheter it conatains or not
    for (int ki = i - i % 3; ki < (i - i % 3 + 3); ki++)
    {
        for (int kj = j - j % 3; kj < (j - j % 3 + 3); kj++)
        {
            if (board[ki][kj] == c)
                return false;
        }
    }
    // at last if no duplicate return true
    return true;
}
bool solve(int i, int j, vector<vector<char>> &board)
{
    // 3 conditions
    if (i == 9)
        return true; // everything fine last tk reached
    if (j == 9)
        return solve(i + 1, 0, board);
    if (board[i][j] != '.')
        return solve(i, j + 1, board); // iterate 1 step
    // now fillling 
    for (char c = '1'; c <= '9'; c++)
    {
        // check whter it is valid char or not
        if (isValid(i, j, board, c) == false)
            continue; // until this is true
        // then fill if it is valid
        board[i][j] = c;
        // now again check whether it's repeated
        bool result = solve(i, j, board);
        if (result == true)
            return true;
        // else backtrack and fill '.' again so that it can again be filled
        board[i][j] = '.';
    }
    // it didnot went into loop
    return false;
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(0, 0, board);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<char>> board = {
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
    {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
    {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
    {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
    {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
    {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
    {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
    {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
    {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    solveSudoku(board);
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
