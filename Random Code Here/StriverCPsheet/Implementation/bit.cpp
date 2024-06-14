#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int n;
    cin>>n;
    int x=0;
    while(n--){
        string str;
        cin>>str;
        if(str=="++X" || str=="X++"){
            x=x+1;
        }
        if(str=="--X" || str=="X--"){
            x=x-1;
        }
    }
    cout<<x<<endl;
}