#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void permutations(string str,string ans){
    // base case
    if(str.length()==0){
        cout<<ans<<endl;
        return;
    }
    // recusion
    for(int i=0;i<str.length();i++){
        char c = str[i];
        // remove ith ele
        // Therefore, str.substr(0, i) will extract characters
        // from index 0 up to (but not including) index i
        string newStr= str.substr(0,i)+str.substr(i+1);
        permutations(newStr,ans+c);
    }
}
int main(){
    string str;
    cin>>str;
    permutations(str,"");
}
