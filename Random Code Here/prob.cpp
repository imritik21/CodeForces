#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {3,1,2};
    //      1 2 3
    //      
    int op = 0;
    sort(arr.begin(), arr.end());


    int c = 1;
    for (int i = 0; i < arr.size(); i++)
    {

        if (arr[i] < c)
        continue;
        op += (arr[i] - c);
        // if((arr[i]-c)==0)continue;
        c++;
    }
    cout << op << endl;
    return 0;
}
