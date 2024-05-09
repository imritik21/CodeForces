#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    int n;
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> vec(3);
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(c);
        int cnt = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i] == 1)
            {
                cnt++;
            }
        }

        if (cnt > 1)
        {
            mx++;
        }
    }
    cout << mx << endl;
}
