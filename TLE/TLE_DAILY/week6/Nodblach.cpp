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
bool isprime(int n){
    bool found=false;
    for(int i=2;i<n;i++){
        if(n%i==0){
        found=true;
        }
    }
    if(found){
        return false;
    }
    else
    return true;
}
int main()
{
    fast_cin();
    int n,k;
    cin>>n>>k;
    vector<int>vec;
    int count=0;
    for(int i=2;i<=n;i++){
        int cnt=0;
        for(int j=1;j*j<=i;j++){
            if(i%j==0){
                cnt++;
                if(i/j != j){
                    cnt++;
                }
            }
        }
        if(cnt==2){
            vec.push_back(i);
        }
    }
    for(int i=0;i<vec.size()-1;i++){
        int sum=vec[i]+vec[i+1]+1;
        bool flag =false;
        for(int j=0;j<vec.size();j++){
            if(vec[j]==sum){
                flag=true;
                break;
            }
        }
        if(flag){
            count++;
        }
    }
    if(count>=k) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}