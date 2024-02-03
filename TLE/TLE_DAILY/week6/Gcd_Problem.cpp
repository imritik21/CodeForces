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
        if(n%2==0) cout<<(n-1)/2<<" "<<(n-1)/2+1<<" 1\n";
        else{
            int curr=(n-1)/2;
            if(curr%2==0) cout<<curr-1<<" "<<curr+1<<" "<<1<<endl; // even the sub 1
            else cout<<curr-2<<" "<<curr+2<<" "<<1<<endl; // 63/2==31 & 31-2==31+2==odd and gcd=1
        }
    }
}