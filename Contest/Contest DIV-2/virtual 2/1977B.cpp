#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int x;
        cin >> x;
        vector<int> v(32);
        for (int i = 29; i >= 0; i--)
        {
            v[i] = (x >= (1 << i));
            x %= (1 << i);
        }
        // we calculated binary representaion
        // for(int i=0;i<v.size();i++)
        // cout<<v[i]<<" ";
        // now

        // starting from lsb
        for (int i = 0, j; i < 32;)
        {
            if (!v[i])
            {
                i++;
                continue; // current bit 0 nothing to do
            }
            // now when its 1
            // using this i will find till where
            j = i + 1;
            while (v[j] == 1)
            {
                v[j] = 0;
                j++;
            }
            // now
            // we know we can write   1 1 1 1
            //                 as   1 0 0 0 -1 this is what we re doing
            if (j > i + 1)
            { // check block size is > 1 is =1 dont do anything
                v[j] = 1;
                v[i] = -1; // setting lower to -1 and a bit front to 1
            }
            i = j; // i willl bcm j
        }
        cout << 32 << "\n";
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << "\n";
    }
}
