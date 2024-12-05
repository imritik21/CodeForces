/*
You are given an array consisting of N elements.
You are also given an integer K. You need to find the
longest subarray of the given array not having more than
 K distinct elements. A subarray of an array is a part or
 section of an array. It has to be continuous.

 For example if you are given an array
 arr[] = {1, 2, 3, 4, 5, 6, 7} then some of the subarrays of this
 array are {2, 3, 4}, {7}, {5, 6}. But {1, 3, 5} is not a subarray
  of the given array as the elements do not occur consecutively in
  the given array.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr = {1, 2, 3, 6, 3, 3, 2, 1 ,4, 5};
    int k = 3;

    pair<int,int> idx= {-1,-1};
    map<int,int> mp;
    int i=0,j=0;
    int n = arr.size();
    int maxi = 0,prev=0;

    while(i<n){
        mp[arr[i]]++;
        while(j<=i && mp.size()>k){
            mp[arr[j]]--;
            if(mp[arr[j]]==0){
                mp.erase(arr[j]);
            }
            j++;
        }
        if(mp.size()<=k){
            prev=maxi;
            maxi = max(maxi,i-j+1);
            // if(maxi>=prev){
            //     idx.first=j;
            //     idx.second=i;
            // }
        }
        i++;
    }
    // for(int kind=idx.first;kind<=idx.second;kind++)cout<<arr[kind]<<" ";
    // cout<<endl;
    cout<<maxi<<endl;
    return 0;
}
