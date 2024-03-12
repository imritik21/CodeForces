#include <bits/stdc++.h>
using namespace std;

bool canmakeZero(vector<int> &ans)
{
    int n = ans.size();
    if (n <= 2)
        return true;

    int summ = accumulate(ans.begin(), ans.end(), 0);
    if (summ % 2 != 0)
        return false;

    int target = summ / 2;
    sort(ans.begin(), ans.end());

    int currentSum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        currentSum += ans[i];
        if (currentSum == target)
            return true;
    }

    return false;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ans[i];
        }
        if (canmakeZero(ans))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }

    return 0;
}