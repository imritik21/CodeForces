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
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    multiset<int> st;
    for(int i=0;i<n;i++){
        st.insert(v[i]);
    }
    int ans=0;
    while(!st.empty()){
        // ans++;
        // int val = *st.begin();
        // st.erase(st.begin());

        // while(st.upper_bound(val) != st.end()){
        //     int newVal = *st.upper_bound(val);
        //     st.erase(st.find(newVal));
        //     val= newVal;
        // }
        ans++;
        int val = *st.begin();
        st.erase(st.begin());
                 // 2 3 4 4      2 is removed upper_bound will get 3
        while(st.upper_bound(val) != st.end()){ // upper bound repeated value nhi lega isiliye
            int newVal = *st.upper_bound(val);
            st.erase(st.find(newVal));
            val = newVal;
        }
    }
    cout<<ans<<'\n';
    return 0;
}
