#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string toLowerCase(const std::string& s) {
    std::string result = s;
    for (char& c : result) {
        c = std::tolower(c);
    }
    return result;
}
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        string s;
        cin>>s;
        toLowerCase(s);
        for(int i=0;i<s.length();i++){
            if(s[i]=='y' && s[i+1]=='e' && s[i+2]=='s')
            cout<<"YES"<<endl;
            else
            cout<<"NO"<<endl;
        }
    }
}