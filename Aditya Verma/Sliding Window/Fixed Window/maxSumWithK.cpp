// given an array and k(window size)
// you need to find the maximum sum
// brute
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
/// sliding window approach O(N)
int maxSumSubarray(int arr[], int n, int k)
{
    int maxSum = 0;
    int windowSum = 0;

    // Calculate sum of first window
    for (int i = 0; i < k; i++)
    {
        windowSum += arr[i];
    }

    // Update maxSum
    maxSum = windowSum;

    // Slide the window
    for (int i = k; i < n; i++)
    {
        windowSum += arr[i] - arr[i - k];
        maxSum = max(maxSum, windowSum);
    }

    return maxSum;
}
// another naive approach
long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    // code here
    int i = 0;
    int j = 0;
    long long mx = INT_MIN;
    long long sum = 0;
    while (j < N)
    {
        sum = sum + Arr[j];
        // reach window size
        if ((j - i + 1) < K)
            j++;
        // now when you hit the window calc
        else if ((j - i + 1) == K)
        {
            mx = max(mx, sum); // now slide the window
            sum = sum - Arr[i];
            i++;
            j++;
        }
    }
    return mx;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    //
    ll maxSum = 0;
    for (int i = 0; i + k < n; i++)
    {
        ll sum = 0;
        for (int j = i; j < i + k; j++)
        {
            sum += arr[j];
        }
        maxSum = max(maxSum, sum);
    }
    cout << maxSum << endl;
}
