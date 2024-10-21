#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
using namespace std;

#define int             long long
#define mod             1000000007
#define inf             1e18
#define all(v)          v.begin(),v.end()
#define nl              '\n'

void _xwyrm() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
}

//                                   _________________< FUNCTIONS >_________________

void solve() {
}

int countSquares(int a, int b)
{
    return (floor(sqrt(b)) - ceil(sqrt(a)) + 1);
}

//                                     _________________< MAIN >_________________

int32_t main() {
    _xwyrm();

    int T;
    cin >> T;
    while (T--) {
          int n; cin >> n;
          int l = 1, ct = n, num = 0;
          
          while(countSquares(l, ct))
          { 
              num = countSquares(l, ct);
                  l = ct+1;
                  ct += num;
          }
          cout <<ct<< endl;
     }
    return 0;
}