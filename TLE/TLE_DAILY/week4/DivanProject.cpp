#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        // how ma ny times we are going to visit the ith building 
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            v.push_back({a,i});
        }
        vector<int> ans(n);
        sort(v.begin(),v.end());
        // as we have sorted now so we will iterate from last 
        // and assign them the closest index as it will be the most visited 
        // after sssigning it to 1 we will chnage and increment thier index  
        int curr=1; // to assign the largest one and then we will chnage as we move further
        int time=0; // time taken 
        for(int i=n-1;i>=0;i--){
            ans[v[i].second]=curr;
            time+=(2*(v[i].first*abs(curr)));
            if(curr>0){
                curr*=-1;
            }
            else{
                curr*=-1;
                curr++;
            }
        }
        cout<<time<<endl;
        cout<<0<<" ";
        for(auto it: ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}