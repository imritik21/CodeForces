#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    string str;
    cin>>str;
    int n = str.length();
    for(int i=0;i<str.length();i++){
        // if(str[i])
        // if((str[i]=='.' && str[i-1]!='-') || (str[i]=='.'&&i==0)||(str[i]=='.'&&i==n-1) ||(str[i]=='.' && str[i-1]=='-' && str[i+1]=='-')){
        //     cout<<0;
        // }
        if(str[i]=='-' && str[i+1]=='.'){
            cout<<1;
            i++;
        }
        else if(str[i]=='-' && str[i+1]=='-'){
            cout<<2;
            i++;
        }
        else{
            cout<<0;
        }
    }
}
