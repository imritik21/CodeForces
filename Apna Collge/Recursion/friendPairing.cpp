#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int friendPair(int n){

    //base cond
    if(n==1 || n==2){
        return n;
    }

    // choice
    // single
    int fnm1=friendPair(n-1);

    // pair
    int fnm2=(n-1)*friendPair(n-2);
    int totalWays=fnm1+fnm2;
    return totalWays;
}
int main(){
    int n;
    cin>>n;
    cout<<friendPair(n)<<endl;
}
