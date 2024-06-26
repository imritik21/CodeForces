#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void maximumSubarraySum(vector<int>& nums, int k) {
        ll n = nums.size();
        ll l=0,r=k-1;
        ll maxSum=INT_MIN;
        ll sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        cout<<"initial "<<sum<<endl;
        int i=0;
        while(r<n-1){
            sum-=nums[l];
            cout<<"i = "<<i<<" sum = "<<sum<<endl;
            l++;
            r++;
            sum+=nums[r];
            cout<<"i = "<<i<<" sum = "<<sum<<endl;
            maxSum=max(maxSum,sum);
            cout<<"i = "<<i<<" maxSum = "<<maxSum<<endl;
            i++;
        }

        //  maxSum;
    }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> nums = {1,1,1,2,3};
    int k=3;
    maximumSubarraySum(nums,k);
    return 0;
}
