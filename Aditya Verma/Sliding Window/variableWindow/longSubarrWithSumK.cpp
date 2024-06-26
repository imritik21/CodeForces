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
    vector<int> arr = {2,5,1,10,10};
    int n = arr.size();
    int k = 14;

    int l=0,r=0,sum=0,maxLen=0;
    while(r<n-1){
        sum+=arr[r];
        // checking valid 
        if(sum>k){
            sum-=arr[l];
            l++;
        }
        if(sum<=k){
            maxLen=max(maxLen,r-l+1);
        }
        r++;
    }
    //3
    cout<<maxLen<<endl;
    return 0;
}
