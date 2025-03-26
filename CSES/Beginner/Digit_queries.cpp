#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long long power(long long a, long long b)
{
    // If b = 0, whatever be the value of a,
    // our result will be 1.
    long long res = 1;
    while (b > 0) {
        // If b is an odd number, then
        // (a^b) = (a * (a^(b–1)/2)^2)
        if (b & 1) {
            res = (res * a);
        }

        // If b is an even number, then
        // (a^b) = ((a^2)^(b/2))
        a = (a * a);
        b >>= 1;
    }
    return res;
}
ll findDigits(ll n){
    ll digits = 1;
    ll base = 9;

    while(n-digits*base > 0){
        n-=digits*base;
        base*=10;
        digits++;
    }
    ll idx = n%digits;
    ll res = power(10,(digits-1))+(n-1)/digits;

    if(idx != 0) res = res/power(10,digits-idx);
    return res%10;
}
void solve()
{
    ll q;
    cin>>q;
    while(q--){
        ll n;
        cin>>n;
        cout<<findDigits(n)<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}
