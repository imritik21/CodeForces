#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define endl '\n' 
signed main(){
    int n;
    cin>>n;
    if(n>9 && n<60){
        cout<<"21:"<<n;
    }
    else if(n<10){
        cout<<"21:0"<<n;
    }
    else{
        if(n%60<10) cout<<"22:0"<<n%60;
        else cout<<"22:"<<n%60;
    }
}