#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// you have given 30 days and N workers and 
// you have to find two such workers with maximum
// common working days 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n; // total workers
    vector<int> masks(n,0);
    for(int i=0;i<n;i++){
        int num_workers;
        cin>>num_workers;
        int mask=0;
        for(int j=0;j<num_workers;j++){
            int day;
            cin>>day;
            mask = (mask|(1<<day)); // eg 7th day as 7th bit
        }
        masks[i]=mask;
    }
    int max_days=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int intersection = (masks[i]&masks[j]);
            int common_days = __builtin_popcount(intersection);
            max_days = max(max_days,common_days);
        }
    }
    cout<<max_days<<endl;
    return 0;
}
