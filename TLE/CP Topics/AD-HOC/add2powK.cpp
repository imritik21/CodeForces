#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int n,q;cin>>n>>q;
    vector<int> v(n);
    for(auto &it:v)cin>>it;
    int maxi=32;
    while(q--){
        int temp;cin>>temp;
        // temp1=temp;
        if(temp>=maxi){
            continue;
        }
        maxi=temp;
        for(int i=0;i<n;i++){
            if((v[i]&((1<<temp)-1))==0){
                v[i]+=((1<<temp)-1);
            }
        }
    }
    for(auto it:v)cout<<it<<" ";
    cout<<endl;
    return 0;
}
