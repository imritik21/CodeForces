#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int countOnes(int num) {
    bitset<32> bits(num);
    return bits.count();
}
bool check(const vector<int> nums,int n){
    for(int i=0;i<n;i++){
        if(nums[i]>nums[i+1]) return false;
    }
    return true;
}
signed main(){
    int n;
    cin>>n;
    int nums[n];
    for(int i=0;i<n;i++) cin>>nums[i];
    unordered_map<int,int> mpp;
    for(int i=0;i<n;i++){
        int num=nums[i];
        int count1=countOnes(num);
        mpp[num]=count1;
    }
    for(int i=0;i<n;i++){
        if(nums[i]>nums[i+1]){
            if(mpp[nums[i]]==mpp[nums[i+1]]){
                swap(nums[i],nums[i+1]);
            }
        }
        if(check(&nums,n)){
            cout<<"YES"<<endl;
            break;
        }
        else{
            cout<<"NO"<<endl;
            break;
        }
    }
}