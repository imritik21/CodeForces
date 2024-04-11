#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/*We can use one tool each time the timer reaches to 1
, then the answer will be ∑ni=1min(a−1,xi)+b
. This can prove to be optimal. Because for each tool, if we use it when the timer is c
, its contribution to the answer is min(xi,a−c)
. We can't use the tool when the timer is less than or equal to 0
 because the bomb will explode before that, so c=1
 is the optimal.*/
void solve()
{
    ll a, b, n;
    // a=5 b=3 n=3
    // 1 1 7
    cin >> a >> b >> n;
    ll ans = b - 1; // ans=2
    ll c = 1;       // when i am having 1 sec then i am using my tools
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        ans = ans + min(c + x, a);
        ans--;
    }
    cout << ans + 1 << endl;
    // arr[i] = 1 1 7
    // jb bhi 1 sec hoga we'll use our tools b=3 and max A use kr skte
    // so min(C+Xi, A)
    // eg at T=1  b=2  at T=2 b=(2-1)+1 at T=3 b=(2-1)+1
    //  at T=4 b=1+min(2+7,5)-1 b=5 due to bug
    // T=5 b=4  T=6 b=3  T=7 b=2 T=8 b=1 T=9 b=0
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
