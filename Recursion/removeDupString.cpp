#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool mp[26]={0};
string res="";
void removeDup(string& str,int i){
    if(i==str.length()){
        cout<<res<<endl;
        return;
    }
    if(mp[str[i]-'a']==0){
        res+=str[i];
        mp[str[i]-'a']=1;
    }
    removeDup(str,i+1);
}
int main(){
    string str;
    cin>>str;
    // for(int i=0;i<str.length();i++){
    //     mp[str[i]]++;
    // }
    removeDup(str,0);
}
