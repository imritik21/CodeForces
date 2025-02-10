#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool possible(ll x, vector<int> &ranks, int cars)
{
    ll totCars = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        ll curr = x / ranks[i]; // 16/4
        ll currCar = sqrt(curr);
        totCars += currCar;
        if (totCars >= cars)
            return true;
    }
    cout<<totCars<<endl;
    return false;
}
long long repairCars(vector<int> &ranks, int cars)
{
    // 1 2 3 4  cars=10
    // binary search on time
    int n = ranks.size();
    ll ans = -1;
    ll lb = 1, ub = 576;
    while (lb <= ub)
    {
        ll mid = (lb + ub) / 2;
        // cout<<"mid "<<mid<<endl;
        // FFFFFFFFFFFFTTTTTTTTT......
        if (possible(mid, ranks, cars))
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
    
    // vector<int> ranks = {4,2,3,1};  // ans=16 true
    vector<int> ranks = {1,1,3,3};
    int cars = 74;
    cout<<repairCars(ranks,cars)<<endl;
    return 0;
}
