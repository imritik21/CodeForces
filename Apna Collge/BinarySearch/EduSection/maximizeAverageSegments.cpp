#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
long double maximumSUm(vector<long double>& arr,ll d, ll n){
    vector<long double> prefix(n);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    long double ans = -1e18;
    long double minSoFar = 0;
    for(int right=d-1;right<n;right++){
        long double bestSubEndingHere = prefix[right]-minSoFar;
        minSoFar = min(minSoFar,prefix[right-d+1]);
        ans = max(ans,bestSubEndingHere);
        
    }
    return ans;
}
bool f(long double x,vector<long double>&arr,ll d,ll n){
    vector<long double> transformedArr(n);
    for(int i=0;i<n;i++){
        transformedArr[i] = arr[i]-x;
    }
    return maximumSUm(transformedArr,d,n)>=0;
}

pair<int,int> anySubarrWithPosSum(vector<long double>& arr,ll d, ll n){
    vector<long double> prefix(n);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
        prefix[i] = prefix[i-1]+arr[i];
    }
    long double ans = -1e18;
    long double minSoFar = 0;
    int bestLeftidx=-1;
    for(int right=d-1;right<n;right++){
        long double bestSubEndingHere = prefix[right]-minSoFar;
        ans = max(ans,bestSubEndingHere);
        if(ans>=0){
            return make_pair(bestLeftidx+1,right);
        }
        if(minSoFar>prefix[right-d+1]){
            minSoFar = prefix[right-d+1];
            bestLeftidx = right-d+1;
        }
    }
    return {-1,-1};// never going to happen bcz we are only considering
    // that mean which is possible
}
pair<int,int> bestSubarray(long double x,vector<long double>&arr,ll d,ll n){
    vector<long double> transformedArr(n);
    for(int i=0;i<n;i++){
        transformedArr[i] = arr[i]-x;
    }
    return anySubarrWithPosSum(transformedArr,d,n);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,d;
    cin>>n>>d;
    vector<long double> arr(n);
    for(auto& i:arr){
        cin>>i;
    }
    long double lb = 0,high = 100;
    // 10 decimal place -> 100*10^10-> 10^12-> 40 iteration
    for(int i=0;i<100;i++){
        long double mid = (lb+high)/2;
        if(f(mid,arr,d,n)){
            lb = mid;
        }
        else{
            high = mid;
        } 
    }
    //// TTTTTTTTTTTTFFFFFFFFF
    // cout<<setprecision(10)<<fixed<<lb<<endl;
    pair<int,int> ans = bestSubarray(lb,arr,d,n);
    cout<<ans.first+1<<" "<<ans.second+1;
    return 0;
}
