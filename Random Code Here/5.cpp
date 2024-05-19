#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    string str;
    cin>>str;
    int n,m; // m always 2 hoga
    cin>>n>>m;
    while(n--){
        int r1,r2;
        cin>>r1>>r2;
        map<char,int> mp;
        for(int i=r1;i<r2;i++){
            mp[str[i]]++;
        }
        int cnt=0;
        int cntrep=0;
        for(auto it: mp){
            if(it.second==1){
                cnt++;
            }
            else if(it.second>1){
                cntrep++;
            }
        }
        cout<<cnt+cntrep<<endl;
    }
}
