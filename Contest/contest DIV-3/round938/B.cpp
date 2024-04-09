#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve(){
    int n,c,d;
        cin>>n>>c>>d;
        int mn=INT_MAX;
        map<int,int> mp;
        for(int i=0;i<n*n;i++){
            int a;
            cin>>a;
            mn=min(mn,a);
            mp[a]++;
        }
        int first=mn,row;
        for(int i=0;i<n;i++){
            first=mn+i*c;
            row=first;
            if(!mp[row]){
                cout<<"NO"<<endl;
                return;
            }
            for(int j=0;j<n;j++){
                row=first+j*d;
                if(!mp[row]){
                    cout<<"NO"<<endl;
                    return;
                }
                mp[row]--;
            }
        }
        cout<<"YES"<<endl;
}
int main(){
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
}
