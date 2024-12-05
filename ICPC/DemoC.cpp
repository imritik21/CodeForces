

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string flag;
    string prev = "true";
    for(int i=1;i<n;i++){
        cout<<"READ "<<i<<endl;
        cout.flush();
        cin>>flag;
        if(prev=="true" && flag=="false"){
            cout<<"OUTPUT "<<i-1<<endl;
            return;
        }
        prev=flag;
    }
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