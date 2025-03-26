#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int num;
    cin>>num;
    while(num>1){
        if(num%2!=0){
            cout<<num<<" ";
            num=num*3+1;
        }
        else{
            cout<<num<<" ";
            num=num/2;
        }
    }
    cout<<1;
}