#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q;
    cin >> n>>q;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> preSorted(n, 0);
    vector<ll> pre(n, 0);
    pre[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + arr[i];
    }
    sort(arr.begin(), arr.end());
    preSorted[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        preSorted[i] = preSorted[i - 1] + arr[i];
    }
    //  5 5  2  3
    //  5 10 12 15
    //
    while (q--)
    {
        ll l, r;
        cin >> l >> r;
        int f = 0, f1 = 0;
        if (r > 1)
        {
            r--;
            f1 = 1;
        }
        if (l > 1)
        {
            l--;
            f = 1;
        }
        if (l == 1 && !f)
        {
            if (r == 1 && !f1)
                r--;
            cout << pre[r] << endl;
        }
        else
            cout << pre[r] - pre[l - 1] << endl;
    }
    return 0;
}
