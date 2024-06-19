
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        ll ans = 0;
        ll curr = 1;
        for(int i=0;i<n;i++)
        {
            if (a[i] > curr)
            {
                ans += a[i] - curr;
                curr = a[i];
            }
            curr++;
        }
        cout << ans << endl;
    }
    return 0;
}
