#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int mini=INT_MAX,maxi=INT_MIN;
void minMax(int l,int h,vector<int>&arr){
    if(l==h){
        mini = min(mini,arr[l]);
        maxi = max(maxi,arr[l]);
        return;
    }
    else if(l==h-1){
        if(arr[l]<arr[h]){
            mini=min(mini,arr[l]);
            maxi=max(maxi,arr[h]);
        }
        else{
            mini=min(mini,arr[h]);
            maxi=max(maxi,arr[l]);
        }
        return;
    }
    int mid = (l+h)/2;
    minMax(l,mid,arr);
    minMax(mid+1,h,arr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    // vector<int> arr = {1,5,6,7,8,9,10,11,16,7,6};
    vector<int> arr = {1,1};
    int n = arr.size();
    minMax(0,n-1,arr);
    cout<<mini<<" "<<maxi<<endl;
    return 0;
}
