#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int fact3(int n){
    return (n*(n-1)*(n-2))/6;
}
int fact2(int n){
    return (n*(n-1))/2;
}
signed main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int tc;
    cin>>tc;
    while(tc--){
        int n;
        cin>>n;
        vector<int> array(n+1,0);
        for(int i=0;i<n;i++){
            int x;cin>>x;
            array[x]++;
        }
        int res=0,prev=0;
        for(int i=0;i<=n;i++){
            if(array[i]>=3){
                res+=fact3(array[i]);
            }
            if(array[i]>=2){
                res+=fact2(array[i])*prev;
            }
            prev+=array[i];
        }
        cout<<res<<endl;
    }
}