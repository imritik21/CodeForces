#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    
    int ans = 0, i = 0, j = 0;
    int sum = 0;

    // Sliding window technique
    while (j < n) {
        sum += arr[j];  // Add the right boundary element

        // Shrink the window if the sum exceeds k
        while (i <= j && sum > k) {
            sum -= arr[i];
            i++;
        }

        // If the current sum is equal to k, calculate the length of the window
        if (sum == k) {
            ans = max(ans, j - i + 1);  // Update maximum length
        }
        
        j++;  // Move the right boundary forward
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while (tc--) {
        solve();
    }

    return 0;
}
