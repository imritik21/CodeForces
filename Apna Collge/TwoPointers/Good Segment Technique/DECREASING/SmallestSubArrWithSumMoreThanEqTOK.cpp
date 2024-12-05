/*
given an arr of positive integers find the lentgh of smallest
subarray with sum >=k
*/
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
    
    vector<int> arr = {1,1,1,2,3,4,5};
    int k = 3;

    int n = arr.size();
    int  minLen = INT_MAX;

    int i=0,j=0,sum=0;
    while(i<n){
        sum+=arr[i];
        while(j<=i && sum>=k){
            minLen = min(minLen,i-j+1);
            sum-=arr[j];
            j++;
        }
        i++;
    }
    cout<<minLen<<endl;
    return 0;
}
