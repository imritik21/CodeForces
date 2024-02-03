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
        if(n==1){
            cout<<2<<endl;
        }
        else if(n%3==0){
            cout<<n/3<<endl;
        }
        else if(n%3!=0 && n%2==0){
            cout<<n/2<<endl;
        }
        else{
            cout<<(n/3+1)<<endl;
        }
    }
}