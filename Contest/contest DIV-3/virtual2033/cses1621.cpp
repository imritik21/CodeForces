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
    ll n;
    cin>>n;
    vector<ll> arr(n);
    set<ll> st;
    for(auto& i:arr){
        cin>>i;
        st.insert(i);
    }
    cout<<st.size()<<endl;
    return 0;
}
