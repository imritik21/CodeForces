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
    vector<int> nums = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k = 3;
    int n = nums.size();
    // brute - generate all subarrayz and take maxlen of atmost k zeroes
    // int maxlen= INT_MIN;
    // for(int i=0;i<n;i++){
    //     int zeroes = 0;
    //     for(int j=i;j<n;j++){
    //         if(nums[j]==0) zeroes++;
    //         if(zeroes<=k){
    //             maxlen=max(maxlen,j-i+1);
    //         }
    //     }
    // }
    // cout<<maxlen<<endl;
    // optimal - 2 pointer same approach when we'll encounter more than k
    // zereos we'll shift low
    int l=0,r=0;
    int maxlen=INT_MIN;
    int zero=0;
    while(r<n){
        if(nums[r]==0) zero++;
        // cond
        while(zero>k){
            if(nums[l]==0) zero--;
            l++;
        }
        if(zero<=k){
            maxlen=max(maxlen,r-l+1);
        }
        r++;
    }
    cout<<maxlen<<endl;
    return 0;
}
