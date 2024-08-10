
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

// void solve()
// {
//     ll n,k;
//     cin>>n>>k;
//     vector<ll> arr(n);
//     forn(i,n)cin>>arr[i];
//     // deque<ll> dq;
//     int maxi = *max_element(all(arr));
//     int i=0;
//     for(;i<n;i++){
//         if(arr[i]==maxi)break;
//     }
//     i++;
//     // cout<<i<<" "<<maxi;
//     // i=2   1 5 3 4 2
//     //       1 5 3 4 2 1 5
//     vector<ll> left;
//     for(int j=0;j<i;j++){
//         arr.push_back(arr[j]);
//     }
//     // for(auto ele: arr)cout<<ele<<" ";
//     for(int j=i;j<arr.size()-1;j++)left.push_back(arr[j]);
//     // find NGL next greater to left for less than i
//     vector<ll> NGL(n,0);
//     stack<ll> st;
//     for(int i=0;i<n;i++){
//         // while(!st.empty() && st.top()<=arr[i])st.pop();
//         // if(st.empty())NGL[i]=arr[i];
//         // else NGL[i]=st.top();
//         // st.push(NGL[i]);
//         while (!st.empty() && st.top() <= arr[i]) {
//             st.pop();
//         }

//         // If the stack is empty, it means there's no greater element to the left
//         if (st.empty()) {
//             NGL[i] = arr[i];  // Assign the current element itself as the "greater" element
//         } else {
//             NGL[i] = st.top(); // The top of the stack is the next greater element
//         }

//         // Push the current element onto the stack
//         st.push(arr[i]);
//     }
//     // cout<<i;
//     // for(auto ele: NGL)cout<<ele<<" ";
//     // cout<<endl;
//     while(k--){
//         ll x;cin>>x;
//         if(x>i){
//             ll rem = x-i; // 10 - 5 = 5
//             cout<<maxi<<" "<<left[rem%left.size()]<<endl;
//         }
//         else{
//             cout<<NGL[x-1]<<" "<<arr[x]<<endl;
//         }
//     }
// }
void solve(){
    ll n,q;
    cin>>n>>q;
    deque<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    vector<pair<ll,ll>> ans(n-1);
    for(int i=0;i<n-1;i++){
        int fst=a[0];
        a.pop_front();
        int scnd = a[0];
        a.pop_front();
        ans[i]=make_pair(fst,scnd);
        a.push_front(max(fst,scnd));
        a.push_back(min(fst,scnd));
    }
    while(q--){
        ll x;
        cin>>x;
        x--;
        if(x>=n-1){
            int pos = (x-n+1)%(n-1);
            cout<<a[0]<<" "<<a[pos+1]<<endl;
        }
        else{
            cout<<ans[x].first<<" "<<ans[x].second<<endl;
        }
    }
}
int main()
{
    fast_cin();
        solve();
    return 0;
}