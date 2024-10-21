#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define ceil 
long long maxKelements(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (auto ele : nums)
    {
        pq.push(ele);
    }
    long long res = 0;
    while (!pq.empty() && k > 0)
    {
        res += pq.top();
        int curr = pq.top();
        curr = ceil((long double)curr/3);
        pq.pop();
        pq.push(curr);
        k--;
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> nums = {756902131,995414896,95906472,149914376,387433380,848985151};
    int k=6;
    cout<<maxKelements(nums,k)<<endl;
    return 0;
}
