#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void subset(string str,string ans,int ind){
    if(ind == str.length()){
        cout<<ans<<endl;
        return;
    }
    // not choose
    subset(str,ans,ind+1);
    // choose
    subset(str,ans+str[ind],ind+1);
}
int main(){
    string str;
    cin>>str;
    subset(str,"",0);
}
