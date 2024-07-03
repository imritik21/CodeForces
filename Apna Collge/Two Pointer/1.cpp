#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestValidSubsequence(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;

    // Variables to track the longest valid subsequence length
    int longestLength = 1;
    int currentLength = 1;

    for (int i = 1; i < n; ++i)
    {
        // Check if the sum of nums[i] and nums[i-1] has the same parity as nums[i-1] and nums[i-2]
        if ((nums[i] + nums[i - 1]) % 2 == (nums[i - 1] + nums[i - 2]) % 2)
        {
            currentLength++;
        }
        else
        {
            currentLength = 2; // Reset to 2 since we have a new starting pair
        }
        longestLength = max(longestLength, currentLength);
    }

    return longestLength;
}

int main()
{
    vector<int> nums = {4,51,68};
    int n = nums.size();
    int oddEven = 0;
    bool flag = false; // This will toggle between true (odd) and false (even)

    for (int i = 0; i < n; ++i)
    {
        if (nums[i] % 2 == 1)
        { // If current element is odd
            if (flag)
            {                 // If flag is true (indicating previous was even)
                oddEven++;    // Found an alternating subsequence
                flag = false; // Toggle flag
            }
        }
        else
        { // If current element is even
            if (!flag)
            {                // If flag is false (indicating previous was odd)
                oddEven++;   // Found an alternating subsequence
                flag = true; // Toggle flag
            }
        }
    }
    int evenOdd = 0;
    bool flag1 = (nums[0] % 2 == 0); // Initialize flag based on first element's parity
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] % 2 == 0) { // Current element is even
            if (!flag1) { // If previous was odd
                evenOdd++; // Found an alternating subsequence
                flag1 = true; // Toggle flag
            }
        } else { // Current element is odd
            if (flag1) { // If previous was even
                evenOdd++; // Found an alternating subsequence
                flag1 = false; // Toggle flag
            }
        }
    }
    cout<<evenOdd<<endl;
    cout << oddEven << endl;
}
