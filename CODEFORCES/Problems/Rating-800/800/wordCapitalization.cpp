#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    string str;
    cin>>str;
    for(int i=0;i<str.length();i++){
        if(i==0 || str[i-1]==' '){
            str[i]=toupper(str[i]);
        }
    }
    cout<<str<<endl;
}