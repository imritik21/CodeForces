#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    set<int> st; // removing dup
    st.insert(0);
    for(int i=0;i<n;i++){
        st.insert(arr[i]);
    }
    int maxi = INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){ // inc subseq
            int mx = (arr[i]|arr[j]);
            maxi = max(maxi,mx);
        }
    }
    st.insert(maxi);

    // cout<<maxi2;
    for(auto it:st){
        cout<<it<<endl;
    }
}
