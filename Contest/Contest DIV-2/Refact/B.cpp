
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    if(n==2){
        if(s1[0]==s1[1]){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
        return;
    }
    int j=0;
    int cnt0=0,cnt1=0;
    for(int i=0;i<n;i++){
        if(s1[i]=='0')cnt0++;
        else cnt1++;
    }
    if(cnt0==n||cnt1==n){
        cout<<"NO"<<endl;
        return;
    }
    // 0 eliminates 1 anyhow 01 or 10
    // 1 eliminates 0 anyhow 10 or 01
    // so any of them wont become 0 before n-1 operation
    bool valid=false;
    while(j<n-1){
        if(cnt0==0||cnt1==0){
            valid=true;
            break;
        }
        if(s2[j]=='0')cnt1--;
        else cnt0--;
        j++;
    }
    if(valid)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}