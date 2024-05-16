#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void largestLocal(vector<vector<int>>& grid,vector<vector<int>>& res) {
        int n= grid.size();
        int l=0,r=0;
        vector<int> curr;
        while(l<n-2 && r<n-2){
            int maxi1=INT_MIN;
            for(int i=l;i<=l+2;i++){
                for(int j=r;j<=r+2;j++){
                    maxi1=max(maxi1,grid[i][j]);
                }
            }
            curr.push_back(maxi1);
            r++;
            int maxi2=INT_MIN;
            for(int i=l;i<=l+2;i++){
                for(int j=r;j<=r+2;j++){
                    maxi2=max(maxi2,grid[i][j]);
                }
            }
            curr.push_back(maxi2);
            if(n-r==3){
                l++;
                r=0;
                res.push_back(curr);
                curr.clear();
            }
        }
    }
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid(n,vector<int>(n));
    vector<vector<int>> res;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    largestLocal(grid,res);
    for(int i=0;i<n-2;i++){
        for(int j=0;j<n-2;j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
}
