#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    int tc;
    cin>>tc;
    while(tc--){
        int a[4],b[4];
        for(int i=0;i<4;i++){
            cin>>a[i]>>b[i];
        }
        int maxx=*max_element(a,a+4);
        int minn=*min_element(a,a+4);
        int s=maxx-minn;
        cout<<s*s<<endl;
    }
}