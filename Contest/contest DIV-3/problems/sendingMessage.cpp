#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,f,a,b;
        cin>>n>>f>>a>>b;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int p=0;
        int mn;
        for(int i=0;i<n;i++){
            mn=min(b,abs(v[i]-p)*a);
            f-=mn;
            p=v[i];
        }
        if(f>0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}