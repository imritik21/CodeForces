#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n;
    cin>>n;
    vector<int> arr(n);
    for(auto &it:arr){
        cin>>it;
    }
    ll m;
    cin>>m;
    vector<int> labels(m);
    for(auto &i:labels)cin>>i;

    vector<pair<int,int>> pile(n);
    pile[0]={1,arr[0]};
    int last = arr[0];
    int maxi=0;
    for(int i=1;i<n;i++){
        pile[i]={last+1,arr[i]+last};
        last = arr[i]+last;
        maxi=max(maxi,last);
    }
    // for(auto ele:pile)cout<<ele.first<<" "<<ele.second<<endl;
    for(int i=0;i<m;i++){
        int target = labels[i];
        int lb = 0,ub=n-1;
        int ans;
        while(lb<=ub){
            int mid = lb + (ub-lb)/2;
            if(pile[mid].first<=target && target<=pile[mid].second){
                ans=mid+1;
                break;
            }
            else if(target<pile[mid].first){
                ub = mid-1;
            }
            else if(target>pile[mid].second){
                lb = mid+1;
            }
        }
        cout<<ans<<endl;
    }
    // TC-  O(N+M*logN)
    return 0;
}
