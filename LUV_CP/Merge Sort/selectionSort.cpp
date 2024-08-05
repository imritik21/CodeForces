#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr = {4,5,3,2,1};
    // find min in every step and swap
    for(int i=0;i+1<arr.size();i++){
        int minIdx = i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[j]<arr[minIdx]){
                minIdx=j;
            }
        }
        swap(arr[minIdx],arr[i]);
    }
    for(auto ele: arr)cout<<ele<<" ";
    return 0;
}
