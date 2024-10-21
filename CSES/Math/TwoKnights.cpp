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
    
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        ll curr = i*i;
        ll tot = (curr*(curr-1))/2;
        ll invalid = 2*(2*(i-2)*(i-1));
        cout<<(tot-invalid)<<endl;
    }
    return 0;
}
