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

    int a,b;
    cin>>a>>b;
    vector<int> arr(4,0);
    arr[a]++;
    arr[b]++;
    int ans=0;
    for(int i=1;i<4;i++){
        if(arr[i]==0) ans=i;
    }
    cout<<ans<<endl;
    return 0;
}
