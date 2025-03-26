#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
map<string,int> mp;
int cnt=0;
void findSubset(string str,string ans,int idx)
{
    if(idx==str.size()){
        cout<<ans<<endl;
        
        // if(ans.size()){
        //     if (mp.find(ans) == mp.end())
        //     {
        //         cout << "aaya" << endl;
        //         mp[ans]++;
                cnt++;
        //     }
        // }
        return;
    }
    //yes include
    findSubset(str,ans+str[idx],idx+1);
    // Not include
    findSubset(str,ans,idx+1);
}
vector<int> curr;
void subset(vector<int>&nums,int idx){
    if(idx==nums.size()){
        for(int i=0;i<curr.size();i++){
            cout<<curr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    // not include
    subset(nums,idx+1);
    curr.push_back(nums[idx]);
    subset(nums,idx+1);
    curr.pop_back();
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    string str = "AAABBC";
    // vector<int> nums = {1,2,3};
    // subset(nums,0);
    findSubset(str," ",0);
    cout<<endl;
    for(auto& it:mp)cout<<it.first<<endl;
    cout<<cnt<<endl;
    return 0;
}
