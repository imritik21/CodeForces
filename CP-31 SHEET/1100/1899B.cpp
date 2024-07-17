
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll MOD = 998244353;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())

void solve()
{
    ll n,b;
    cin >> n;
    vector<ll> prefix;
    ll sum = 0;
    prefix.push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin >> b;
        sum+=b;
        prefix.push_back(sum);
    }
    // if (n == 1)
    // {
    //     cout << sum << endl;
    //     return;
    // }
    ll res=0;
    for(int i=1;i<=n;i++){
        vector<ll> v;
        if(n%i==0){
            for(int j=i;j<=n;j+=i){
                sum = prefix[j]-prefix[j-i];
                v.push_back(sum);
            }
            sort(all(v));
            res=max(res,v[(ll)v.size()-1]-v[0]);
        }
    }
    cout<<res<<endl;
    // vector<int> factors;
    // for (int i = 1; i*i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         factors.push_back(i);
    //         if (i != (n / i))
    //             factors.push_back(n/i);
    //     }
    // }
    // sort(all(factors));
    // ll maxi = INT_MIN;
    // for (int i = 0; i < factors.size() - 1; i++)
    // {
    //     int size = factors[i];
    //     ll cnt = 0;
    //     ll sum = 0, sum1 = 0;
    //     int j = 0;
    //     while (cnt != size)
    //     {
    //         sum1 += arr[j++];
    //         cnt++;
    //     }
    //     cnt = 0;
    //     for (int k = size; k < n; k++)
    //     {
    //         if (cnt == size)
    //         {
    //             cnt = 0;
    //             maxi = max(maxi, abs(sum - sum1));
    //             sum1 = max(sum1, sum);
    //             sum = 0;
    //         }
    //         sum += arr[k];
    //         cnt++;
    //     }
    //     maxi = max(maxi, abs(sum - sum1));
    // }
    // cout << maxi << endl;
    // for(int i=0;i<factors.size()-1;i++){
    //     cout<<factors[i]<<" ";
    // }
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