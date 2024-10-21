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

    vector<int> arr = {1,2,3,4,5,6,7,8,10,11,12,16,20};
    // now i need to find no of ele btw l and r 
    // where l = 4 and r=12
    int idx1 = upper_bound(arr.begin(),arr.end(),4)-arr.begin();
    int idx2 = lower_bound(arr.begin(),arr.end(),12)-arr.begin();
    int temp = idx2-idx1;
    cout<<idx1<<" "<<idx2<<endl;
    cout<<temp<<endl;
    return 0;
}
