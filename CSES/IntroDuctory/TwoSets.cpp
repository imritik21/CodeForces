#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;
    // 4    1 4   2 3  sum = 10
    // 5   1 2 5   3 4 sum = 15
    // 6   1 2 3 4 5 6 sum = odd
    // 3   1 2 3
    // 7   1 2 3 4 5 6 7  sum=28
    // 8   sum = 36     2 3 6 7    1 4 5 8
    ll sum = (1LL * n * (1LL * n + 1)) / 2;
    // cout << sum << endl;
    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        vector<int> set1, set2;
        ll target = sum / 2;
        for (int i = n; i >= 1; i--)
        {
            if (target >= i)
            {
                set1.push_back(i);
                target -= i;
            }
            else
            {
                set2.push_back(i);
            }
        }
        cout<<"YES"<<endl;
        cout<<set1.size()<<endl;
        for(int i=0;i<set1.size();i++)cout<<set1[i]<<" ";
        cout<<endl;
        cout<<set2.size()<<endl;
        for(auto& ele:set2)cout<<ele<<" ";
        cout<<endl;
    }
    return 0;
}
