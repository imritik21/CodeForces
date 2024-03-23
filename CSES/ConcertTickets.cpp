#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n,m;
    cin>>n>>m;
    multiset<int> st;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        st.insert(a);
    }
    for(int i=0;i<m;i++){
        int a;cin>>a;
        if(st.empty()){
            cout<<-1<<endl;
            continue;
        }
        if(a< *st.begin()){
            cout<<-1<<endl;
            continue;
        }
        auto it = st.upper_bound(a);
        it--;
        cout<<*it<<endl;
        st.erase(it);
    }
}
