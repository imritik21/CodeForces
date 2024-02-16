#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        int minn=1,maxx=INT_MAX;
        set<int>v;
        int t,x;
        for(int i=0;i<n;i++){
            cin>>t>>x;
            if(t==1){
                minn=max(minn,x);
            }
            if(t==2){
                maxx=min(maxx,x);
            }
            if(t==3){
                v.insert(x);
            }
        }
        if(maxx<minn){
            cout<<0<<endl;
            continue;
        }
        int ans=maxx-minn+1;
        for(auto &it:v) ans-=(it>=minn && it<=maxx);
        cout<<ans<<endl;
    }
}