#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
const int N = 1e9 + 1;
vector<int> queryResults(int limit, vector<vector<int>> &queries)
{
    int n = queries.size();
    vector<int> ball(N, 0);
    vector<int> color(N, 0);
    int cnt = 0;
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        int ballidx = queries[i][0];
        int coloridx = queries[i][1];
        if (ball[ballidx] == 0 && color[coloridx] == 0)
        {
            cnt++;
            ball[ballidx] = 1;
            color[coloridx] = 1;
            ans.push_back(cnt);
        }
        else
        {
            // cnt will remain unchange
            ans.push_back(cnt);
        }
    }
    return ans;
}
int main()
{
    int limit=4;
    vector<vector<int,int>> queries(n,vector<int>(2));
    vector<int> res = queryResults(limit,queries);
}
