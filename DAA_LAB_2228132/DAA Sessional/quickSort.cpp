#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
// int partition(vector<int>&arr,int lo,int hi){
//     int pivot = arr[hi];
//     int i = lo-1;

//     for(int j=lo;j<=hi-1;j++){
//         if(arr[j]<pivot){
//             i++;
//             swap(arr[j],arr[i]);
//         }
//     }
//     swap(arr[i+1],arr[hi]);
//     return i+1;
// }
int partition(vector<int>&arr,int lo,int hi){
    int pivot = arr[lo];
    int i = lo;

    for(int j=lo+1;j<=hi;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[j],arr[i]);
        }
    }
    swap(arr[i],arr[lo]);
    return i;
}
void quickSort(vector<int>&arr,int lo,int hi){
    if(lo<hi){
        int pi = partition(arr,lo,hi);

        quickSort(arr,lo,pi-1);
        quickSort(arr,pi+1,hi);
    }

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> arr = {10, 7, 8, 9, 1, 5,110,23,45};
    int n = arr.size();
    quickSort(arr,0,n-1);
    for(auto ele: arr)cout<<ele<<" ";
    return 0;
}
