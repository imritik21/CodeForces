#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// bool possible(ll r,ll x,vector<vector<ll>>& arr,ll c){
//     if(arr[x][r])
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,k,q;
    cin>>n>>k>>q;
    vector<vector<ll>> arr(n,vector<ll>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<k;j++){
            arr[i][j]|=arr[i-1][j];
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<k;j++){
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        ll m;
        cin>>m;
        // set<ll> st;
        ll maxIdx=-1,minIdx=-1;
        for(int i=0;i<m;i++){
            // bi1>4   2 3
            // bi2<8   1 2 3
            // bi1<6   1 2
            // maxIdx '>' 2 and minIdx '<' 2
            int r,c;
            char op;
            r--;
            cin>>r>>op>>c;
            // bs on Bir
            ll lb = 0,ub=n-1;
            while(lb<=ub){
                ll mid = lb + (ub-lb)/2;
                
                if(op=='>'){
                    if(arr[mid][r]>c){
                        maxIdx = mid;  //2
                        ub = mid-1;
                    }
                    else{
                        lb = mid+1;
                    }
                }
                else if(op=='<'){
                    if(arr[mid][r]<c){
                        minIdx=mid;
                        lb = mid+1;
                    }
                    else{
                        ub = mid-1;
                    }
                }
            }
            // now i need to take min common idx
        }
        // min of common index
        // if possible the 
        cout<<minIdx<<" "<<maxIdx<<endl;
    }
    return 0;
}
