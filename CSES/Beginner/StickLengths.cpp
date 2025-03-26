#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());
    int temp = arr[n/2];
    ll ans = 0;
    for(auto el:arr){
        ans+=abs(el-temp);
    }
    cout<<ans<<endl;
    return 0;
}
