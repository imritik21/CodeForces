#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

const ll N = 5005;
ll sum[N][N],dp[N][N];

ll fun(int i,int j,vector<ll>&arr){
    if(i==j)return arr[i];

    if(dp[i][j]!=1e15)return dp[i][j];

    dp[i][j] = max(arr[i]+sum[i+1][j]-fun(i+1,j,arr),
                    arr[j]+sum[i][j-1]-fun(i,j-1,arr));

    return dp[i][j];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j]=1e15;
        }
    }
    
    for(int i=0;i<n;i++){
        ll curr=0;
        for(int j=i;j<n;j++){
            curr+=arr[j];
            sum[i][j]=curr;
        }
    }

    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i>j)continue;
            if(i==j){
                dp[i][j]=arr[i];
            }
            else{
                dp[i][j] = max(arr[i]+sum[i+1][j]-dp[i+1][j],
                                arr[j]+sum[i][j-1]-dp[i][j-1]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
    // cout<<fun(0,n-1,arr);

    return 0;
}
