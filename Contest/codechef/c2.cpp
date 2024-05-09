#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    { // Use 0-based indexing for clarity
        cin >> arr[i];
    }
    long long cnt = 0; // Use long long for potentially large counts

    for (int i = 0; i < n; i++)
    {
        int j =0; // Start j from i+1
        while (j < n && pow(arr[i], j-i) > arr[j]) // Adjust condition to compare pow(arr[i], j-i) with arr[j]
        {
            j++; // Increment j as long as arr[i]^j is less than or equal to arr[j]
        }
        if(pow(arr[i],j)<=arr[j]){
                cnt++;
            }
    }

    cout << cnt << endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}
