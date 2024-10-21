#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr1 = {1,4,5,9};
    vector<int> arr2 = {2,3,6,10};

    vector<int> final;
    int i=0,j=0;
    int n = arr1.size();
    int m = arr2.size();
    while(i<n && j<m){
        if(arr1[i]<=arr2[j]){
            final.push_back(arr1[i]);
            i++;
        }
        else{
            final.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n)final.push_back(arr1[i++]);
    while(j<m)final.push_back(arr2[j++]);

    for(auto &ele:final)cout<<ele<<" ";
    cout<<"hello";
    return 0;
}
