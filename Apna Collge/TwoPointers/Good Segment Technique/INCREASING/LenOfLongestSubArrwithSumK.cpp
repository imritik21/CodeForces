#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout<<"Heloo"<<endl;
    vector<int> arr = {10,1,1,1,1,1};
    int n = arr.size();
    int k = 11;

    int i=0,j=0;
    // if neg ele it wont work
    // as the prefix sum is monotonic
    int maxLen = 0;
    int sum=0;
    while(i<n){
        sum+=arr[i];
        while(j<=i && sum>k){
            sum-=arr[j];
            j++;
        }
        if(sum<=k){
            maxLen = max(maxLen,i-j+1);
        }
        i++;
    }
    cout<<maxLen<<endl;
    // TC - (N+M) or O(N)
    return 0;
}
