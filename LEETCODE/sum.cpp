class Solution {
public:
    long long  inc(vector<int>& nums, int k){
        int n=nums.size();
        long long ops=0;
        for(int i=n/2;i<n && nums[i]<k;i++){
            ops+=k-nums[i];
        }
        return ops;
    }
    long long  dec(vector<int>& nums, int k){
        int n=nums.size();
        long long ops=0;
        for(int i=n/2;i>=0 && nums[i]>k;i--){
            ops+=nums[i]-k;
        }
        return ops;
    }
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int med=nums[n/2];
        // if(n%2==0)
        //     med=(nums[(n/2)-1]+nums[n/2])/2;
        // else
        //     med=nums[n/2];
        if(med==k)
            return 0;
        else if(med<k)
            return inc(nums,k);
        else
            return dec(nums,k);
    }
};