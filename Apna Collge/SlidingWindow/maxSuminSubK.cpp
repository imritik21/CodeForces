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
    vector<int> arr = {};
    int k = 3;
    int maxSum=0;
    int n = arr.size();
    int sum=0;
    
    for(int i=0;i<k;i++){
        sum+=arr[i];
    }
    int maxSum = sum;
    for(int i=k;i<n;i++){
        sum+=arr[i];
        sum-=arr[i-k];
        maxSum=max(maxSum,sum);
    }
    cout<<maxSum;
    return 0;
}
