#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool possible(ll x,vector<ll>& city,vector<ll>&cell){
    ll i=0,j=0;
    int n = city.size();
    int m = cell.size();
    bool reach = false;
    while(i<n && j<m){
        if(abs(cell[j]-city[i])<=x){
            i++;
            reach=true;
        }
        else{
            j++;
            reach=false;
        }
    }
    return i==n;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,m;
    cin>>n>>m;
    vector<ll> cell(m);
    vector<ll> city(n);
    for(auto &i:city)cin>>i;
    for(auto &i:cell)cin>>i;

    ll lb = 0,ub=2e9;
    ll ans=0;
    for(int i=0;i<60;i++){
        ll mid = lb + (ub-lb)/2;
        if(possible(mid,city,cell)){
            ans=mid;
            ub=mid-1;
        }
        else{
            lb=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
