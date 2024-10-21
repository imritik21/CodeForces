#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr = {6,8,0,1,3};
    ////////////////  8 -1 1 3 -1
    int n = arr.size();
    vector<int> NGE(n,0);

    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            NGE[i]=-1;
        }
        else{
            NGE[i] = st.top();
        }
        st.push(arr[i]);
    }
    for(auto& i:NGE)cout<<i<<" ";
    return 0;
}
