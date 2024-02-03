#include<bits/stdc++.h>
using namespace std;
#define int  long long
#define endl '\n'

signed main() {
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        string a,b,c;
        cin>>a>>b>>c;
        bool flag=false;
        for(int i=0;i<n;i++){
            if(a[i]!=c[i] && b[i]!=c[i]){
                flag=true;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<endl;
    }
}
