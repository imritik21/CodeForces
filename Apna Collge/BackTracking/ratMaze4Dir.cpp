#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// you need to print no of ways to reach n-1,m-1
// used directions are all four direction 
bool isValid(int x,int y,int n,int m){
    return ((x >= 0 && x < n && y >= 0 && y < m));
}
int maze(int i,int j,int n,int m){
    // base case
    if(i==n-1 && j==m-1) return 1; // last cell  pos
    if(!isValid(i,j,n,m)) return 0;
    int w1=maze(i+1,j,n,m);
    int w2=maze(i,j+1,n,m);
    int w3=maze(i-1,j,n,m);
    int w4=maze(i,j-1,n,m);
    return w1+w2+w3+w4;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<maze(0,0,n,m)<<endl;
}
