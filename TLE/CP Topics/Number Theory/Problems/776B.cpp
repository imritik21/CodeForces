#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e5 + 7;
int seive[N];
void solve()
{
    fill(seive, seive + N + 1, true);
    seive[0] = seive[1] = false;
    for (int i = 2; i * i <= N; i++)
    {
        if (seive[i] == true)
        {
            for (int j = i * i; j <= N; j += i)
            {
                seive[j] = false;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    solve();
    if (n == 1)
    {
        cout << 1 << endl;
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
    }
    else
    {
        cout<<2<<endl;
        for (int i = 2; i <= n + 1; i++)
        {
            if(seive[i]==0){
                seive[i]=2;
            }
            cout << seive[i] << " ";
        }
    }
}
