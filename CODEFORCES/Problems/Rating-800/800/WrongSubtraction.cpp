#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n,k;
    cin>>n>>k;
    while(k--){
        if(n%10!=0){
            n=n-1;
        }
        else if(n%10==0){
            n=n/10;
        }
    }
    cout<<n;
}