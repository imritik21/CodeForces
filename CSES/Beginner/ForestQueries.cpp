#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// void solve()
// {
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,q;
    cin>>n>>q;
    vector<vector<char>> arr(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>> v(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]=='*')v[i][j]=1;
        }
    }

    
    vector<vector<int>> pre(n,vector<int>(n,0));
    pre[0][0]=v[0][0];
    for(int i=1;i<n;i++)pre[0][i]=pre[0][i-1]+v[0][i];
    for(int i=1;i<n;i++)pre[i][0]=pre[i-1][0]+v[i][0];

    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            pre[i][j]=v[i][j]+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }

    while(q--){
        ll r1,c1,r2,c2;
        cin>>r1>>c1>>r2>>c2;
        r1--;r2--;c1--;c2--;

        int result = pre[r2][c2];

        // Subtract the parts outside the query bounds
        if (r1 > 0) result -= pre[r1 - 1][c2];
        if (c1 > 0) result -= pre[r2][c1 - 1];
        if (r1 > 0 && c1 > 0) result += pre[r1 - 1][c1 - 1];

        cout << result << endl;
    }
    return 0;
}
