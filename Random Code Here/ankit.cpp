#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int minElementsToSum(vector<int>& arr, int k) {
    vector<int> dp(k + 1, numeric_limits<int>::max());
    dp[0] = 0;

    for (int coin : arr) {
        for (int j = coin; j <= k; ++j) {
            if (dp[j - coin] != numeric_limits<int>::max()) {
                dp[j] = min(dp[j], dp[j - coin] + 1);
            }
        }
    }

    return (dp[k] == numeric_limits<int>::max()) ? -1 : dp[k];
}

int main() {
    int n;cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int k ; cin>>k;
    cout << minElementsToSum(arr, k) << endl;

    return 0;
}
