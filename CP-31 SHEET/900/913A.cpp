#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// ll fast_pow (ll x ,ll n ){
//     ll result = 1 ;
//     while (n>0){
//         if (n%2==1)
//             result*=x ;
//         x*=x ;
//         n/=2 ;
//     }
//     return result ;
// }
int main()
{
    ll n, m;
    cin >> n >> m;
    if (n >= 40)
    {
        cout << m << endl;
    }
    else
    {
        cout << m % pow(2,n)<< endl;
    }
}
