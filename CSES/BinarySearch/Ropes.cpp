
/* Programmed by : https://www.linkedin.com/in/ritik-shankar-537741264/ */

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
//very good problem on Binary Search on Decimals
bool f(double x,vector<int>&arr,int k){
    ll total = 0;
    for(auto i:arr){
        total+=i/x;
        if(total>=k){
            return true;
        }
    }
    return false;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto& i:arr){
        cin>>i;
    }

    double lb=0,ub=1e7,error=1e-7;
    double ans=0;
    // while(ub-lb>error){
    //     double mid = (lb+ub)/2;
    //     cout<<lb<<" "<<ub<<" "<<mid<<endl;
    //     if(f(mid,arr,k)){
    //         ans=max(ans,mid);
    //         lb = mid + error;
    //     }else{
    //         ub=mid-error;
    //     }
    // }
    int iterations = 60;
    for(int i=0;i<iterations;i++){
        double mid = lb + (ub-lb)/2;
        if(f(mid,arr,k)){
            ans=max(ans,mid);
            lb=mid+error;
        }
        else{
            ub=mid-error;
        }
    }
    cout<<setprecision(7)<<fixed<<ans<<endl;
}
int main()
{
    fast_cin();
    ll t=1;
    for (int it = 1; it <= t; it++)
    {
        solve();
    }
    return 0;
}