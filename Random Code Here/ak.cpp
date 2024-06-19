#include <bits/stdc++.h>
using namespace std;
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
  deque<long long int> formax;
  deque<long long int> formin;
  long long int ans = 0;

  for (int i = 0; i < n; i++) {

    // if window sized reached
    if (!formax.empty() && i - formax.front() >= k) {
      formax.pop_front();
    }
    if (!formin.empty() && i - formin.front() >= k) {
      formin.pop_front();
    }

    while (!formax.empty() && nums[i] >= nums[formax.back()]) {
      formax.pop_back();
    }
	formax.push_back(i);
    while (!formin.empty() && nums[i] <= nums[formin.back()]) {
      formin.pop_back();
    }
	formin.push_back(i);
	
	if(i >= k-1){
		ans += nums[formax.front()] + nums[formin.front()];
	}
  }
  return ans;
}
int main(){
    int tc;cin>>tc;
    while(tc--){
        int n,k;
        cin>>n>>k;
        vector<int> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        long long ans=sumOfMaxAndMin(nums,n,k);
        cout<<ans<<endl;
    }
}