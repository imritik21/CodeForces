// i have given 2 arryas and i have to find
// for every ele of arr1 how much ele in arr2
// are smaller than this
// app 1 - Binary Search TC-O(NlogN);
// app 2 - Two Pointers TC-O(N);

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
    
    int n,m;cin>>n>>m;
    vector<int> a(n),b(m);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    vector<int> ans(n);

    int i=0,j=0;
    while(i<n){
        while(j<m && b[j]<a[i])j++;
        ans[i]=j;
        i++;
    }
    for(auto ele:ans)cout<<ele<<" ";
    // TC is O(N); 
    // this can be very useful while in contest
    // when we would have tto itrate over n and we nneed thsi
    // for constraints n<=5000 (N^2) would get AC but (ON^2logN) wouldn't;
    return 0;
}
