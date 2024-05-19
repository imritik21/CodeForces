#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// allowed directon are down and right
int maze(int i, int j, int n, int m, vector<vector<int>> &blocked)
{
    if (i == n - 1 && j == m - 1)
        return 1; // last posn reached kiya to 1
    if (i == n || j == m)
        return 0; // boundry cond
    if (blocked[i][j] == 1)
        return 0;
    else if (blocked[i][j] == 0)
    {

        return maze(i + 1, j, n, m, blocked)+maze(i, j + 1, n, m, blocked);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> blocked(n, vector<int>(m, 0));

    int k;
    cin >> k;
    while (k--)
    {
        int i, j;
        cin >> i >> j;
        blocked[i - 1][j - 1] = 1; // cell ko 1 mark 
    }
    cout << maze(0, 0, n, m, blocked);
}
