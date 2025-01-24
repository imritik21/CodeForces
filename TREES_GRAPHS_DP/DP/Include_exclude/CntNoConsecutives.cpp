#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// Problem: Given a binary string
// find total no of n length possible binary string 
// where no 0's are consecutive
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // there can be 2 ways
    // string ending with 0 and 1
    //             len_0  1  2  3  4  5  6
    // end with 0:  0     1  prev 1's ke peeche 0
    // end with 1:  0     1  prev 0's and 1's both ke peeche 1
    int n;
    cin>>n;
    vector<int> dp_1(n,0),dp_0(n,0);
    dp_1[0]=0;dp_0[0]=0;
    dp_1[1]=1;dp_0[1]=1;

    for(int i=2;i<n+1;i++){
        dp_1[i] = dp_0[i-1]+dp_1[i-1];
        dp_0[i] = dp_1[i-1];
    }
    cout<<dp_1[n]+dp_0[n]<<endl;
    return 0;
}
