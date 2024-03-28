#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n;
    cin>>n;
    int res=INT_MAX;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        res=min(res,abs(x));
    }
    cout<<res<<endl;
}
