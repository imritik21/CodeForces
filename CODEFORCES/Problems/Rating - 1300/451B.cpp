#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // 1<n<=10^5
    if (is_sorted(arr, arr + n))
    {
        cout << "yes\n";
        cout << 1 << " " << 1;
    }
    else
    {
        bool flag = false;
        int index1 = -1;
        int index2 = -1;
        for (int i = 0; i < n; i++)
        {
            flag = false;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] > arr[j])
                {
                    flag = true;
                    index1=i;
                    index2 = j;
                    swap(arr[i], arr[j]);
                    break;
                }
            }
            if (flag)
                break;
        }
        if (flag && is_sorted(arr, arr + n))
        {
            cout << "yes" << endl;
            cout << index1 << " " << index2 << endl;
        }
        else
            cout << "no" << endl;
    }
}
