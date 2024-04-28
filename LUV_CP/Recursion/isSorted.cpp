#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
bool isSorted(vector<int>& arr,int i){
    // base case
    if(i==arr.size()-1){
        return true;
    }
    if(arr[i]>arr[i+1]){
        return false;
    }
    return isSorted(arr,i+1);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(isSorted(arr,0)){
        cout<<"True"<<endl;
    }
    else
    cout<<"False\n";
}
