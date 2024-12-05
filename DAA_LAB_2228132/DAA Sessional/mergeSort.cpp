#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int cnt=0;
void merge(int lo,int mid,int hi,vector<int>& arr){
    int l_sz = mid-lo+1;
    int L[l_sz+1];
    int r_sz = hi-mid;
    int R[r_sz+1];

    for(int i=0;i<l_sz;i++){
        L[i] = arr[lo+i];
    }
    for(int i=0;i<r_sz;i++){
        R[i] = arr[mid+1+i];
    }
    L[l_sz]=R[r_sz]=INT_MAX;
    int l_i=0,r_i=0;
    for(int i=lo;i<=hi;i++){
        if(L[l_i]<=R[r_i]){
            arr[i] = L[l_i];
            l_i++;
        }
        else{
            arr[i] = R[r_i];
            r_i++;
        }
    }
    cnt++;
}
void mergeSort(int lo,int hi,vector<int>& arr){
    if(lo==hi){
        return;
    }
    int mid = (lo+hi)/2;
    mergeSort(lo,mid,arr);
    mergeSort(mid+1,hi,arr);
    merge(lo,mid,hi,arr);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr = {2,3,1,4,5,2,3,9,7};
    int n = arr.size();

    mergeSort(0,n-1,arr);
    for(auto ele:arr)cout<<ele<<" ";
    cout<<endl;
    cout<<cnt<<" ";
    return 0;
}
