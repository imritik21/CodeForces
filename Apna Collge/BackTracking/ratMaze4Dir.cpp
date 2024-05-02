#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// you need to print no of ways to reach n-1,m-1
// used directions are all four direction 
int maze(int i,int j,int n,int m){
    // base case
    if(i==n-1 && j==m-1) return 1; // last cell  pos
    if(i==n || j==m) return 0; // edge/ boundry cond
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
