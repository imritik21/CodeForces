#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
int main(){
    int n,d;
    cin>>n>>d;
    d=d%n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // put d elements and put it to the back
    vector<int>temp(d);
    for(int i=0;i<d;i++){
        temp[i]=arr[i];
    }
    // shifting
    // if d=3 we start shifting from 3rd index
    for(int i=d;i<n;i++)
    {
        arr[i-d]=arr[i];
    }
    int j=0;
    // put back temp in last
    for(int i=n-d;i<n;i++){
        arr[i]=temp[j];
        j++;
    }
    // display
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
