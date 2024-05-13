#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
    int n,count=0;
    cin>>n;
    string str;
    cin>>str;
    unordered_map<char,int> mp;
    for(int i=0;i<(2*n)-2;i+=2){
        mp[str[i]]++;
        auto it = mp.find('a'+(str[i+1]-'A'));

        if(it!=mp.end()){
            // found 
            if(mp['a'+(str[i+1]-'A')]>1)
            mp['a'+(str[i+1]-'A')]--;
            else
            mp.erase('a'+(str[i+1]-'A'));
        }
        else
        count++;
    }
    cout<<count<<endl;
}
