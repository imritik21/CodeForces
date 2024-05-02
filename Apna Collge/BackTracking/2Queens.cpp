#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void printBoard(vector<vector<char>>& board){
    cout<<"--------Chess-------"<<endl;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
void nQueens(vector<vector<char>>& board,int row){
    // base
    if(row==board.size()){
        printBoard(board);
        return;
    }
    // go for every col
    for(int j=0;j<board.size();j++){
        board[row][j]='Q'; // place the Queen
        nQueens(board,row+1);/// go to next row
        board[row][j]='.'; // while backtrack to upper row again remove the queen for further
    }
}
int main(){
    int n=2;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    nQueens(board,0);
}
