#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int cnt=0;
vector<string> allString; // contains all str
void subsets(int ind,int size,vector<int>& f,string curr){
    if(ind == size){
        // we reached so push
        allString.push_back(curr);
        cnt++;
        return;
    }

    for(int i=0;i<26;i++){
        if(f[i]>0){
            f[i]--;
            subsets(ind+1,size,f,curr+(char)(i+'a'));
            f[i]++; // don't want to affect other choices
        }
    }
}

int main(){
    string str;
    cin>>str;
    vector<int> f(26);
    for(int i=0;i<str.length();i++){
        f[str[i]-'a']++;
    }
    subsets(0,str.length(),f,"");
    cout<<cnt<<endl;
    // for(int i=0;i<allString.size();i++){
    //     cout<<allString[i]<<endl;
    // }
}
