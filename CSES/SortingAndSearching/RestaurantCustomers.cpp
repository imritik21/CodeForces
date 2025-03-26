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
    vector<ll> arr(1e5 + 7, 0);
    //  2 3 4 5 6 7 8 9
    //  1 1 -1 1    -1 -1
    vector<pair<ll,ll>> vec;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        vec.push_back({x, 1});
        vec.push_back({y, -1}); 
    }
    sort(vec.begin(),vec.end());
    ll maxi=-1;
    ll curr=0;
    for(int i=0;i<vec.size();i++){
        curr+=vec[i].second;
        maxi=max(maxi,curr);
    }

    cout<<maxi<<endl;
    return 0;
}
