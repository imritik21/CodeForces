#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool possible(ll k,vector<int>&arr){
    int i = arr.size()-1,ok=1;
    for(int j=k-1;j>=0;j--,i--){
        ok &= (arr[i]>arr[j] && arr[i-1]>arr[j]);
    }
    return ok;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(),arr.end());
    ll lb=1,ub=(n+1)/2-1;
    ll ans=0;
    while(lb<=ub){
        ll mid = (lb+ub)/2;
        // TTTTTTTTFFFFFF....
        if(possible(mid,arr)){
            ans=mid;
            lb=mid+1;
        }
        else{
            ub=mid-1;
        }
    }
    cout<<ans<<endl;
    int i=n-1,j=ans-1;
    vector<int> res(n);
    for(int k=0;k<n;k++){
        if(k%2==0 || j==-1)res[k]=arr[i--];
        else res[k]=arr[j--];
    }
    for(auto& it:res)cout<<it<<" ";
    cout<<endl;
    return 0;
}
