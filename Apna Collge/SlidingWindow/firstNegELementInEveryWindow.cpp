#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// first negtive in every window of size k
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {1, -1, -2, 3, -4, 5, -5};
    // -1 -1 -2 -4 -4
    vector<int> res;
    int n = arr.size();
    int k = 3;
    deque<int> dq;
    for (int i = 0; i < k; i++)
    {

        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
    }
    if (!dq.empty())
        res.push_back(arr[dq.front()]);
    else
        res.push_back(0);

    for (int i = k; i < n; i++)
    {
        // revome ele that are not in this window
        if(arr[i-k]<0)dq.pop_front();
        if (arr[i] < 0)
        {
            dq.push_back(i);
        }
        if (!dq.empty())
            res.push_back(arr[dq.front()]);
        else
            res.push_back(0);
    }
    for (auto ele : res)
        cout << ele << " ";
    return 0;
}
