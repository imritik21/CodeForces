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
    
    ll n,m,k;
    cin>>n>>m>>k;
    vector<ll> arr(n);
    vector<ll> apt(m);
    for(auto& i:arr)cin>>i;
    for(auto& i:apt)cin>>i;
    sort(arr.begin(),arr.end());
    sort(apt.begin(),apt.end());
    ll i=0,j=0,ans=0;
    while(i<n && j<m){
        if(abs(arr[i]-apt[j])<=k){
            ans++;
            i++;
            j++;
        }
        else{
            if(arr[i]>apt[j]){
                j++;
            }
            else{
                i++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
