#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool f(long double x,vector<long double>&a,vector<long double>&b,int n ,int k){
    vector<long double> transformedArr(n);
    for(int i=0;i<n;i++){
        transformedArr[i] = (a[i]-b[i]*x);
    }
    sort(transformedArr.begin(),transformedArr.end());
    reverse(transformedArr.begin(),transformedArr.end());
    long double sum = 0;
    for(int i=0;i<k;i++){
        sum+=transformedArr[i];
    }
    return sum>=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin>>n>>k;
    vector<long double> a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }


    long double lb=0,ub=1e10;
    // search space = 10^10*10^6 => 10^16 -> 

    long double ans=0;
    int iteration = 60;
    for(int i=0;i<iteration;i++){
        long double mid = lb + (ub-lb)/2;
        if(f(mid,a,b,n,k)){
            ans = mid;
            lb=mid+1;
        }
        else{
            ub = mid-1;
        }
    }
    cout<<setprecision(7)<<fixed<<ans<<endl;
    return 0;
}
