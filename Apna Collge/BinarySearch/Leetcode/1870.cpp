#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool possible(int x, vector<int> &dist, double hour)
{
    double tot = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        tot += (dist[i] /(double) x);
        if (tot > hour)
            return false;
        double extra = tot - floor(tot);
        // if (x == 100000)
        //     cout << tot << " " << extra << " ";
        if (extra > 0)
        {
            tot -= extra;
            tot += 1;
        }
        // if (x == 100000)
        //     cout << tot << endl;
    }
    return true;
}
int minSpeedOnTime(vector<int> &dist, double hour)
{
    int n = dist.size();
    int ans = -1;
    int lb = 1, ub = 1e7;
    while (lb <= ub)
    {
        int mid = (lb + ub) / 2;
        cout<<"mid "<<mid<<endl;
        // FFFFFFFFFFFFTTTTTTTT....
        if (possible(mid, dist, hour))
        {
            ans = mid;
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // vector<int> dist = {1,3,2};  // ans=3 fine
    vector<int> dist = {1,1,100000};
    double hour = 2.01;
    cout<<minSpeedOnTime(dist,hour)<<endl;
    return 0;
}
