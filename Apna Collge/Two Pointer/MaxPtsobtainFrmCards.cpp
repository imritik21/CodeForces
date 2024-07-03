#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {6,2,3,4,7,2,1,7,1};
    int n  = arr.size();
    int k  = 4;
    int maxSum=0;
    int lsum=0,rsum=0;
    for(int i=0;i<=k-1;i++){
        lsum+=arr[i];
        maxSum=max(maxSum,lsum);
    }
    // now we need to shrink lsum from k-1 to 0 ele
    int ind = n-1;
    for(int i=k-1;i>=0;i--){
        lsum-=arr[i];
        rsum+=arr[ind];
        ind--;
        maxSum=max(maxSum,lsum+rsum);
    }
    cout<<maxSum<<endl;
    return 0;
}
