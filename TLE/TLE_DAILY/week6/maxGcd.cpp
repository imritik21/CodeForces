#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int res=__gcd(n/2,(n/2)*2);
        cout<<res<<endl;
    }
}