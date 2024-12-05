
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
ll MOD = 998244353;
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
const int N = 1e5+7;
int primes[N];
void seive(){
    fill(primes,primes+N+1,true);
    primes[0]=primes[1]=false;
    for(int i=2;i*i<=N;i++){
        if(primes[i]){
            for(int j=i*i;j<=N;j+=i){
                primes[j]=false;
            }
        }
    }
}
void solve() {
    int n;
    cin >> n;

    if(n<=4){
        cout<<-1<<endl;
        return;
    }
    if(n>=10){
        cout<<"2 4 6 ";
        for(int i=10;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<8<<" ";
        for(int i=1;i<=n;i+=2){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    if(n==5){
        cout<<"2 4 5 3 1"<<endl;
    }
    else if(n==6)cout<<"2 4 6 3 1 5"<<endl;
    else if(n==7)cout<<"2 4 6 3 1 5 7"<<endl;
    else if(n==8)cout<<"2 4 8 6 3 1 5 7"<<endl;
    else if(n==9)cout<<"2 4 8 6 3 1 5 7 9"<<endl;
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