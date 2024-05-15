#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// no of ways
// allowed directon are down and right
int maze(int i,int j,int n,int m){
    if(i==n-1 && j==m-1) return 1; // last posn reached
    if(i==n || j==m) return 0; // boundry cond
    int w1=maze(i+1,j,n,m);
    int w2=maze(i,j+1,n,m);
    return w1+w2;
}
int main(){
    int n,m;
    cin>>n>>m;
    cout<<maze(0,0,n,m);
}
