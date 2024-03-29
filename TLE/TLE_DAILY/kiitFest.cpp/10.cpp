#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h> 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
 
int check(string s1,string s2){
    int i=0,j=0;
    while(i<s1.length() && j<s2.length()){
        if(s1[i] == s2[j]){
            i++;
            j++;
        }else{
            j++;
        }
    }
    if(i == s1.length()){
        return j;
    }else{
        return 0;
    }
}
string check1(string s,string t){
    int i=0,j=0;
    while(i<s.length() && j<t.length()){
        if(s[i] < t[j]){
            return "Alice";
        }else if(s[i] > t[j]){
            return "Bob";
        }
    }
    return "Draw";
}
void solve(){
    string s,t,a;
    int cnt1 = check(s,a);
    int cnt2 = check(t,a);
    if(cnt1 < cnt2){
        cout<<"Alice"<<endl;
    }else if(cnt1 > cnt2){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<check1(s,t)<<endl;
    }
    
}
int main()
{
 fast_cin();
 ll t;
 cin >> t;
 for(int it=1;it<=t;it++) {
     solve();
 }
 return 0;
}