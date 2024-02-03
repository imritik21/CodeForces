#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
bool isPrime(long long  n){
    if(n==1) return false;
    for(long long  i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        long long a,b;
        cin>>a>>b;
        if((a-b==1) && (isPrime(a+b))) cout<<"YES\n";
        else cout<<"NO\n";
    }
}