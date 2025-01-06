
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
bool isPalindrome(vector<int>&arr,int n){
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-i-1]){
            return false;
        }
    }
    return true;
}
void solve()
{
    //its always valid to remove all occur of x
    // still it will form palindrome
    // just find first i , ai!=an-i-1
    // its alwys possible either ai or an-i-1 
    // would be removed all to be palindrome
    int n;
    cin>>n;
    vector<int> arr(n);
    map<int,int> mp;
    for(auto& i:arr){
        cin>>i;
        mp[i]++;
    }
    if(n==1 || n==2){
        cout<<"YES"<<endl;
        return;
    }
    // if already pal
    bool pal = isPalindrome(arr,n);
    if(pal){
        cout<<"YES"<<endl;
        return;
    }
    int idx = -1;
    for(int i=0;i<n;i++){
        if(arr[i]!=arr[n-i-1]){
            idx=i;
            break;
        }
    }
    int ele1 = arr[idx];
    int ele2 = arr[n-idx-1];
    vector<int> vec1,vec2;
    for(int i=0;i<n;i++){
        if(arr[i]!=ele1){
            vec1.push_back(arr[i]);
        }
        if(arr[i]!=ele2){
            vec2.push_back(arr[i]);
        }
    }
    if(isPalindrome(vec1,vec1.size())|| isPalindrome(vec2,vec2.size())){
        cout<<"YES"<<endl;
    }
    else cout<<"NO"<<endl;
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