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
    // flush
    
    vector<int> arr = {5,5,5,5,6,6};
    int ele = 5;
    int n = arr.size();
    int cnt=0,key=arr[0];
    for(int i=0;i<n;i++){
        if(cnt==0)key=arr[i];
        if(arr[i]==key)cnt++;
        else cnt--;
    }
    for(int i=0;i<n;i++)if(arr[i]==key)cnt++;
    if(cnt>=n/2){
        cout<<"YES element is repeated n/2 times"<<endl;
    }
    else cout<<"NO, The element is not repeated"<<endl;
    // cout<<key<<endl;
    return 0;
}
