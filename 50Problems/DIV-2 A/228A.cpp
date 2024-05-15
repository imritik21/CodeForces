#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    set<ll> st;
    for(int i=0;i<4;i++){
        ll a;cin>>a;
        st.insert(a);
    }
    cout<<4-st.size()<<endl;
}
