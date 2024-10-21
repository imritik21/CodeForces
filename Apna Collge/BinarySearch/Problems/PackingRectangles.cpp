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
    
    ll w,h,n;
    cin>>w>>h>>n;

    ll lb=0,ub=1e18;
    ll ans = 2e18;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;
        ll rows = mid/w;
        ll cols = mid/h;
        if(cols>0 && rows>=(n+cols-1)/cols){
            ans=min(ans,mid);
            ub = mid-1;
        }
        else{
            lb = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
