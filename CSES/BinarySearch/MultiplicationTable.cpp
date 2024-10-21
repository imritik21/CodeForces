#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool check(ll mid,ll n){
    ll cnt=0;
    for(ll row=1;row<=n;row++){
        cnt+=min(n,mid/row);
    }
    return cnt>=(n*n+1)/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    ll ans;
    ll lb = 1,ub=n*n;
    while(lb<=ub){
        ll mid = lb + (ub-lb)/2;
        if(check(mid,n)){
            ans = mid;
            ub = mid-1;
        }
        else{
            lb = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
