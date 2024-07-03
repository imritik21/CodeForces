#include <iostream>
#include <vector>

using namespace std;
int findoddSum(vector<int>& nums){
    int n = nums.size();
    int i=0;
    int countOddevn=0;
    while(i<n && nums[i]%2==0) i++;
    int f=1;
    while(i<n){
        if(nums[i]%2==f){
            countOddevn++;
            f=1-f;
        }
        i++;
    }
    i=0;
    int countevenOdd=0;
    while(i<n && nums[i]%2==1) i++;
    f = 0;
    while(i<n){
        if(nums[i]%2==f){
            countevenOdd++;
            f=1-f;
        }
        i++;
    }
    return max(countOddevn,countevenOdd);
}
int findEvenSum(vector<int>& nums){
    int n = nums.size();
    int even=0;
    for(auto num:nums){
        if(num%2==0) even++;
    }
    return max(even,n-even);
}

int main() {
    vector<int> nums = {4,51,68};
    cout<<max(findEvenSum(nums),findoddSum(nums));
    return 0;
}
