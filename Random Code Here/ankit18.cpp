#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    string s;
    cin>>s;
    int lCount=0,Rcount=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') lCount++;
        else if(s[i]==')') Rcount++;
    }
    if(lCount==Rcount){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}
