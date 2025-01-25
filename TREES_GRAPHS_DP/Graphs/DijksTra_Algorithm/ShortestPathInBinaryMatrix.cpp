#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
void solve() {}
int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<vector<int>> grid = {{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> dist(n, vector<int>(m, 1e9));
  vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  dist[0][0] = 0;
  queue<pair<int, pair<int, int>>> q;
  q.push({0, {0, 0}});

  while (!q.empty())
  {
    int dis = q.front().first;
    int row = q.front().second.first;
    int col = q.front().second.second;
    q.pop();
    if (row == n - 1 && col == m - 1)
    {
      cout << dist[row][col] << endl;
      return 0;
    }
    for (auto &d : dir)
    {
      int nrow = row + d.first;
      int ncol = col + d.second;
      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0)
      {
        if (dist[nrow][ncol] > dis + 1)
        {
          dist[nrow][ncol] = dis + 1;
          q.push({dis + 1, {nrow, ncol}});
        }
      }
    }
  }
  return 0;
}
