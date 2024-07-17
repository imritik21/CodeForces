#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    vector<int> arr = {5,10,10,100,5,6};
    // now i need to find out maxSum of subarrays with no two consec ele
    // typical greedy include exclude
    // if we include 5 then we need to exclude next ele
    // thus for excluding we'll take max of prev incl
    int inc = arr[0];
    int exc = 0;
    int n = arr.size();
    for(int i=1;i<n;i++){
        int newInc = arr[i]+exc; // new ele + prev exclude
        int newExc = max(inc,exc);
        inc = newInc;
        exc = newExc;
    }
    cout<<max(inc,exc)<<endl;
    return 0;
}
