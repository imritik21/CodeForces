#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main()
{
    string str;
    cin >> str;
    int ans = 0;
    int cntL = 0, cntR = 0;
    // ya to string L se shuru hoga ya R se
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'L')
            cntL++;
        else
            cntR++;
        if ((cntL - cntR) == 0)
        {
            ans++;
        }
    }
    cout<<ans<<endl;
}
