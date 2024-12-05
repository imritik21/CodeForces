#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void solve()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 8;
    
    // Corrected to use floating-point division
    double logResult = log2(static_cast<double>(n)); // or log2(n / 4.0)
    
    int ans = static_cast<int>(logResult);    // Truncated version
    int ans2 = static_cast<int>(ceil(logResult)); // Ceil version

    cout << ans << " " << ans2 << "\n"; // Output: 1 2

    // ll mask = 1LL<<1;
    // cout<<mask;

    return 0;
}
