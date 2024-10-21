#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool possible(ll x,vector<int>& bloomDay,int m,int k){
    int n = bloomDay.size();
    int cnt=0,boq=0;
    for(int i=0;i<n;i++){
        if(bloomDay[i]<=x){
            cnt++;
        }
        else{
            boq+=(cnt/k);
            cnt=0;
        }
    }
    boq+=(cnt/k);
    return boq>=m;
}
int minDays(vector<int>& bloomDay,int m,int k){
    int n = bloomDay.size();
    if(m*k>n) return -1;
    ll lb=1,ub=1e18;
    ll ans = -1;
    for(int i=0;i<80;i++){
        ll mid = lb + (ub-lb)/2;
        if(possible(mid,bloomDay,m,k)){
            // FFFFFFFFTTTTTTTTTT....
            ans=mid;
            ub = mid-1;
        }
        else{
            lb = mid+1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    vector<int> bloomDay = {7,7,7,7,12,7,7};
    int m = 2;
    int k=3;
    cout<<minDays(bloomDay,m,k)<<endl;
    return 0;
}
