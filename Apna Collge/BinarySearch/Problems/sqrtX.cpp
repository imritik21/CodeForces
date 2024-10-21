#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll x;
    cin>>x;

    ll ans=0;
    ll lb=0,ub=x;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;
        if(mid*mid<=x){ // mid<=x/mid overflow control
            ans=mid;
            lb=mid+1;
        }
        else{
            ub = mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
