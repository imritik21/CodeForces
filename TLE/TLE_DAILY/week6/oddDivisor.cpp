#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        while(n%2==0){
            n/=2;
        }
        if(n != 1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}