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
    int a,k;
    cin>>a>>k;
    // for(int i=0;i<=k;i++){
    //     a= a^(1<<k);
    // }
    a = a^(1<<k);
    cout<<a<<endl;
    return 0;
}
