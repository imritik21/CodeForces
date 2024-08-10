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

    vector<int> arr = {5,2,1,4,3,6};
    int n =arr.size();
    vector<int> NGE(n,0);
    stack<int> st;

    for(int i=n-1;i>=0;i--){
        //      5 2 1 4 3 6
        //      6 4 4 6 6 -1
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){
            // no ele greater to it on right
            NGE[i]=-1;
        }
        else{
            NGE[i]=st.top();
        }
        st.push(arr[i]);
    }

    for(auto ele:NGE)cout<<ele<<" ";
    return 0;
}
