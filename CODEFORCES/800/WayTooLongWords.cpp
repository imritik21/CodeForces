#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        if(str.length()>10){
            cout<<str[0]<<str.length()-2<<str[str.length()-1]<<endl;
        }
        else{
            cout<<str<<endl;
        }
    }
}