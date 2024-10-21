#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool possible(double t,vector<pair<double,double>>&arr){
    int n = arr.size();
    pair<double,double> curr = {-1e18,1e18};
    for(auto i:arr){
        double x = i.first;
        double speed = i.second;
        // take intersection of all max(x) and
        // min of all(y) then justt comp for validity if they do intersect
        pair<double,double> range = {x-speed*t,x+speed*t};
        // cond max(x1,x2,x3..)<=min(y1,y2,y3..)
        // so 
        curr = {max(curr.first,range.first),min(curr.second,range.second)};
        if(curr.first>curr.second)
        return false; 
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin>>n;
    vector<pair<double,double>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    double lb = 0, ub=1e9,error=1e-7;
    double ans=0;
    for(int i=0;i<60;i++){
        double mid = lb + (ub-lb)/2;
        if(possible(mid,arr)){
            ans=mid;
            ub = mid-error;
        }
        else{
            lb = mid+error;
        }
    }
    cout<<setprecision(7)<<fixed<<ans<<endl;
    return 0;
}
