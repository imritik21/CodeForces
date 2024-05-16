#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
int main(){
    int n,m,key;
    cin>>n>>m>>key;
    vector<vector<int>> arr(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    // search
    cout<<searchMatrix(arr,key);
}
