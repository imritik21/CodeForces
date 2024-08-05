#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

void solve()
{
    ll n, x;
    cin >> n >> x;
    ll cnt = 0;

    for(int a=1;a<=min(n,x);a++){
        for(int b=1;a*b<=n and a+b<=x;b++){
            int maxC = min((n-a*b)/(a+b),x-(a+b));
            cnt+=maxC;
        }
    }
    cout << cnt << endl;
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
