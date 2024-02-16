#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    string s;
    cin>>s;
    int n=s.length();
    int index;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='.'){
            index=i;
            break;
        }
    }
    string res="";
    for(int i=index+1;i<n;i++){
        res=res+s[i];
    }
    cout<<res;
}