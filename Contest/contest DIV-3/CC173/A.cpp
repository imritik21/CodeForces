#include <bits/stdc++.h>
using namespace std;

vector<int> help(vector<int> &brr)
{
    int n = brr.size();
    vector<int> doubled(2 * n);

    for (int i = 0; i < 2 * n; i++)
        doubled[i] = brr[i % n];

    int best = 0, candidate = 1, k = 0;

    while (candidate < n)
    {
        if (doubled[best + k] == doubled[candidate + k])
        {
            k++;
            if (k == n)
                break;
        }
        else if (doubled[best + k] < doubled[candidate + k])
        {
            candidate += k + 1;
            k = 0;
        }
        else
        {
            best = candidate;
            candidate = best + 1;
            k = 0;
        }
    }

    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = doubled[best + i];

    return result;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n), brr(m);

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
        cin >> brr[i];

    if (m == 1)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > brr[0])
                arr[i] = brr[0];
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    vector<int> b = help(brr);
    vector<int> vis(n, 0);

    int i = 0, j = 0;
    map<int,int> mp;
    while (i < n)
    {
        
        if(arr[i]<b[0]){
            i++;
        }
        else if(arr[i]>b[0]){
            if ((i+m)-1 < n)
            {
                // vec.push_back({i, ((i + m) - 1)});
                mp[i]++;
                i += (m);
                // cout<<i<<endl;
            }
            else{
                i++;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(mp.find(i)!=mp.end()){
            for(int j=0;j<m;j++)cout<<b[j]<<" ";
            i+=(m-1);
        }
        else cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        solve();
    }

    return 0;
}
