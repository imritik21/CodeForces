#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    int b[q];
    for (int i = 0; i < q; i++)
    {
        cin >> b[i];
    }
    bool found = false;
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (b[i] == a[mid])
        {
            found = true;
            break;
        }
        else if (b[i] > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (found)
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}