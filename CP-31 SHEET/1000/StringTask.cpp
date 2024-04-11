#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    string str;
    cin>>str;
    int n=str.length();
    // Convert string to lowercase
    string res;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i=0;i<n;i++){
        if(str[i]!='a' && str[i]!='e' && str[i]!='i' && str[i]!='o' && str[i]!='u' && str[i]!='y'){
            res+=str[i];
        }
    }
    for(int i=0;i<res.length();i++){
        cout<<'.'<<res[i];
    }
}
