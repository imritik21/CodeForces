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
        while(!st.empty() && st.top()<=arr[i]){
            st.pop();
        }
        if(st.empty()){ // no index which is greater than this on right
          // eg  5 3 2 1
          //    -1 all popped (3,2,1) st is empty so no ele on right is >
            NGE[i]=-1;
        }
        else{
            // after removal is stack is not empty then that ele is NGE
            NGE[i]=st.top();
        }
        st.push(arr[i]); // this may be the NGE of other ele on left so push
    }
    for(auto ele: arr)cout<<ele<<" ";
    cout<<endl;
    for(auto ele: NGE)cout<<ele<<" ";
    return 0;
}
