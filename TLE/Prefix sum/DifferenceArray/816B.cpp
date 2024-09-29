
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
    ll n,k,q;
    cin>>n>>k>>q;
    vector<ll> arr(200007,0);
    // applying difference array 
    // increment on l 
    // decrement on r+1
    for(int i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        arr[x]++;
        arr[y+1]--;
    }
    vector<ll> pre1(200007,0);
    vector<ll> grtK(200007,0);
    pre1[0]=arr[0];
    for(int i=1;i<200007;i++){
        pre1[i]=pre1[i-1]+arr[i];
        if(pre1[i]>=k){
            grtK[i]++;
        }
    }
    vector<ll> pre2(200007,0);
    pre2[0]=grtK[0];
    for(int i=1;i<200007;i++){
        pre2[i]=pre2[i-1]+grtK[i];
    }
    // for(int i=90;i<=100;i++){
    //     cout<<pre2[i]<<" ";
    // } 
    // 0 0 1 2 3 3 3 4 4 4 4
    // 0 1 2 3 4 5 6 7 8 9 100
    // cout<<pre2[91]<<" "<<pre2[94];
    // cout<<pre2[91]<<endl;
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        // cout<<pre2[r]<<" "<<pre2[l]<<endl;
        cout<<pre2[r]-pre2[l-1]<<endl;
    }
}
int main()
{
    fast_cin();
    ll t=1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}