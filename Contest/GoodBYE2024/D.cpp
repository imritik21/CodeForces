
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p32;
typedef pair<ll, ll> p64;
typedef pair<double, double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int>> vv32;
typedef vector<vector<ll>> vv64;
typedef vector<vector<p64>> vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
double eps = 1e-12;
#define forn(i, e) for (ll i = 0; i < e; i++)
#define forsn(i, s, e) for (ll i = s; i < e; i++)
#define rforn(i, s) for (ll i = s; i >= 0; i--)
#define rforsn(i, s, e) for (ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout << #x << " = " << x << ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
constexpr int MOD = 998244353;

class ModInt {
public:
    long long value;

    ModInt(long long v = 0) {
        value = v % MOD;
        if (value < 0) value += MOD;
    }

    ModInt& operator+=(const ModInt& other) {
        value += other.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }

    ModInt& operator-=(const ModInt& other) {
        value -= other.value;
        if (value < 0) value += MOD;
        return *this;
    }

    ModInt& operator*=(const ModInt& other) {
        value = value * other.value % MOD;
        return *this;
    }

    ModInt& operator/=(const ModInt& other) {
        return *this *= other.inverse();
    }

    ModInt operator+(const ModInt& other) const { return ModInt(*this) += other; }
    ModInt operator-(const ModInt& other) const { return ModInt(*this) -= other; }
    ModInt operator*(const ModInt& other) const { return ModInt(*this) *= other; }
    ModInt operator/(const ModInt& other) const { return ModInt(*this) /= other; }

    // Modular inverse using Fermat's Little Theorem
    ModInt inverse() const {
        return power(MOD - 2);
    }

    // Exponentiation
    ModInt power(long long exp) const {
        ModInt result = 1;
        ModInt base = *this;
        while (exp > 0) {
            if (exp % 2 == 1) result *= base;
            base *= base;
            exp /= 2;
        }
        return result;
    }
};
void solve()
{
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n),b(n);
    forn(i,n)cin>>a[i];
    forn(i,n)cin>>b[i];
    auto c = a;
    auto d = b;
    sort(all(c));sort(all(d));
    ModInt ans = 1;
    forn(i,n){
        ans*=min(c[i],d[i]);
        // ans%=MOD;
    }
    cout<<ans.value<<" ";
    for(int i=0;i<q;i++){
        ll x,y;
        cin>>x>>y;
        y--;
        if(x==1){
            a[y]+=1;
            int currIdx = lower_bound(all(c),a[y])-c.begin()-1;
            ans/=min(c[currIdx],d[currIdx]);
            // ans%=MOD;
            c[currIdx]++;
            ans*=min(c[currIdx],d[currIdx]);
            // ans%=MOD;
        }
        else if(x==2){
            b[y]++;
            int currIdx = lower_bound(all(d),b[y])-d.begin()-1;
            ans/=min(c[currIdx],d[currIdx]);
            // ans%=MOD;
            d[currIdx]++;
            ans*=min(c[currIdx],d[currIdx]);
            // ans%=MOD;
        }
        cout<<ans.value<<" ";
    }
    cout<<endl;
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