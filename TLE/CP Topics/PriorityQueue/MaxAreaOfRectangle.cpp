#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
    // LEETCODE - MAXIMUM AREA OF HISTOGRAM
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // vector<int> arr = {3,1,2,4,2,3};
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    vector<int> NSL(n,0);
    vector<int> NSR(n,0);
    // next smaller to left mtlb 0 se n tk jao
    //               3  1 2 4 2 3
    //              -1 -1 1 2 1 4
    stack<int> st1,st2;
    for(int i=0;i<n;i++){
        while(!st1.empty() && arr[st1.top()]>=arr[i]){
            st1.pop();
        }
        if(st1.empty()){
            NSL[i]=-1;
        }
        else{
            NSL[i] = st1.top();
        }
        st1.push(i);
    }
    for(int i=n-1;i>=0;i--){
        while(!st2.empty() && arr[st2.top()]>=arr[i]){
            st2.pop();
        }
        if(st2.empty()){
            NSR[i]=n;
        }
        else{
            NSR[i] = st2.top();
        }
        st2.push(i);
    }
    // max Area
    int maxArea = 0;
    for(int i=0;i<n;i++){
        maxArea = max(maxArea,arr[i]*(i-NSL[i]+NSR[i]-i-1));
    }
    cout<<maxArea<<endl;
    return 0;
}
