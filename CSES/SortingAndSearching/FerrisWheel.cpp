#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,x;
    cin>>n>>x;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    ll cnt=0;
    ll sum=0;
    //  2 3 7 9
    //  2 5 12 21
    // for(int i=0;i<n;i++){
    //     if(nums[i])
    // }   2 3 3 6 6
    // 10 15
    //  9 8 8 9 10 8 5 8 7 10
    //  5 7 8 8 8 8 9 9 10 10
    //    1 2 3 4 5 6 7 8 9

    int i=0,j=n-1;
    while(i<=j){
        if(arr[i]+arr[j]>x){
            j--;
            cnt++;
        }
        else{
            cnt++;
            i++;
            j--;
        }
    }
    cout<<cnt<<endl;
    return 0;
}
