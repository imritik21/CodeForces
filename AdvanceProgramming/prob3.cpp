/*
3. Given a and b . Find the number of possible values that x can get
    so that the equation a%x = b
*/
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

    int a, b;
    cin >> a >> b;
    if (b >= a)
    {
        cout << "Not possible " << endl;
        return 1;
    }
    int d = a - b;
    int cnt = 0;
    vector<int> valid;
    for (int x = 1; x * x <= d; x++)
    {
        if (d % x == 0 )
        {
            if (x > b)
            {
                valid.push_back(x);
            }
            if (d / x != x && d / x > b)
            {
                valid.push_back(d / x);
            }
        }
    }
    cout << valid.size() << endl;
    for(auto ele:valid)cout<<ele<<" ";
    cout<<endl;
    return 0;
}
