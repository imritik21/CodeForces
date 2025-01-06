#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
string str = "";
string findShortestPathBFS(int src_row, int src_col, int dest_row, int dest_col, vector<vector<char>> &arr,string &ans) {
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    vector<char> dir_chars = {'D', 'U', 'L', 'R'};

    q.push({src_row, src_col});
    vis[src_row][src_col] = 1;

    while (!q.empty()) {
        // auto [row, col] = q.front();
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == dest_row && col == dest_col) break;

        for (int i = 0; i < directions.size(); i++) {
            int nrow = row + directions[i].first;
            int ncol = col + directions[i].second;

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                arr[nrow][ncol] != '#' && !vis[nrow][ncol]) {
                vis[nrow][ncol] = 1;
                parent[nrow][ncol] = {row, col};
                q.push({nrow, ncol});
            }
        }
    }

    if (!vis[dest_row][dest_col]) return "NO";

    string path = "";
    int cur_row = dest_row, cur_col = dest_col;
    while (cur_row != src_row || cur_col != src_col) {
        // auto [prev_row, prev_col] = parent[cur_row][cur_col];
        int prev_row = parent[cur_row][cur_col].first;
        int prev_col = parent[cur_row][cur_col].second;
        for (int i = 0; i < directions.size(); i++) {
            if (prev_row + directions[i].first == cur_row &&
                prev_col + directions[i].second == cur_col) {
                path += dir_chars[i];
                break;
            }
        }
        cur_row = prev_row;
        cur_col = prev_col;
    }

    reverse(path.begin(), path.end());
    ans=path;
    return "YES";
}
//  DFS but it doesnot guarantee shortest path
// bool hasPath(int src_row, int src_col, int dest_row, int dest_col,
//              vector<vector<char>> &arr, vector<vector<int>> &vis)
// {
//     if (src_row == dest_row && src_col == dest_col)
//     {
//         return true;
//     }
//     vis[src_row][src_col] = 1;
//     int n = arr.size();
//     int m = arr[0].size();
//     vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
//     vector<char> char_dir = {'D', 'U', 'L', 'R'};
//     for (int i = 0; i < directions.size(); i++)
//     {
//         int nrow = src_row + directions[i].first;
//         int ncol = src_col + directions[i].second;

//         if (nrow >= 0 && nrow < n && !vis[nrow][ncol] && arr[nrow][ncol] != '#')
//         {

//             if (hasPath(nrow, ncol, dest_row, dest_col, arr, vis))
//             {
//                 str += char_dir[i]; // while backtracking
//                 return true;
//             }
//         }
//     }
//     return false;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> arr(n, vector<char>(m));
    int src_row = -1, src_col = -1;
    int dest_row = -1, dest_col = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
            {
                src_row = i;
                src_col = j;
            }
            if (arr[i][j] == 'B')
            {
                dest_row = i;
                dest_col = j;
            }
        }
    }
    // vector<vector<int>> vis(n, vector<int>(m, 0));
    string ans="";
    string res=findShortestPathBFS(src_row,src_col,dest_row,dest_col,arr,ans);
    if(res=="YES"){
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        cout<<ans<<endl;
    }
    else cout<<"NO"<<endl;
    // cout<<findShortestPathBFS(src_row,src_col,dest_row,dest_col,arr,ans);
    return 0;
}
